@bs.val
external stringify: ('a, Js.Null.t<'b>, int) => string = "JSON.stringify"

module AddMovieMutation = %relay.mutation(
  `
  mutation AddMoviePageMutation(
    $imdbId: String
    $overview: String
    $runtime: Int
    $poster: String
    $releaseDate: date
    $tagline: String
    $title: String
    $rating: Int
    $genres: [movie_genre_insert_input!]!
    $people: [movie_person_insert_input!]!
    $watchDates: [seen_insert_input!]!
  ) {
    insert_movie_one(
      object: {
        imdb_id: $imdbId
        overview: $overview
        runtime: $runtime
        poster: $poster
        release_date: $releaseDate
        tagline: $tagline
        title: $title
        ratings: { data: [{ rating: $rating }] }
        movie_genres: { data: $genres }
        movie_people: {
          data: $people
          on_conflict: {
            constraint: movie_person_movie_id_person_id_job_key
            update_columns: job
          }
        }
        dates_watched: { data: $watchDates }
      }
      on_conflict: { constraint: movie_imdb_id_key, update_columns: title }
    ) {
      title
    }
  }
`
)

module Genre = {
  open AddMoviePageMutation_graphql.Types

  let make = ({name}: Tmdb.Movie.Genre.t) => {
    id: None,
    movie_id: None,
    genre_id: None,
    genre: Some({
      data: {
        id: None,
        name: Some(name),
      },
      on_conflict: Some({
        constraint_: #genre_name_key,
        update_columns: [#name],
        where: None,
      }),
    }),
  }
}

module Person = {
  open AddMoviePageMutation_graphql.Types

  let make = (person: Tmdb.Movie.Credits.Crew.t) => {
    id: None,
    job: Job.parseTmdb(person.department, person.job),
    movie: None,
    movie_id: None,
    person: Some({
      data: {
        id: None,
        movie_people: None,
        name: Some(person.name),
        original_id: Some(person.id),
      },
      on_conflict: Some({
        constraint_: #person_original_id_key,
        update_columns: [#original_id],
        where: None,
      }),
    }),
    person_id: None,
  }
}

@react.component
let make = () => {
  let (mutate, _isMutating) = AddMovieMutation.use()
  let (movie, getMovie) = Tmdb.useMovie()
  let (rating, setRating) = React.useState(() => "")
  let (imdbId, setImdbId) = React.useState(() => "")

  let handleAddMovie = (movie: Tmdb.Movie.t) => {
    let castAsCrew = movie.credits.cast->Belt.Array.map(cast => {
      open Tmdb.Movie.Credits.Crew
      {
        name: cast.name,
        id: cast.id,
        job: "Cast",
        department: "Cast",
      }
    })

    let people = movie.credits.crew->Belt.Array.concat(castAsCrew)

    mutate(
      ~variables={
        imdbId: movie.imdb_id,
        overview: movie.overview,
        runtime: movie.runtime,
        poster: movie.poster_path,
        releaseDate: Some(movie.release_date),
        tagline: movie.tagline,
        title: Some(movie.title),
        rating: rating === "" ? None : Some(int_of_string(rating)),
        genres: movie.genres->Belt.Array.map(Genre.make),
        people: people
        ->Belt.Array.keep(({department, job}) => Job.isValid(department, job))
        ->Belt.Array.map(Person.make),
        watchDates: [
          {
            date: Some(Js.Date.make()->Js.Date.toISOString),
            id: None,
            movie: None,
            movie_id: None,
          },
        ],
      },
      ~onCompleted=(_, _) => Router.Route.go(Feed),
      (),
    ) |> ignore
  }

  <Layout.Base>
    <div className="flex flex-wrap md:space-x-8">
      <div className="w-full md:w-auto space-y-4">
        <Form.TextField
          label="IMDb ID"
          name="imdb-id"
          onChange={event => {
            let id = (event->ReactEvent.Form.target)["value"]
            let id = id->Js.String2.match_(%re("/tt\\d+/"))

            switch id {
            | Some([id]) =>
              getMovie(id)
              setImdbId(_ => id)
            | Some(_)
            | None => ()
            }
          }}
          value=imdbId
        />
        <Form.TextField
          label="Rating"
          name="rating"
          onChange={event => {
            let value = (event->ReactEvent.Form.target)["value"]

            setRating(_ => value)
          }}
          value=rating
        />
        {switch movie {
        | Error
        | NoData
        | NotCalled => React.null
        | Loading => React.string("Loading")
        | Data(movie) =>
          <Layout.Button onClick={_ => handleAddMovie(movie)}>
            {React.string("Add")}
          </Layout.Button>
        }}
      </div>
      {switch movie {
      | Error
      | NoData
      | NotCalled => React.null
      | Loading => React.string("Loading")
      | Data(movie) =>
        <div className="flex-1 p-5 mt-8 text-xs bg-gray-200 md:mt-0">
          <h1 className="mb-4 text-2xl font-bold"> {React.string(movie.title)} </h1>
          <div className="mb-4">
            {React.string(movie.overview->Belt.Option.getWithDefault(""))}
          </div>
          <div className="mb-4"> {React.string("Rating: " ++ rating)} </div>
          <h2 className="mb-2 text-lg font-bold"> {React.string("Cast")} </h2>
          <ul>
            {movie.credits.cast
            ->Belt.Array.map(person => <li> {React.string(person.name)} </li>)
            ->React.array}
          </ul>
          <h2 className="mt-4 mb-2 text-lg font-bold"> {React.string("Crew")} </h2>
          <ul>
            {movie.credits.crew
            ->Belt.Array.map(person =>
              <li> {React.string(person.name)} {React.string(" (" ++ (person.job ++ ")"))} </li>
            )
            ->React.array}
          </ul>
        </div>
      }}
    </div>
  </Layout.Base>
}

let default = make

module SearchQuery = %relay.query(`
  query SearchPageQuery($query: String!) {
    movies: movie_connection(
      where: { title: { _ilike: $query } }
      order_by: { release_date: desc }
    ) {
      edges {
        movie: node {
          id
          title
          year
          ...Poster_movie
        }
      }
    }
    cast: person_connection(
      first: 20
      where: { name: { _ilike: $query }, movie_people: { job: { _eq: "cast" } } }
      order_by: { movie_people_aggregate: { count: desc_nulls_last } }
    ) {
      edges {
        person: node {
          name
          movie_people(
            limit: 3
            order_by: { movie: { release_date: desc } }
            where: { job: { _eq: "cast" } }
          ) {
            movie {
              title
            }
            id
          }
          movie_people_aggregate(where: { job: { _eq: "cast" } }) {
            aggregate {
              count
            }
          }
          id
        }
      }
    }
  }
`)

@react.component
let make = (~query) => {
  let data = SearchQuery.use(~variables={query: "%" ++ Js.Global.decodeURI(query) ++ "%"}, ())

  <>
    <div className="my-8 grid grid-md">
      <div className="col-start-3 col-end-3"> <SectionHeader title="Movies" /> </div>
      {switch Belt.Array.length(data.movies.edges) {
      | 0 =>
        <div className="col-start-3 col-end-3">
          {React.string("I couldn't find any movies that match: ")}
          <span className="font-bold"> {query->Js.Global.decodeURI->React.string} </span>
        </div>
      | _ =>
        <div className="grid grid-cols-1 md:grid-cols-2 lg:grid-cols-4 gap-5 col-start-3 col-end-3">
          {data.movies.edges
          ->Belt.Array.map(({movie}) => {
            <Router.Link key={movie.id} to_={Movie(movie.id)}>
              <Poster movie=movie.fragmentRefs />
              <div className="mt-4">
                <div className="text-xs font-bold text-gray-900"> {React.string(movie.title)} </div>
                <div className="flex text-xs text-gray-600 space-x-1">
                  {switch movie.year {
                  | Some(year) => <div> {React.string(year)} </div>
                  | None => React.null
                  }}
                </div>
              </div>
            </Router.Link>
          })
          ->React.array}
        </div>
      }}
    </div>
    <div className="my-8 grid grid-md">
      <div className="col-start-3 col-end-3"> <SectionHeader title="Cast" /> </div>
      {switch Belt.Array.length(data.cast.edges) {
      | 0 =>
        <div className="col-start-3 col-end-3">
          {React.string("I couldn't find any cast that match: ")}
          <span className="font-bold"> {query->Js.Global.decodeURI->React.string} </span>
        </div>
      | _ =>
        <div className="grid grid-cols-1 md:grid-cols-2 lg:grid-cols-4 gap-5 col-start-3 col-end-3">
          {data.cast.edges
          ->Belt.Array.map(({person}) => {
            <Link key={person.id} to_={Person(person.id)}> {React.string(person.name)} </Link>
          })
          ->React.array}
        </div>
      }}
    </div>
  </>
}

let default = make

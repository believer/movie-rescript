module GenresFragment = %relay(`
  fragment Genres_movie on movie
    @argumentDefinitions(
      genreLimit: {type: "Int", defaultValue: 3},
    ) {
    genres: movie_genres(limit: $genreLimit) {
      genre {
        id
        name
      }
    }
  }
`)

@react.component
let make = (~movie) => {
  let data = GenresFragment.use(movie)

  <div>
    {data.genres->Belt.Array.map(({genre}) => genre.name)->Js.Array2.joinWith(" | ")->React.string}
  </div>
}

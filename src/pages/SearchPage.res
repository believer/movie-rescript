module SearchQuery = %relay.query(
  `
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
  }
`
)

@react.component
let make = (~query) => {
  let data = SearchQuery.use(~variables={query: "%" ++ Js.Global.decodeURI(query) ++ "%"}, ())

  switch Belt.Array.length(data.movies.edges) {
  | 0 =>
    <div className="my-8 grid grid-md">
      <div className="col-start-3 col-end-3">
        {React.string("I couldn't find any movies that match: ")}
        <span className="font-bold"> {React.string(query)} </span>
      </div>
    </div>
  | _ =>
    <div className="my-8 grid grid-md">
      <div className="grid grid-cols-1 md:grid-cols-2 lg:grid-cols-4 gap-5 col-start-3 col-end-3">
        {data.movies.edges->Belt.Array.map(({movie}) => {
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
        })->React.array}
      </div>
    </div>
  }
}

let default = make

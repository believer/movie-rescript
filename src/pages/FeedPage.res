module FeedQuery = %relay(`
  query FeedPageQuery(
    $genreLimit: Int!
    $dateGte: timestamp!
    $dateLte: timestamp!
  ) {
    ...FeedPage_query
  }
`)

module FeedFragment = %relay(`
  fragment FeedPage_query on query_root
  @refetchable(queryName: "FeedPageRefetchQuery")
  @argumentDefinitions(
    first: { type: "Int!", defaultValue: 16 }
    after: { type: "String" }
  ) {
    feed: seen_connection(
      first: $first
      after: $after
      order_by: { date: desc }
      where: {
        date: { _gte: $dateGte, _lte: $dateLte }
      }
    ) @connection(key: "FeedPage_query_feed") {
      edges {
        node {
          movie {
          id
          year
          title
          ...Genres_movie @arguments(genreLimit: $genreLimit)
          ...Poster_movie
          ...Ratings_movie
          }
        }
      }
    }
  }
`)

@react.component
let make = () => {
  let (year, setYear) = React.useState(() => Js.Date.make()->Js.Date.getFullYear)
  let queryData = FeedQuery.use(
    ~variables={
      genreLimit: 3,
      dateGte: Intl.DateTime.make(
        ~date=Js.Date.makeWithYMD(~year, ~month=0., ~date=1., ()),
        ~locale=Some("sv-SE"),
        (),
      ),
      dateLte: Intl.DateTime.make(
        ~date=Js.Date.makeWithYMD(~year, ~month=11., ~date=31., ()),
        ~locale=Some("sv-SE"),
        (),
      ),
    },
    (),
  )

  let {data, loadNext, hasNext, isLoadingNext} = FeedFragment.usePagination(queryData.fragmentRefs)

  let handleSelectYear = year => setYear(_ => float_of_string(year))

  <div className="my-8 grid grid-md">
    <div className="col-start-3 col-end-3"> <SelectYear onChange=handleSelectYear /> </div>
    {switch Belt.Array.length(data.feed.edges) {
    | 0 =>
      <div className="col-start-3 col-end-3">
        {React.string("I haven't watched any movies this year!")}
      </div>
    | _ =>
      <div className="grid grid-cols-1 md:grid-cols-2 lg:grid-cols-4 gap-5 col-start-3 col-end-3">
        {data.feed.edges
        ->Belt.Array.map(({node: {movie}}) =>
          <Router.Link className="grid grid-feed-movie gap-5" key=movie.id to_=Movie(movie.id)>
            <Poster movie=movie.fragmentRefs size=Poster.Feed />
            <div>
              <div className="mr-4">
                <div className="text-xs font-bold text-gray-900"> {React.string(movie.title)} </div>
                <div className="flex text-xs text-gray-600 space-x-1">
                  {switch movie.year {
                  | Some(year) => <div> {React.string(year)} </div>
                  | None => React.null
                  }}
                  <div> {React.string(j`\\u2022`)} </div>
                  <Genres movie=movie.fragmentRefs />
                </div>
              </div>
              <Rating movie=movie.fragmentRefs />
            </div>
          </Router.Link>
        )
        ->React.array}
      </div>
    }}
    {hasNext
      ? <div className="ml-auto mr-auto col-start-3 col-end-3">
          <Layout.Button disabled=isLoadingNext onClick={_ => loadNext(~count=16, ()) |> ignore}>
            {(isLoadingNext ? "Loading..." : "More") |> React.string}
          </Layout.Button>
        </div>
      : React.null}
  </div>
}

let default = make

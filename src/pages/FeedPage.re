module FeedQuery = [%relay.query
  {|
  query FeedPageQuery {
    ...FeedPage_query
  }
|}
];

module FeedFragment = [%relay.fragment
  {|
  fragment FeedPage_query on query_root
    @refetchable(queryName: "FeedPageRefetchQuery")
    @argumentDefinitions(
      first: {type: "Int!", defaultValue: 12},
      after: {type: "String"}
    ) {
    feed: movie_connection(
      first: $first,
      after: $after,
      order_by: {created_at: desc}
    ) @connection(key: "FeedPage_query_feed") {
      edges {
        node {
          id
          year
          title
          ...Genres_movie
          ...Poster_movie
          ...Ratings_movie
        }
      }
    }
  }
|}
];

[@react.component]
let make = () => {
  let queryData = FeedQuery.use(~variables=(), ());
  let ReasonRelay.{data, loadNext, hasNext, isLoadingNext} =
    FeedFragment.usePagination(queryData.fragmentRefs);

  <div className="my-8 grid grid-md">
    <div className="grid grid-4-col grid-gap-4">
      {data.feed.edges
       ->Belt.Array.map(({node}) => {
           <Router.Link key={node.id} to_={Movie(node.id)}>
             <Poster movie={node.fragmentRefs} />
             <div className="mt-4">
               <div className="mr-4">
                 <div className="text-xs font-bold text-gray-900">
                   {React.string(node.title)}
                 </div>
                 <div className="flex text-xs text-gray-600 space-x-1">
                   {switch (node.year) {
                    | Some(year) => <div> {React.string(year)} </div>
                    | None => React.null
                    }}
                   <div> {React.string({j|\u2022|j})} </div>
                   <Genres movie={node.fragmentRefs} />
                 </div>
               </div>
               <Rating movie={node.fragmentRefs} />
             </div>
           </Router.Link>
         })
       ->React.array}
    </div>
    {hasNext
       ? <div className="ml-auto mr-auto">
           <Layout.Button
             disabled=isLoadingNext
             onClick={_ => loadNext(~count=16, ()) |> ignore}>
             {(isLoadingNext ? "Loading..." : "More") |> React.string}
           </Layout.Button>
         </div>
       : React.null}
  </div>;
};

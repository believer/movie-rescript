/* @generated */
%%raw("/* @generated */")
module Types = {
  @@ocaml.warning("-30")
  
  type rec fragment_feed = {
    edges: array<fragment_feed_edges>,
  }
   and fragment_feed_edges = {
    node: fragment_feed_edges_node,
  }
   and fragment_feed_edges_node = {
    movie: fragment_feed_edges_node_movie,
  }
   and fragment_feed_edges_node_movie = {
    id: string,
    year: option<string>,
    title: string,
    fragmentRefs: RescriptRelay.fragmentRefs<[ | #Genres_movie | #Poster_movie | #Ratings_movie]>
  }
  
  
  type fragment = {
    feed: fragment_feed,
  }
}

module Internal = {
  type fragmentRaw
  let fragmentConverter: 
    Js.Dict.t<Js.Dict.t<Js.Dict.t<string>>> = 
    %raw(
      json`{"__root":{"feed_edges_node_movie_year":{"n":""},"feed_edges_node_movie":{"f":""}}}`
    )
  
  let fragmentConverterMap = ()
  let convertFragment = v => v->RescriptRelay.convertObj(
    fragmentConverter, 
    fragmentConverterMap, 
    Js.undefined
  )
}
type t
type fragmentRef
external getFragmentRef:
  RescriptRelay.fragmentRefs<[> | #FeedPage_query]> => fragmentRef = "%identity"


module Utils = {
  @@ocaml.warning("-33")
  open Types
  @inline
  let connectionKey = "FeedPage_query_feed"
  
}
type relayOperationNode
type operationType = RescriptRelay.fragmentNode<relayOperationNode>


%%private(let makeNode = (node_FeedPageRefetchQuery): operationType => {
  ignore(node_FeedPageRefetchQuery)
  %raw(json` (function(){
var v0 = [
  "feed"
];
return {
  "argumentDefinitions": [
    {
      "defaultValue": null,
      "kind": "LocalArgument",
      "name": "after"
    },
    {
      "kind": "RootArgument",
      "name": "dateGte"
    },
    {
      "kind": "RootArgument",
      "name": "dateLte"
    },
    {
      "defaultValue": 16,
      "kind": "LocalArgument",
      "name": "first"
    },
    {
      "kind": "RootArgument",
      "name": "genreLimit"
    }
  ],
  "kind": "Fragment",
  "metadata": {
    "connection": [
      {
        "count": "first",
        "cursor": "after",
        "direction": "forward",
        "path": (v0/*: any*/)
      }
    ],
    "refetch": {
      "connection": {
        "forward": {
          "count": "first",
          "cursor": "after"
        },
        "backward": null,
        "path": (v0/*: any*/)
      },
      "fragmentPathInResult": [],
      "operation": node_FeedPageRefetchQuery
    }
  },
  "name": "FeedPage_query",
  "selections": [
    {
      "alias": "feed",
      "args": [
        {
          "kind": "Literal",
          "name": "order_by",
          "value": {
            "date": "desc"
          }
        },
        {
          "fields": [
            {
              "fields": [
                {
                  "kind": "Variable",
                  "name": "_gte",
                  "variableName": "dateGte"
                },
                {
                  "kind": "Variable",
                  "name": "_lte",
                  "variableName": "dateLte"
                }
              ],
              "kind": "ObjectValue",
              "name": "date"
            }
          ],
          "kind": "ObjectValue",
          "name": "where"
        }
      ],
      "concreteType": "seenConnection",
      "kind": "LinkedField",
      "name": "__FeedPage_query_feed_connection",
      "plural": false,
      "selections": [
        {
          "alias": null,
          "args": null,
          "concreteType": "seenEdge",
          "kind": "LinkedField",
          "name": "edges",
          "plural": true,
          "selections": [
            {
              "alias": null,
              "args": null,
              "concreteType": "seen",
              "kind": "LinkedField",
              "name": "node",
              "plural": false,
              "selections": [
                {
                  "alias": null,
                  "args": null,
                  "concreteType": "movie",
                  "kind": "LinkedField",
                  "name": "movie",
                  "plural": false,
                  "selections": [
                    {
                      "alias": null,
                      "args": null,
                      "kind": "ScalarField",
                      "name": "id",
                      "storageKey": null
                    },
                    {
                      "alias": null,
                      "args": null,
                      "kind": "ScalarField",
                      "name": "year",
                      "storageKey": null
                    },
                    {
                      "alias": null,
                      "args": null,
                      "kind": "ScalarField",
                      "name": "title",
                      "storageKey": null
                    },
                    {
                      "args": [
                        {
                          "kind": "Variable",
                          "name": "genreLimit",
                          "variableName": "genreLimit"
                        }
                      ],
                      "kind": "FragmentSpread",
                      "name": "Genres_movie"
                    },
                    {
                      "args": null,
                      "kind": "FragmentSpread",
                      "name": "Poster_movie"
                    },
                    {
                      "args": null,
                      "kind": "FragmentSpread",
                      "name": "Ratings_movie"
                    }
                  ],
                  "storageKey": null
                },
                {
                  "alias": null,
                  "args": null,
                  "kind": "ScalarField",
                  "name": "__typename",
                  "storageKey": null
                }
              ],
              "storageKey": null
            },
            {
              "alias": null,
              "args": null,
              "kind": "ScalarField",
              "name": "cursor",
              "storageKey": null
            }
          ],
          "storageKey": null
        },
        {
          "alias": null,
          "args": null,
          "concreteType": "PageInfo",
          "kind": "LinkedField",
          "name": "pageInfo",
          "plural": false,
          "selections": [
            {
              "alias": null,
              "args": null,
              "kind": "ScalarField",
              "name": "endCursor",
              "storageKey": null
            },
            {
              "alias": null,
              "args": null,
              "kind": "ScalarField",
              "name": "hasNextPage",
              "storageKey": null
            }
          ],
          "storageKey": null
        }
      ],
      "storageKey": null
    }
  ],
  "type": "query_root",
  "abstractKey": null
};
})() `)
})
let node: operationType = makeNode(FeedPageRefetchQuery_graphql.node)



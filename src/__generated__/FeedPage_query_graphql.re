/* @generated */

module Types = {
  [@ocaml.warning "-30"];
  type fragment_feed = {edges: array(fragment_feed_edges)}
  and fragment_feed_edges = {node: fragment_feed_edges_node}
  and fragment_feed_edges_node = {
    id: string,
    year: option(string),
    title: string,
    fragmentRefs:
      ReasonRelay.fragmentRefs(
        [ | `Genres_movie | `Poster_movie | `Ratings_movie],
      ),
  };

  type fragment = {feed: fragment_feed};
};

module Internal = {
  type fragmentRaw;
  let fragmentConverter: Js.Dict.t(Js.Dict.t(Js.Dict.t(string))) = [%raw
    {json| {"__root":{"feed_edges_node_year":{"n":""},"feed_edges_node":{"f":""}}} |json}
  ];
  let fragmentConverterMap = ();
  let convertFragment = v =>
    v
    ->ReasonRelay._convertObj(
        fragmentConverter,
        fragmentConverterMap,
        Js.undefined,
      );
};

type t;
type fragmentRef;
external getFragmentRef:
  ReasonRelay.fragmentRefs([> | `FeedPage_query]) => fragmentRef =
  "%identity";

module Utils = {
  open Types;
};

type operationType = ReasonRelay.fragmentNode;

let node: operationType = [%raw
  {json| (function(){
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
      "operation": require('./FeedPageRefetchQuery_graphql.bs.js').node
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
            "dates_watched_aggregate": {
              "max": {
                "date": "desc_nulls_last"
              }
            }
          }
        },
        {
          "fields": [
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
              "name": "dates_watched"
            }
          ],
          "kind": "ObjectValue",
          "name": "where"
        }
      ],
      "concreteType": "movieConnection",
      "kind": "LinkedField",
      "name": "__FeedPage_query_feed_connection",
      "plural": false,
      "selections": [
        {
          "alias": null,
          "args": null,
          "concreteType": "movieEdge",
          "kind": "LinkedField",
          "name": "edges",
          "plural": true,
          "selections": [
            {
              "alias": null,
              "args": null,
              "concreteType": "movie",
              "kind": "LinkedField",
              "name": "node",
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
                  "alias": null,
                  "args": null,
                  "kind": "ScalarField",
                  "name": "__typename",
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
})() |json}
];

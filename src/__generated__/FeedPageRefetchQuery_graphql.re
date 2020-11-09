/* @generated */

module Types = {
  [@ocaml.warning "-30"];

  type response = {
    fragmentRefs: ReasonRelay.fragmentRefs([ | `FeedPage_query]),
  };
  type rawResponse = response;
  type refetchVariables = {
    after: option(string),
    dateGte: option(string),
    dateLte: option(string),
    first: option(int),
    genreLimit: option(int),
  };
  let makeRefetchVariables =
      (~after=?, ~dateGte=?, ~dateLte=?, ~first=?, ~genreLimit=?, ())
      : refetchVariables => {
    after,
    dateGte,
    dateLte,
    first,
    genreLimit,
  };
  type variables = {
    after: option(string),
    dateGte: option(string),
    dateLte: option(string),
    first: int,
    genreLimit: option(int),
  };
};

module Internal = {
  type responseRaw;
  let responseConverter: Js.Dict.t(Js.Dict.t(Js.Dict.t(string))) = [%raw
    {json| {"__root":{"":{"f":""}}} |json}
  ];
  let responseConverterMap = ();
  let convertResponse = v =>
    v
    ->ReasonRelay._convertObj(
        responseConverter,
        responseConverterMap,
        Js.undefined,
      );

  type rawResponseRaw = responseRaw;
  let convertRawResponse = convertResponse;

  let variablesConverter: Js.Dict.t(Js.Dict.t(Js.Dict.t(string))) = [%raw
    {json| {"__root":{"after":{"n":""},"dateGte":{"n":""},"dateLte":{"n":""},"genreLimit":{"n":""}}} |json}
  ];
  let variablesConverterMap = ();
  let convertVariables = v =>
    v
    ->ReasonRelay._convertObj(
        variablesConverter,
        variablesConverterMap,
        Js.undefined,
      );
};

type queryRef;

module Utils = {
  open Types;
  let makeVariables =
      (~after=?, ~dateGte=?, ~dateLte=?, ~first, ~genreLimit=?, ()): variables => {
    after,
    dateGte,
    dateLte,
    first,
    genreLimit,
  };
};

type operationType = ReasonRelay.queryNode;

let node: operationType = [%raw
  {json| (function(){
var v0 = [
  {
    "defaultValue": null,
    "kind": "LocalArgument",
    "name": "after"
  },
  {
    "defaultValue": null,
    "kind": "LocalArgument",
    "name": "dateGte"
  },
  {
    "defaultValue": null,
    "kind": "LocalArgument",
    "name": "dateLte"
  },
  {
    "defaultValue": 12,
    "kind": "LocalArgument",
    "name": "first"
  },
  {
    "defaultValue": null,
    "kind": "LocalArgument",
    "name": "genreLimit"
  }
],
v1 = {
  "kind": "Variable",
  "name": "after",
  "variableName": "after"
},
v2 = {
  "kind": "Variable",
  "name": "first",
  "variableName": "first"
},
v3 = [
  (v1/*: any*/),
  (v2/*: any*/),
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
v4 = {
  "alias": null,
  "args": null,
  "kind": "ScalarField",
  "name": "id",
  "storageKey": null
};
return {
  "fragment": {
    "argumentDefinitions": (v0/*: any*/),
    "kind": "Fragment",
    "metadata": null,
    "name": "FeedPageRefetchQuery",
    "selections": [
      {
        "args": [
          (v1/*: any*/),
          (v2/*: any*/)
        ],
        "kind": "FragmentSpread",
        "name": "FeedPage_query"
      }
    ],
    "type": "query_root",
    "abstractKey": null
  },
  "kind": "Request",
  "operation": {
    "argumentDefinitions": (v0/*: any*/),
    "kind": "Operation",
    "name": "FeedPageRefetchQuery",
    "selections": [
      {
        "alias": "feed",
        "args": (v3/*: any*/),
        "concreteType": "movieConnection",
        "kind": "LinkedField",
        "name": "movie_connection",
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
                  (v4/*: any*/),
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
                    "alias": "genres",
                    "args": [
                      {
                        "kind": "Variable",
                        "name": "limit",
                        "variableName": "genreLimit"
                      }
                    ],
                    "concreteType": "movie_genre",
                    "kind": "LinkedField",
                    "name": "movie_genres",
                    "plural": true,
                    "selections": [
                      {
                        "alias": null,
                        "args": null,
                        "concreteType": "genre",
                        "kind": "LinkedField",
                        "name": "genre",
                        "plural": false,
                        "selections": [
                          (v4/*: any*/),
                          {
                            "alias": null,
                            "args": null,
                            "kind": "ScalarField",
                            "name": "name",
                            "storageKey": null
                          }
                        ],
                        "storageKey": null
                      },
                      (v4/*: any*/)
                    ],
                    "storageKey": null
                  },
                  {
                    "alias": null,
                    "args": null,
                    "kind": "ScalarField",
                    "name": "poster",
                    "storageKey": null
                  },
                  {
                    "alias": null,
                    "args": null,
                    "concreteType": "rating",
                    "kind": "LinkedField",
                    "name": "ratings",
                    "plural": true,
                    "selections": [
                      (v4/*: any*/),
                      {
                        "alias": null,
                        "args": null,
                        "kind": "ScalarField",
                        "name": "rating",
                        "storageKey": null
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
      },
      {
        "alias": "feed",
        "args": (v3/*: any*/),
        "filters": [
          "order_by",
          "where"
        ],
        "handle": "connection",
        "key": "FeedPage_query_feed",
        "kind": "LinkedHandle",
        "name": "movie_connection"
      }
    ]
  },
  "params": {
    "cacheID": "c195eb177e540da47add311f1c808091",
    "id": null,
    "metadata": {},
    "name": "FeedPageRefetchQuery",
    "operationKind": "query",
    "text": "query FeedPageRefetchQuery(\n  $after: String\n  $dateGte: timestamp\n  $dateLte: timestamp\n  $first: Int! = 12\n  $genreLimit: Int\n) {\n  ...FeedPage_query_2HEEH6\n}\n\nfragment FeedPage_query_2HEEH6 on query_root {\n  feed: movie_connection(first: $first, after: $after, order_by: {dates_watched_aggregate: {max: {date: desc_nulls_last}}}, where: {dates_watched: {date: {_gte: $dateGte, _lte: $dateLte}}}) {\n    edges {\n      node {\n        id\n        year\n        title\n        ...Genres_movie_36mvd1\n        ...Poster_movie\n        ...Ratings_movie\n        __typename\n      }\n      cursor\n    }\n    pageInfo {\n      endCursor\n      hasNextPage\n    }\n  }\n}\n\nfragment Genres_movie_36mvd1 on movie {\n  genres: movie_genres(limit: $genreLimit) {\n    genre {\n      id\n      name\n    }\n    id\n  }\n}\n\nfragment Poster_movie on movie {\n  poster\n}\n\nfragment Ratings_movie on movie {\n  ratings {\n    id\n    rating\n  }\n}\n"
  }
};
})() |json}
];

include ReasonRelay.MakeLoadQuery({
  type variables = Types.variables;
  type loadedQueryRef = queryRef;
  type response = Types.response;
  let query = node;
  let convertVariables = Internal.convertVariables;
});

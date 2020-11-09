/* @generated */

module Types = {
  [@ocaml.warning "-30"];

  type response = {
    fragmentRefs: ReasonRelay.fragmentRefs([ | `FeedPage_query]),
  };
  type rawResponse = response;
  type refetchVariables = {
    genreLimit: option(int),
    dateGte: option(string),
    dateLte: option(string),
  };
  let makeRefetchVariables =
      (~genreLimit=?, ~dateGte=?, ~dateLte=?, ()): refetchVariables => {
    genreLimit,
    dateGte,
    dateLte,
  };
  type variables = {
    genreLimit: int,
    dateGte: string,
    dateLte: string,
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
    {json| {} |json}
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
  let makeVariables = (~genreLimit, ~dateGte, ~dateLte): variables => {
    genreLimit,
    dateGte,
    dateLte,
  };
};

type operationType = ReasonRelay.queryNode;

let node: operationType = [%raw
  {json| (function(){
var v0 = {
  "defaultValue": null,
  "kind": "LocalArgument",
  "name": "dateGte"
},
v1 = {
  "defaultValue": null,
  "kind": "LocalArgument",
  "name": "dateLte"
},
v2 = {
  "defaultValue": null,
  "kind": "LocalArgument",
  "name": "genreLimit"
},
v3 = [
  {
    "kind": "Literal",
    "name": "first",
    "value": 12
  },
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
    "argumentDefinitions": [
      (v0/*: any*/),
      (v1/*: any*/),
      (v2/*: any*/)
    ],
    "kind": "Fragment",
    "metadata": null,
    "name": "FeedPageQuery",
    "selections": [
      {
        "args": null,
        "kind": "FragmentSpread",
        "name": "FeedPage_query"
      }
    ],
    "type": "query_root",
    "abstractKey": null
  },
  "kind": "Request",
  "operation": {
    "argumentDefinitions": [
      (v2/*: any*/),
      (v0/*: any*/),
      (v1/*: any*/)
    ],
    "kind": "Operation",
    "name": "FeedPageQuery",
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
    "cacheID": "3bd7f553bf5ab95bc4048a0041aae0aa",
    "id": null,
    "metadata": {},
    "name": "FeedPageQuery",
    "operationKind": "query",
    "text": "query FeedPageQuery(\n  $genreLimit: Int!\n  $dateGte: timestamp!\n  $dateLte: timestamp!\n) {\n  ...FeedPage_query\n}\n\nfragment FeedPage_query on query_root {\n  feed: movie_connection(first: 12, order_by: {dates_watched_aggregate: {max: {date: desc_nulls_last}}}, where: {dates_watched: {date: {_gte: $dateGte, _lte: $dateLte}}}) {\n    edges {\n      node {\n        id\n        year\n        title\n        ...Genres_movie_36mvd1\n        ...Poster_movie\n        ...Ratings_movie\n        __typename\n      }\n      cursor\n    }\n    pageInfo {\n      endCursor\n      hasNextPage\n    }\n  }\n}\n\nfragment Genres_movie_36mvd1 on movie {\n  genres: movie_genres(limit: $genreLimit) {\n    genre {\n      id\n      name\n    }\n    id\n  }\n}\n\nfragment Poster_movie on movie {\n  poster\n}\n\nfragment Ratings_movie on movie {\n  ratings {\n    id\n    rating\n  }\n}\n"
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

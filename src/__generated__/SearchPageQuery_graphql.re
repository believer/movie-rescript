/* @generated */

module Types = {
  [@ocaml.warning "-30"];
  type response_movies = {edges: array(response_movies_edges)}
  and response_movies_edges = {movie: response_movies_edges_movie}
  and response_movies_edges_movie = {
    id: string,
    title: string,
    year: option(string),
    fragmentRefs: ReasonRelay.fragmentRefs([ | `Poster_movie]),
  };

  type response = {movies: response_movies};
  type rawResponse = response;
  type refetchVariables = {query: option(string)};
  let makeRefetchVariables = (~query=?, ()): refetchVariables => {
    query: query,
  };
  type variables = {query: string};
};

module Internal = {
  type wrapResponseRaw;
  let wrapResponseConverter: Js.Dict.t(Js.Dict.t(Js.Dict.t(string))) = [%raw
    {json| {"__root":{"movies_edges_movie_year":{"n":""},"movies_edges_movie":{"f":""}}} |json}
  ];
  let wrapResponseConverterMap = ();
  let convertWrapResponse = v =>
    v
    ->ReasonRelay.convertObj(
        wrapResponseConverter,
        wrapResponseConverterMap,
        Js.null,
      );

  type responseRaw;
  let responseConverter: Js.Dict.t(Js.Dict.t(Js.Dict.t(string))) = [%raw
    {json| {"__root":{"movies_edges_movie_year":{"n":""},"movies_edges_movie":{"f":""}}} |json}
  ];
  let responseConverterMap = ();
  let convertResponse = v =>
    v
    ->ReasonRelay.convertObj(
        responseConverter,
        responseConverterMap,
        Js.undefined,
      );

  type wrapRawResponseRaw = wrapResponseRaw;
  let convertWrapRawResponse = convertWrapResponse;

  type rawResponseRaw = responseRaw;
  let convertRawResponse = convertResponse;

  let variablesConverter: Js.Dict.t(Js.Dict.t(Js.Dict.t(string))) = [%raw
    {json| {} |json}
  ];
  let variablesConverterMap = ();
  let convertVariables = v =>
    v
    ->ReasonRelay.convertObj(
        variablesConverter,
        variablesConverterMap,
        Js.undefined,
      );
};

type queryRef;

module Utils = {
  open Types;
  let makeVariables = (~query): variables => {query: query};
};

type relayOperationNode;

type operationType = ReasonRelay.queryNode(relayOperationNode);

let node: operationType = [%raw
  {json| (function(){
var v0 = [
  {
    "defaultValue": null,
    "kind": "LocalArgument",
    "name": "query"
  }
],
v1 = [
  {
    "kind": "Literal",
    "name": "order_by",
    "value": {
      "release_date": "desc"
    }
  },
  {
    "fields": [
      {
        "fields": [
          {
            "kind": "Variable",
            "name": "_ilike",
            "variableName": "query"
          }
        ],
        "kind": "ObjectValue",
        "name": "title"
      }
    ],
    "kind": "ObjectValue",
    "name": "where"
  }
],
v2 = {
  "alias": null,
  "args": null,
  "kind": "ScalarField",
  "name": "id",
  "storageKey": null
},
v3 = {
  "alias": null,
  "args": null,
  "kind": "ScalarField",
  "name": "title",
  "storageKey": null
},
v4 = {
  "alias": null,
  "args": null,
  "kind": "ScalarField",
  "name": "year",
  "storageKey": null
};
return {
  "fragment": {
    "argumentDefinitions": (v0/*: any*/),
    "kind": "Fragment",
    "metadata": null,
    "name": "SearchPageQuery",
    "selections": [
      {
        "alias": "movies",
        "args": (v1/*: any*/),
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
                "alias": "movie",
                "args": null,
                "concreteType": "movie",
                "kind": "LinkedField",
                "name": "node",
                "plural": false,
                "selections": [
                  (v2/*: any*/),
                  (v3/*: any*/),
                  (v4/*: any*/),
                  {
                    "args": null,
                    "kind": "FragmentSpread",
                    "name": "Poster_movie"
                  }
                ],
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
  },
  "kind": "Request",
  "operation": {
    "argumentDefinitions": (v0/*: any*/),
    "kind": "Operation",
    "name": "SearchPageQuery",
    "selections": [
      {
        "alias": "movies",
        "args": (v1/*: any*/),
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
                "alias": "movie",
                "args": null,
                "concreteType": "movie",
                "kind": "LinkedField",
                "name": "node",
                "plural": false,
                "selections": [
                  (v2/*: any*/),
                  (v3/*: any*/),
                  (v4/*: any*/),
                  {
                    "alias": null,
                    "args": null,
                    "kind": "ScalarField",
                    "name": "poster",
                    "storageKey": null
                  }
                ],
                "storageKey": null
              }
            ],
            "storageKey": null
          }
        ],
        "storageKey": null
      }
    ]
  },
  "params": {
    "cacheID": "6402e1510fd9774811f331dc9a07ad28",
    "id": null,
    "metadata": {},
    "name": "SearchPageQuery",
    "operationKind": "query",
    "text": "query SearchPageQuery(\n  $query: String!\n) {\n  movies: movie_connection(where: {title: {_ilike: $query}}, order_by: {release_date: desc}) {\n    edges {\n      movie: node {\n        id\n        title\n        year\n        ...Poster_movie\n      }\n    }\n  }\n}\n\nfragment Poster_movie on movie {\n  poster\n}\n"
  }
};
})() |json}
];

include ReasonRelay.MakeLoadQuery({
  type variables = Types.variables;
  type loadedQueryRef = queryRef;
  type response = Types.response;
  type node = relayOperationNode;
  let query = node;
  let convertVariables = Internal.convertVariables;
});

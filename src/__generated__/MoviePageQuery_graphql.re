/* @generated */

module Types = {
  [@ocaml.warning "-30"];
  type response_movie_movie = {
    title: string,
    tagline: option(string),
    runtime: int,
    release_date: option(string),
    overview: option(string),
    id: string,
    fragmentRefs:
      ReasonRelay.fragmentRefs(
        [
          | `Cast_movie
          | `Composer_movie
          | `Director_movie
          | `Producer_movie
          | `Poster_movie
          | `Ratings_movie
        ],
      ),
  };
  type response_movie = [
    | `movie(response_movie_movie)
    | `UnselectedUnionMember(string)
  ];

  type response = {
    movie:
      option(
        [ | `movie(response_movie_movie) | `UnselectedUnionMember(string)],
      ),
  };
  type rawResponse = response;
  type refetchVariables = {id: option(string)};
  let makeRefetchVariables = (~id=?, ()): refetchVariables => {id: id};
  type variables = {id: string};
};

let unwrap_response_movie:
  {. "__typename": string} =>
  [ | `movie(Types.response_movie_movie) | `UnselectedUnionMember(string)] =
  u =>
    switch (u##__typename) {
    | "movie" => `movie(u->Obj.magic)
    | v => `UnselectedUnionMember(v)
    };

let wrap_response_movie:
  [ | `movie(Types.response_movie_movie) | `UnselectedUnionMember(string)] =>
  {. "__typename": string} =
  fun
  | `movie(v) => v->Obj.magic
  | `UnselectedUnionMember(v) => {"__typename": v};

module Internal = {
  type responseRaw;
  let responseConverter: Js.Dict.t(Js.Dict.t(Js.Dict.t(string))) = [%raw
    {json| {"__root":{"movie":{"n":"","u":"response_movie"},"movie_movie_tagline":{"n":""},"movie_movie_release_date":{"n":""},"movie_movie_overview":{"n":""},"movie_movie":{"f":""}}} |json}
  ];
  let responseConverterMap = {"response_movie": unwrap_response_movie};
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
  let makeVariables = (~id): variables => {id: id};
};

type operationType = ReasonRelay.queryNode;

let node: operationType = [%raw
  {json| (function(){
var v0 = [
  {
    "defaultValue": null,
    "kind": "LocalArgument",
    "name": "id"
  }
],
v1 = [
  {
    "kind": "Variable",
    "name": "id",
    "variableName": "id"
  }
],
v2 = {
  "alias": null,
  "args": null,
  "kind": "ScalarField",
  "name": "__typename",
  "storageKey": null
},
v3 = {
  "alias": null,
  "args": null,
  "kind": "ScalarField",
  "name": "id",
  "storageKey": null
},
v4 = {
  "alias": null,
  "args": null,
  "kind": "ScalarField",
  "name": "overview",
  "storageKey": null
},
v5 = {
  "alias": null,
  "args": null,
  "kind": "ScalarField",
  "name": "release_date",
  "storageKey": null
},
v6 = {
  "alias": null,
  "args": null,
  "kind": "ScalarField",
  "name": "runtime",
  "storageKey": null
},
v7 = {
  "alias": null,
  "args": null,
  "kind": "ScalarField",
  "name": "tagline",
  "storageKey": null
},
v8 = {
  "alias": null,
  "args": null,
  "kind": "ScalarField",
  "name": "title",
  "storageKey": null
},
v9 = [
  {
    "alias": null,
    "args": null,
    "concreteType": "person",
    "kind": "LinkedField",
    "name": "person",
    "plural": false,
    "selections": [
      (v3/*: any*/),
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
  (v3/*: any*/)
];
return {
  "fragment": {
    "argumentDefinitions": (v0/*: any*/),
    "kind": "Fragment",
    "metadata": null,
    "name": "MoviePageQuery",
    "selections": [
      {
        "alias": "movie",
        "args": (v1/*: any*/),
        "concreteType": null,
        "kind": "LinkedField",
        "name": "node",
        "plural": false,
        "selections": [
          (v2/*: any*/),
          {
            "kind": "InlineFragment",
            "selections": [
              (v3/*: any*/),
              (v4/*: any*/),
              (v5/*: any*/),
              (v6/*: any*/),
              (v7/*: any*/),
              (v8/*: any*/),
              {
                "args": null,
                "kind": "FragmentSpread",
                "name": "Cast_movie"
              },
              {
                "args": null,
                "kind": "FragmentSpread",
                "name": "Composer_movie"
              },
              {
                "args": null,
                "kind": "FragmentSpread",
                "name": "Director_movie"
              },
              {
                "args": null,
                "kind": "FragmentSpread",
                "name": "Producer_movie"
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
            "type": "movie",
            "abstractKey": null
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
    "name": "MoviePageQuery",
    "selections": [
      {
        "alias": "movie",
        "args": (v1/*: any*/),
        "concreteType": null,
        "kind": "LinkedField",
        "name": "node",
        "plural": false,
        "selections": [
          (v2/*: any*/),
          (v3/*: any*/),
          {
            "kind": "InlineFragment",
            "selections": [
              (v4/*: any*/),
              (v5/*: any*/),
              (v6/*: any*/),
              (v7/*: any*/),
              (v8/*: any*/),
              {
                "alias": "cast",
                "args": [
                  {
                    "kind": "Literal",
                    "name": "order_by",
                    "value": {
                      "person": {
                        "movie_people_aggregate": {
                          "count": "desc"
                        }
                      }
                    }
                  },
                  {
                    "kind": "Literal",
                    "name": "where",
                    "value": {
                      "job": {
                        "_eq": "cast"
                      }
                    }
                  }
                ],
                "concreteType": "movie_person",
                "kind": "LinkedField",
                "name": "movie_people",
                "plural": true,
                "selections": (v9/*: any*/),
                "storageKey": "movie_people(order_by:{\"person\":{\"movie_people_aggregate\":{\"count\":\"desc\"}}},where:{\"job\":{\"_eq\":\"cast\"}})"
              },
              {
                "alias": "composer",
                "args": [
                  {
                    "kind": "Literal",
                    "name": "where",
                    "value": {
                      "job": {
                        "_eq": "composer"
                      }
                    }
                  }
                ],
                "concreteType": "movie_person",
                "kind": "LinkedField",
                "name": "movie_people",
                "plural": true,
                "selections": (v9/*: any*/),
                "storageKey": "movie_people(where:{\"job\":{\"_eq\":\"composer\"}})"
              },
              {
                "alias": "director",
                "args": [
                  {
                    "kind": "Literal",
                    "name": "where",
                    "value": {
                      "job": {
                        "_eq": "director"
                      }
                    }
                  }
                ],
                "concreteType": "movie_person",
                "kind": "LinkedField",
                "name": "movie_people",
                "plural": true,
                "selections": (v9/*: any*/),
                "storageKey": "movie_people(where:{\"job\":{\"_eq\":\"director\"}})"
              },
              {
                "alias": "producer",
                "args": [
                  {
                    "kind": "Literal",
                    "name": "where",
                    "value": {
                      "job": {
                        "_eq": "producer"
                      }
                    }
                  }
                ],
                "concreteType": "movie_person",
                "kind": "LinkedField",
                "name": "movie_people",
                "plural": true,
                "selections": (v9/*: any*/),
                "storageKey": "movie_people(where:{\"job\":{\"_eq\":\"producer\"}})"
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
                  (v3/*: any*/),
                  {
                    "alias": null,
                    "args": null,
                    "kind": "ScalarField",
                    "name": "rating",
                    "storageKey": null
                  }
                ],
                "storageKey": null
              }
            ],
            "type": "movie",
            "abstractKey": null
          }
        ],
        "storageKey": null
      }
    ]
  },
  "params": {
    "cacheID": "56432502cf6bf1886771212ad67b1f08",
    "id": null,
    "metadata": {},
    "name": "MoviePageQuery",
    "operationKind": "query",
    "text": "query MoviePageQuery(\n  $id: ID!\n) {\n  movie: node(id: $id) {\n    __typename\n    ... on movie {\n      id\n      overview\n      release_date\n      runtime\n      tagline\n      title\n      ...Cast_movie\n      ...Composer_movie\n      ...Director_movie\n      ...Producer_movie\n      ...Poster_movie\n      ...Ratings_movie\n    }\n    id\n  }\n}\n\nfragment Cast_movie on movie {\n  cast: movie_people(where: {job: {_eq: \"cast\"}}, order_by: {person: {movie_people_aggregate: {count: desc}}}) {\n    person {\n      id\n      name\n    }\n    id\n  }\n}\n\nfragment Composer_movie on movie {\n  composer: movie_people(where: {job: {_eq: \"composer\"}}) {\n    person {\n      id\n      name\n    }\n    id\n  }\n}\n\nfragment Director_movie on movie {\n  director: movie_people(where: {job: {_eq: \"director\"}}) {\n    person {\n      id\n      name\n    }\n    id\n  }\n}\n\nfragment Poster_movie on movie {\n  poster\n}\n\nfragment Producer_movie on movie {\n  producer: movie_people(where: {job: {_eq: \"producer\"}}) {\n    person {\n      id\n      name\n    }\n    id\n  }\n}\n\nfragment Ratings_movie on movie {\n  ratings {\n    id\n    rating\n  }\n}\n"
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

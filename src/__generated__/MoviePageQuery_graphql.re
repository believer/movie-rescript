
/* @generated */

module Types = {
  [@ocaml.warning "-30"];
  type response_movie_movie = {
    title: string,
    original_id: option(int),
    id: string,
    fragmentRefs:
      ReasonRelay.fragmentRefs(
        [
          | `MovieOverview_movie
          | `Cast_movie
          | `Composer_movie
          | `Director_movie
          | `Producer_movie
          | `Poster_movie
          | `Ratings_movie
          | `MovieMeta_movie
          | `Genres_movie
          | `WatchDates_movie
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
  type refetchVariables = {
    id: option(string),
    genreLimit: option(int),
  };
  let makeRefetchVariables = (~id=?, ~genreLimit=?, ()): refetchVariables => {
    id,
    genreLimit,
  };
  type variables = {
    id: string,
    genreLimit: int,
  };
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
  type wrapResponseRaw;
  let wrapResponseConverter: Js.Dict.t(Js.Dict.t(Js.Dict.t(string))) = [%raw
    {json| {"__root":{"movie":{"n":"","u":"response_movie"},"movie_movie":{"f":""},"movie_movie_original_id":{"n":""}}} |json}
  ];
  let wrapResponseConverterMap = {"response_movie": wrap_response_movie};
  let convertWrapResponse = v =>
    v->ReasonRelay.convertObj(
      wrapResponseConverter,
      wrapResponseConverterMap,
      Js.null,
    );

  type responseRaw;
  let responseConverter: Js.Dict.t(Js.Dict.t(Js.Dict.t(string))) = [%raw
    {json| {"__root":{"movie":{"n":"","u":"response_movie"},"movie_movie":{"f":""},"movie_movie_original_id":{"n":""}}} |json}
  ];
  let responseConverterMap = {"response_movie": unwrap_response_movie};
  let convertResponse = v =>
    v->ReasonRelay.convertObj(
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
    v->ReasonRelay.convertObj(
      variablesConverter,
      variablesConverterMap,
      Js.undefined,
    );
};

type queryRef;

module Utils = {
  open Types;
  let makeVariables = (~id, ~genreLimit): variables => {id, genreLimit};
};

type relayOperationNode;

type operationType = ReasonRelay.queryNode(relayOperationNode);



let node: operationType = [%raw {json| (function(){
var v0 = {
  "defaultValue": null,
  "kind": "LocalArgument",
  "name": "genreLimit"
},
v1 = {
  "defaultValue": null,
  "kind": "LocalArgument",
  "name": "id"
},
v2 = [
  {
    "kind": "Variable",
    "name": "id",
    "variableName": "id"
  }
],
v3 = {
  "alias": null,
  "args": null,
  "kind": "ScalarField",
  "name": "__typename",
  "storageKey": null
},
v4 = {
  "alias": null,
  "args": null,
  "kind": "ScalarField",
  "name": "id",
  "storageKey": null
},
v5 = {
  "alias": null,
  "args": null,
  "kind": "ScalarField",
  "name": "original_id",
  "storageKey": null
},
v6 = {
  "alias": null,
  "args": null,
  "kind": "ScalarField",
  "name": "title",
  "storageKey": null
},
v7 = [
  (v4/*: any*/),
  {
    "alias": null,
    "args": null,
    "kind": "ScalarField",
    "name": "name",
    "storageKey": null
  }
],
v8 = [
  {
    "alias": null,
    "args": null,
    "concreteType": "person",
    "kind": "LinkedField",
    "name": "person",
    "plural": false,
    "selections": (v7/*: any*/),
    "storageKey": null
  },
  (v4/*: any*/)
];
return {
  "fragment": {
    "argumentDefinitions": [
      (v0/*: any*/),
      (v1/*: any*/)
    ],
    "kind": "Fragment",
    "metadata": null,
    "name": "MoviePageQuery",
    "selections": [
      {
        "alias": "movie",
        "args": (v2/*: any*/),
        "concreteType": null,
        "kind": "LinkedField",
        "name": "node",
        "plural": false,
        "selections": [
          (v3/*: any*/),
          {
            "kind": "InlineFragment",
            "selections": [
              (v4/*: any*/),
              (v5/*: any*/),
              (v6/*: any*/),
              {
                "args": null,
                "kind": "FragmentSpread",
                "name": "MovieOverview_movie"
              },
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
              },
              {
                "args": null,
                "kind": "FragmentSpread",
                "name": "MovieMeta_movie"
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
                "name": "WatchDates_movie"
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
    "argumentDefinitions": [
      (v1/*: any*/),
      (v0/*: any*/)
    ],
    "kind": "Operation",
    "name": "MoviePageQuery",
    "selections": [
      {
        "alias": "movie",
        "args": (v2/*: any*/),
        "concreteType": null,
        "kind": "LinkedField",
        "name": "node",
        "plural": false,
        "selections": [
          (v3/*: any*/),
          (v4/*: any*/),
          {
            "kind": "InlineFragment",
            "selections": [
              (v5/*: any*/),
              (v6/*: any*/),
              {
                "alias": null,
                "args": null,
                "kind": "ScalarField",
                "name": "overview",
                "storageKey": null
              },
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
                "selections": (v8/*: any*/),
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
                "selections": (v8/*: any*/),
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
                "selections": (v8/*: any*/),
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
                "selections": (v8/*: any*/),
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
                "name": "imdb_id",
                "storageKey": null
              },
              {
                "alias": null,
                "args": null,
                "kind": "ScalarField",
                "name": "release_date",
                "storageKey": null
              },
              {
                "alias": null,
                "args": null,
                "kind": "ScalarField",
                "name": "runtime",
                "storageKey": null
              },
              {
                "alias": null,
                "args": null,
                "kind": "ScalarField",
                "name": "tagline",
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
                    "selections": (v7/*: any*/),
                    "storageKey": null
                  },
                  (v4/*: any*/)
                ],
                "storageKey": null
              },
              {
                "alias": null,
                "args": null,
                "concreteType": "seen",
                "kind": "LinkedField",
                "name": "dates_watched",
                "plural": true,
                "selections": [
                  {
                    "alias": null,
                    "args": null,
                    "kind": "ScalarField",
                    "name": "date",
                    "storageKey": null
                  },
                  (v4/*: any*/)
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
    "cacheID": "ede37e4786f04c29b1a4579f84d6183f",
    "id": null,
    "metadata": {},
    "name": "MoviePageQuery",
    "operationKind": "query",
    "text": "query MoviePageQuery(\n  $id: ID!\n  $genreLimit: Int!\n) {\n  movie: node(id: $id) {\n    __typename\n    ... on movie {\n      id\n      original_id\n      title\n      ...MovieOverview_movie\n      ...Cast_movie\n      ...Composer_movie\n      ...Director_movie\n      ...Producer_movie\n      ...Poster_movie\n      ...Ratings_movie\n      ...MovieMeta_movie\n      ...Genres_movie_36mvd1\n      ...WatchDates_movie\n    }\n    id\n  }\n}\n\nfragment Cast_movie on movie {\n  cast: movie_people(where: {job: {_eq: \"cast\"}}, order_by: {person: {movie_people_aggregate: {count: desc}}}) {\n    person {\n      id\n      name\n    }\n    id\n  }\n}\n\nfragment Composer_movie on movie {\n  composer: movie_people(where: {job: {_eq: \"composer\"}}) {\n    person {\n      id\n      name\n    }\n    id\n  }\n}\n\nfragment Director_movie on movie {\n  director: movie_people(where: {job: {_eq: \"director\"}}) {\n    person {\n      id\n      name\n    }\n    id\n  }\n}\n\nfragment Genres_movie_36mvd1 on movie {\n  genres: movie_genres(limit: $genreLimit) {\n    genre {\n      id\n      name\n    }\n    id\n  }\n}\n\nfragment MovieMeta_movie on movie {\n  imdb_id\n  release_date\n  runtime\n  tagline\n}\n\nfragment MovieOverview_movie on movie {\n  overview\n}\n\nfragment Poster_movie on movie {\n  poster\n}\n\nfragment Producer_movie on movie {\n  producer: movie_people(where: {job: {_eq: \"producer\"}}) {\n    person {\n      id\n      name\n    }\n    id\n  }\n}\n\nfragment Ratings_movie on movie {\n  ratings {\n    id\n    rating\n  }\n}\n\nfragment WatchDates_movie on movie {\n  dates_watched {\n    date\n    id\n  }\n}\n"
  }
};
})() |json}];

include ReasonRelay.MakeLoadQuery({
    type variables = Types.variables;
    type loadedQueryRef = queryRef;
    type response = Types.response;
    type node = relayOperationNode;
    let query = node;
    let convertVariables = Internal.convertVariables;
  });

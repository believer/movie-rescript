/* @generated */
%%raw("/* @generated */")
module Types = {
  @@ocaml.warning("-30")
  
  type rec response_movies = {
    edges: array<response_movies_edges>,
  }
   and response_movies_edges = {
    movie: response_movies_edges_movie,
  }
   and response_movies_edges_movie = {
    id: string,
    title: string,
    year: option<string>,
    fragmentRefs: RescriptRelay.fragmentRefs<[ | #Poster_movie | #Ratings_movie]>
  }
   and response_cast = {
    edges: array<response_cast_edges>,
  }
   and response_cast_edges = {
    person: response_cast_edges_person,
  }
   and response_cast_edges_person = {
    name: string,
    movie_people: array<response_cast_edges_person_movie_people>,
    movie_people_aggregate: response_cast_edges_person_movie_people_aggregate,
    id: string,
  }
   and response_cast_edges_person_movie_people = {
    movie: response_cast_edges_person_movie_people_movie,
    id: string,
  }
   and response_cast_edges_person_movie_people_movie = {
    title: string,
  }
   and response_cast_edges_person_movie_people_aggregate = {
    aggregate: option<response_cast_edges_person_movie_people_aggregate_aggregate>,
  }
   and response_cast_edges_person_movie_people_aggregate_aggregate = {
    count: option<int>,
  }
  
  
  type response = {
    movies: response_movies,
    cast: response_cast,
  }
  type rawResponse = response
  type refetchVariables = {
    query: option<string>,
  }
  let makeRefetchVariables = (
    ~query=?,
    ()
  ): refetchVariables => {
    query: query
  }
  
  type variables = {
    query: string,
  }
}

module Internal = {
  type wrapResponseRaw
  let wrapResponseConverter: 
    Js.Dict.t<Js.Dict.t<Js.Dict.t<string>>> = 
    %raw(
      json`{"__root":{"movies_edges_movie":{"f":""},"movies_edges_movie_year":{"n":""},"cast_edges_person_movie_people_aggregate_aggregate":{"n":""},"cast_edges_person_movie_people_aggregate_aggregate_count":{"n":""}}}`
    )
  
  let wrapResponseConverterMap = ()
  let convertWrapResponse = v => v->RescriptRelay.convertObj(
    wrapResponseConverter, 
    wrapResponseConverterMap, 
    Js.null
  )
  type responseRaw
  let responseConverter: 
    Js.Dict.t<Js.Dict.t<Js.Dict.t<string>>> = 
    %raw(
      json`{"__root":{"movies_edges_movie":{"f":""},"movies_edges_movie_year":{"n":""},"cast_edges_person_movie_people_aggregate_aggregate":{"n":""},"cast_edges_person_movie_people_aggregate_aggregate_count":{"n":""}}}`
    )
  
  let responseConverterMap = ()
  let convertResponse = v => v->RescriptRelay.convertObj(
    responseConverter, 
    responseConverterMap, 
    Js.undefined
  )
  type wrapRawResponseRaw = wrapResponseRaw
  let convertWrapRawResponse = convertWrapResponse
  type rawResponseRaw = responseRaw
  let convertRawResponse = convertResponse
  let variablesConverter: 
    Js.Dict.t<Js.Dict.t<Js.Dict.t<string>>> = 
    %raw(
      json`{}`
    )
  
  let variablesConverterMap = ()
  let convertVariables = v => v->RescriptRelay.convertObj(
    variablesConverter, 
    variablesConverterMap, 
    Js.undefined
  )
}

type queryRef

module Utils = {
  @@ocaml.warning("-33")
  open Types
  let makeVariables = (
    ~query
  ): variables => {
    query: query
  }
}
type relayOperationNode
type operationType = RescriptRelay.queryNode<relayOperationNode>


let node: operationType = %raw(json` (function(){
var v0 = [
  {
    "defaultValue": null,
    "kind": "LocalArgument",
    "name": "query"
  }
],
v1 = {
  "release_date": "desc"
},
v2 = [
  {
    "kind": "Variable",
    "name": "_ilike",
    "variableName": "query"
  }
],
v3 = [
  {
    "kind": "Literal",
    "name": "order_by",
    "value": (v1/*: any*/)
  },
  {
    "fields": [
      {
        "fields": (v2/*: any*/),
        "kind": "ObjectValue",
        "name": "title"
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
},
v5 = {
  "alias": null,
  "args": null,
  "kind": "ScalarField",
  "name": "title",
  "storageKey": null
},
v6 = {
  "alias": null,
  "args": null,
  "kind": "ScalarField",
  "name": "year",
  "storageKey": null
},
v7 = {
  "job": {
    "_eq": "cast"
  }
},
v8 = [
  {
    "kind": "Literal",
    "name": "first",
    "value": 20
  },
  {
    "kind": "Literal",
    "name": "order_by",
    "value": {
      "movie_people_aggregate": {
        "count": "desc_nulls_last"
      }
    }
  },
  {
    "fields": [
      {
        "kind": "Literal",
        "name": "movie_people",
        "value": (v7/*: any*/)
      },
      {
        "fields": (v2/*: any*/),
        "kind": "ObjectValue",
        "name": "name"
      }
    ],
    "kind": "ObjectValue",
    "name": "where"
  }
],
v9 = {
  "alias": null,
  "args": null,
  "kind": "ScalarField",
  "name": "name",
  "storageKey": null
},
v10 = {
  "kind": "Literal",
  "name": "where",
  "value": (v7/*: any*/)
},
v11 = [
  {
    "kind": "Literal",
    "name": "limit",
    "value": 3
  },
  {
    "kind": "Literal",
    "name": "order_by",
    "value": {
      "movie": (v1/*: any*/)
    }
  },
  (v10/*: any*/)
],
v12 = {
  "alias": null,
  "args": [
    (v10/*: any*/)
  ],
  "concreteType": "movie_person_aggregate",
  "kind": "LinkedField",
  "name": "movie_people_aggregate",
  "plural": false,
  "selections": [
    {
      "alias": null,
      "args": null,
      "concreteType": "movie_person_aggregate_fields",
      "kind": "LinkedField",
      "name": "aggregate",
      "plural": false,
      "selections": [
        {
          "alias": null,
          "args": null,
          "kind": "ScalarField",
          "name": "count",
          "storageKey": null
        }
      ],
      "storageKey": null
    }
  ],
  "storageKey": "movie_people_aggregate(where:{\"job\":{\"_eq\":\"cast\"}})"
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
                "alias": "movie",
                "args": null,
                "concreteType": "movie",
                "kind": "LinkedField",
                "name": "node",
                "plural": false,
                "selections": [
                  (v4/*: any*/),
                  (v5/*: any*/),
                  (v6/*: any*/),
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
              }
            ],
            "storageKey": null
          }
        ],
        "storageKey": null
      },
      {
        "alias": "cast",
        "args": (v8/*: any*/),
        "concreteType": "personConnection",
        "kind": "LinkedField",
        "name": "person_connection",
        "plural": false,
        "selections": [
          {
            "alias": null,
            "args": null,
            "concreteType": "personEdge",
            "kind": "LinkedField",
            "name": "edges",
            "plural": true,
            "selections": [
              {
                "alias": "person",
                "args": null,
                "concreteType": "person",
                "kind": "LinkedField",
                "name": "node",
                "plural": false,
                "selections": [
                  (v9/*: any*/),
                  {
                    "alias": null,
                    "args": (v11/*: any*/),
                    "concreteType": "movie_person",
                    "kind": "LinkedField",
                    "name": "movie_people",
                    "plural": true,
                    "selections": [
                      {
                        "alias": null,
                        "args": null,
                        "concreteType": "movie",
                        "kind": "LinkedField",
                        "name": "movie",
                        "plural": false,
                        "selections": [
                          (v5/*: any*/)
                        ],
                        "storageKey": null
                      },
                      (v4/*: any*/)
                    ],
                    "storageKey": "movie_people(limit:3,order_by:{\"movie\":{\"release_date\":\"desc\"}},where:{\"job\":{\"_eq\":\"cast\"}})"
                  },
                  (v12/*: any*/),
                  (v4/*: any*/)
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
                "alias": "movie",
                "args": null,
                "concreteType": "movie",
                "kind": "LinkedField",
                "name": "node",
                "plural": false,
                "selections": [
                  (v4/*: any*/),
                  (v5/*: any*/),
                  (v6/*: any*/),
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
                  }
                ],
                "storageKey": null
              }
            ],
            "storageKey": null
          }
        ],
        "storageKey": null
      },
      {
        "alias": "cast",
        "args": (v8/*: any*/),
        "concreteType": "personConnection",
        "kind": "LinkedField",
        "name": "person_connection",
        "plural": false,
        "selections": [
          {
            "alias": null,
            "args": null,
            "concreteType": "personEdge",
            "kind": "LinkedField",
            "name": "edges",
            "plural": true,
            "selections": [
              {
                "alias": "person",
                "args": null,
                "concreteType": "person",
                "kind": "LinkedField",
                "name": "node",
                "plural": false,
                "selections": [
                  (v9/*: any*/),
                  {
                    "alias": null,
                    "args": (v11/*: any*/),
                    "concreteType": "movie_person",
                    "kind": "LinkedField",
                    "name": "movie_people",
                    "plural": true,
                    "selections": [
                      {
                        "alias": null,
                        "args": null,
                        "concreteType": "movie",
                        "kind": "LinkedField",
                        "name": "movie",
                        "plural": false,
                        "selections": [
                          (v5/*: any*/),
                          (v4/*: any*/)
                        ],
                        "storageKey": null
                      },
                      (v4/*: any*/)
                    ],
                    "storageKey": "movie_people(limit:3,order_by:{\"movie\":{\"release_date\":\"desc\"}},where:{\"job\":{\"_eq\":\"cast\"}})"
                  },
                  (v12/*: any*/),
                  (v4/*: any*/)
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
    "cacheID": "8bac51fe77d41416edd11f241cceec06",
    "id": null,
    "metadata": {},
    "name": "SearchPageQuery",
    "operationKind": "query",
    "text": "query SearchPageQuery(\n  $query: String!\n) {\n  movies: movie_connection(where: {title: {_ilike: $query}}, order_by: {release_date: desc}) {\n    edges {\n      movie: node {\n        id\n        title\n        year\n        ...Poster_movie\n        ...Ratings_movie\n      }\n    }\n  }\n  cast: person_connection(first: 20, where: {name: {_ilike: $query}, movie_people: {job: {_eq: \"cast\"}}}, order_by: {movie_people_aggregate: {count: desc_nulls_last}}) {\n    edges {\n      person: node {\n        name\n        movie_people(limit: 3, order_by: {movie: {release_date: desc}}, where: {job: {_eq: \"cast\"}}) {\n          movie {\n            title\n            id\n          }\n          id\n        }\n        movie_people_aggregate(where: {job: {_eq: \"cast\"}}) {\n          aggregate {\n            count\n          }\n        }\n        id\n      }\n    }\n  }\n}\n\nfragment Poster_movie on movie {\n  poster\n}\n\nfragment Ratings_movie on movie {\n  ratings {\n    id\n    rating\n  }\n}\n"
  }
};
})() `)

include RescriptRelay.MakeLoadQuery({
    type variables = Types.variables
    type loadedQueryRef = queryRef
    type response = Types.response
    type node = relayOperationNode
    let query = node
    let convertVariables = Internal.convertVariables
  });

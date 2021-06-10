/* @generated */
%%raw("/* @generated */")
module Types = {
  @@ocaml.warning("-30")
  
  type rec response_insert_seen_one = {
    id: string,
    movie: response_insert_seen_one_movie,
  }
   and response_insert_seen_one_movie = {
    id: string,
    year: option<string>,
    title: string,
    fragmentRefs: RescriptRelay.fragmentRefs<[ | #Genres_movie | #Poster_movie | #Ratings_movie]>
  }
  
  
  type response = {
    insert_seen_one: option<response_insert_seen_one>,
  }
  type rawResponse = response
  type variables = {
    id: int,
    date: string,
  }
}

module Internal = {
  type wrapResponseRaw
  let wrapResponseConverter: 
    Js.Dict.t<Js.Dict.t<Js.Dict.t<string>>> = 
    %raw(
      json`{"__root":{"insert_seen_one_movie":{"f":""},"insert_seen_one":{"n":""},"insert_seen_one_movie_year":{"n":""}}}`
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
      json`{"__root":{"insert_seen_one_movie":{"f":""},"insert_seen_one":{"n":""},"insert_seen_one_movie_year":{"n":""}}}`
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


module Utils = {
  @@ocaml.warning("-33")
  open Types
  let makeVariables = (
    ~id,
    ~date
  ): variables => {
    id: id,
    date: date
  }
  let make_response_insert_seen_one_movie = (
    ~id,
    ~year=?,
    ~title,
    ~fragmentRefs,
    ()
  ): response_insert_seen_one_movie => {
    id: id,
    year: year,
    title: title,
    fragmentRefs: fragmentRefs
  }
  let make_response_insert_seen_one = (
    ~id,
    ~movie
  ): response_insert_seen_one => {
    id: id,
    movie: movie
  }
  let makeOptimisticResponse = (
    ~insert_seen_one=?,
    ()
  ): rawResponse => {
    insert_seen_one: insert_seen_one
  }
}
type relayOperationNode
type operationType = RescriptRelay.mutationNode<relayOperationNode>


let node: operationType = %raw(json` (function(){
var v0 = {
  "defaultValue": null,
  "kind": "LocalArgument",
  "name": "date"
},
v1 = {
  "defaultValue": null,
  "kind": "LocalArgument",
  "name": "id"
},
v2 = [
  {
    "fields": [
      {
        "kind": "Variable",
        "name": "date",
        "variableName": "date"
      },
      {
        "kind": "Variable",
        "name": "movie_id",
        "variableName": "id"
      }
    ],
    "kind": "ObjectValue",
    "name": "object"
  }
],
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
  "name": "year",
  "storageKey": null
},
v5 = {
  "alias": null,
  "args": null,
  "kind": "ScalarField",
  "name": "title",
  "storageKey": null
};
return {
  "fragment": {
    "argumentDefinitions": [
      (v0/*: any*/),
      (v1/*: any*/)
    ],
    "kind": "Fragment",
    "metadata": null,
    "name": "WatchDatesMutation",
    "selections": [
      {
        "alias": null,
        "args": (v2/*: any*/),
        "concreteType": "seen",
        "kind": "LinkedField",
        "name": "insert_seen_one",
        "plural": false,
        "selections": [
          (v3/*: any*/),
          {
            "alias": null,
            "args": null,
            "concreteType": "movie",
            "kind": "LinkedField",
            "name": "movie",
            "plural": false,
            "selections": [
              (v3/*: any*/),
              (v4/*: any*/),
              (v5/*: any*/),
              {
                "args": null,
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
          }
        ],
        "storageKey": null
      }
    ],
    "type": "mutation_root",
    "abstractKey": null
  },
  "kind": "Request",
  "operation": {
    "argumentDefinitions": [
      (v1/*: any*/),
      (v0/*: any*/)
    ],
    "kind": "Operation",
    "name": "WatchDatesMutation",
    "selections": [
      {
        "alias": null,
        "args": (v2/*: any*/),
        "concreteType": "seen",
        "kind": "LinkedField",
        "name": "insert_seen_one",
        "plural": false,
        "selections": [
          (v3/*: any*/),
          {
            "alias": null,
            "args": null,
            "concreteType": "movie",
            "kind": "LinkedField",
            "name": "movie",
            "plural": false,
            "selections": [
              (v3/*: any*/),
              (v4/*: any*/),
              (v5/*: any*/),
              {
                "alias": "genres",
                "args": [
                  {
                    "kind": "Literal",
                    "name": "limit",
                    "value": 3
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
                ],
                "storageKey": "movie_genres(limit:3)"
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
            "storageKey": null
          }
        ],
        "storageKey": null
      }
    ]
  },
  "params": {
    "cacheID": "a95889e25c94c68c5c02b0cff4a4489a",
    "id": null,
    "metadata": {},
    "name": "WatchDatesMutation",
    "operationKind": "mutation",
    "text": "mutation WatchDatesMutation(\n  $id: Int!\n  $date: timestamp!\n) {\n  insert_seen_one(object: {movie_id: $id, date: $date}) {\n    id\n    movie {\n      id\n      year\n      title\n      ...Genres_movie\n      ...Poster_movie\n      ...Ratings_movie\n    }\n  }\n}\n\nfragment Genres_movie on movie {\n  genres: movie_genres(limit: 3) {\n    genre {\n      id\n      name\n    }\n    id\n  }\n}\n\nfragment Poster_movie on movie {\n  poster\n}\n\nfragment Ratings_movie on movie {\n  ratings {\n    id\n    rating\n  }\n}\n"
  }
};
})() `)



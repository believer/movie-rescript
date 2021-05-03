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
      json`{"__root":{"insert_seen_one":{"n":""},"insert_seen_one_movie_year":{"n":""}}}`
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
      json`{"__root":{"insert_seen_one":{"n":""},"insert_seen_one_movie_year":{"n":""}}}`
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
    ()
  ): response_insert_seen_one_movie => {
    id: id,
    year: year,
    title: title
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
v2 = {
  "alias": null,
  "args": null,
  "kind": "ScalarField",
  "name": "id",
  "storageKey": null
},
v3 = [
  {
    "alias": null,
    "args": [
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
    "concreteType": "seen",
    "kind": "LinkedField",
    "name": "insert_seen_one",
    "plural": false,
    "selections": [
      (v2/*: any*/),
      {
        "alias": null,
        "args": null,
        "concreteType": "movie",
        "kind": "LinkedField",
        "name": "movie",
        "plural": false,
        "selections": [
          (v2/*: any*/),
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
          }
        ],
        "storageKey": null
      }
    ],
    "storageKey": null
  }
];
return {
  "fragment": {
    "argumentDefinitions": [
      (v0/*: any*/),
      (v1/*: any*/)
    ],
    "kind": "Fragment",
    "metadata": null,
    "name": "WatchDatesMutation",
    "selections": (v3/*: any*/),
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
    "selections": (v3/*: any*/)
  },
  "params": {
    "cacheID": "2071bcd73b30c6b1fcdef807f542b198",
    "id": null,
    "metadata": {},
    "name": "WatchDatesMutation",
    "operationKind": "mutation",
    "text": "mutation WatchDatesMutation(\n  $id: Int!\n  $date: timestamp!\n) {\n  insert_seen_one(object: {movie_id: $id, date: $date}) {\n    id\n    movie {\n      id\n      year\n      title\n    }\n  }\n}\n"
  }
};
})() `)



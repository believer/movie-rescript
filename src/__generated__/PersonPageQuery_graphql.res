/* @generated */
%%raw("/* @generated */")
module Types = {
  @@ocaml.warning("-30")
  
  type rec response_node = {
    __typename: [ | #person],
    id: string,
    name: string,
    jobs: array<response_node_jobs>,
  }
   and response_node_jobs = {
    job: Job.t,
    movie: response_node_jobs_movie,
  }
   and response_node_jobs_movie = {
    id: string,
    title: string,
    year: option<string>,
  }
  
  
  type response = {
    node: option<response_node>,
  }
  type rawResponse = response
  type refetchVariables = {
    id: option<string>,
  }
  let makeRefetchVariables = (
    ~id=?,
    ()
  ): refetchVariables => {
    id: id
  }
  
  type variables = {
    id: string,
  }
}

module Internal = {
  type wrapResponseRaw
  let wrapResponseConverter: 
    Js.Dict.t<Js.Dict.t<Js.Dict.t<string>>> = 
    %raw(
      json`{"__root":{"node_jobs_job":{"c":"Job"},"node":{"n":"","tnf":"person"},"node_jobs_movie_year":{"n":""}}}`
    )
  
  let wrapResponseConverterMap = {
    "Job": Job.serialize,
  }
  
  let convertWrapResponse = v => v->RescriptRelay.convertObj(
    wrapResponseConverter, 
    wrapResponseConverterMap, 
    Js.null
  )
  type responseRaw
  let responseConverter: 
    Js.Dict.t<Js.Dict.t<Js.Dict.t<string>>> = 
    %raw(
      json`{"__root":{"node_jobs_job":{"c":"Job"},"node":{"n":"","tnf":"person"},"node_jobs_movie_year":{"n":""}}}`
    )
  
  let responseConverterMap = {
    "Job": Job.parse,
  }
  
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
  open Types
  let makeVariables = (
    ~id
  ): variables => {
    id: id
  }
}
type relayOperationNode
type operationType = RescriptRelay.queryNode<relayOperationNode>


let node: operationType = %raw(json` (function(){
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
  "name": "name",
  "storageKey": null
},
v5 = [
  {
    "kind": "Literal",
    "name": "order_by",
    "value": {
      "movie": {
        "release_date": "desc"
      }
    }
  }
],
v6 = {
  "alias": null,
  "args": null,
  "kind": "ScalarField",
  "name": "job",
  "storageKey": null
},
v7 = {
  "alias": null,
  "args": null,
  "concreteType": "movie",
  "kind": "LinkedField",
  "name": "movie",
  "plural": false,
  "selections": [
    (v3/*: any*/),
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
      "name": "year",
      "storageKey": null
    }
  ],
  "storageKey": null
};
return {
  "fragment": {
    "argumentDefinitions": (v0/*: any*/),
    "kind": "Fragment",
    "metadata": null,
    "name": "PersonPageQuery",
    "selections": [
      {
        "alias": null,
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
              {
                "alias": "jobs",
                "args": (v5/*: any*/),
                "concreteType": "movie_person",
                "kind": "LinkedField",
                "name": "movie_people",
                "plural": true,
                "selections": [
                  (v6/*: any*/),
                  (v7/*: any*/)
                ],
                "storageKey": "movie_people(order_by:{\"movie\":{\"release_date\":\"desc\"}})"
              }
            ],
            "type": "person",
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
    "name": "PersonPageQuery",
    "selections": [
      {
        "alias": null,
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
              {
                "alias": "jobs",
                "args": (v5/*: any*/),
                "concreteType": "movie_person",
                "kind": "LinkedField",
                "name": "movie_people",
                "plural": true,
                "selections": [
                  (v6/*: any*/),
                  (v7/*: any*/),
                  (v3/*: any*/)
                ],
                "storageKey": "movie_people(order_by:{\"movie\":{\"release_date\":\"desc\"}})"
              }
            ],
            "type": "person",
            "abstractKey": null
          }
        ],
        "storageKey": null
      }
    ]
  },
  "params": {
    "cacheID": "094e26e1e56c3b05a5cb7c5532cb468e",
    "id": null,
    "metadata": {},
    "name": "PersonPageQuery",
    "operationKind": "query",
    "text": "query PersonPageQuery(\n  $id: ID!\n) {\n  node(id: $id) {\n    __typename\n    ... on person {\n      id\n      name\n      jobs: movie_people(order_by: {movie: {release_date: desc}}) {\n        job\n        movie {\n          id\n          title\n          year\n        }\n        id\n      }\n    }\n    id\n  }\n}\n"
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

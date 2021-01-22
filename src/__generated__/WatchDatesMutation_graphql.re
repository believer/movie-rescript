
/* @generated */

module Types = {
  [@ocaml.warning "-30"];
  type response_insert_seen_one = {id: string};

  type response = {insert_seen_one: option(response_insert_seen_one)};
  type rawResponse = response;
  type variables = {
    id: int,
    date: string,
  };
};

module Internal = {
  type wrapResponseRaw;
  let wrapResponseConverter: Js.Dict.t(Js.Dict.t(Js.Dict.t(string))) = [%raw
    {json| {"__root":{"insert_seen_one":{"n":""}}} |json}
  ];
  let wrapResponseConverterMap = ();
  let convertWrapResponse = v =>
    v->ReasonRelay.convertObj(
      wrapResponseConverter,
      wrapResponseConverterMap,
      Js.null,
    );

  type responseRaw;
  let responseConverter: Js.Dict.t(Js.Dict.t(Js.Dict.t(string))) = [%raw
    {json| {"__root":{"insert_seen_one":{"n":""}}} |json}
  ];
  let responseConverterMap = ();
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

module Utils = {
  open Types;
  let makeVariables = (~id, ~date): variables => {id, date};

  let make_response_insert_seen_one = (~id): response_insert_seen_one => {
    id: id,
  };

  let makeOptimisticResponse = (~insert_seen_one=?, ()): rawResponse => {
    insert_seen_one: insert_seen_one,
  };
};

type relayOperationNode;

type operationType = ReasonRelay.mutationNode(relayOperationNode);



let node: operationType = [%raw {json| (function(){
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
      {
        "alias": null,
        "args": null,
        "kind": "ScalarField",
        "name": "id",
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
    "selections": (v2/*: any*/),
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
    "selections": (v2/*: any*/)
  },
  "params": {
    "cacheID": "9cd244fb8247a73383076c6cb18a1775",
    "id": null,
    "metadata": {},
    "name": "WatchDatesMutation",
    "operationKind": "mutation",
    "text": "mutation WatchDatesMutation(\n  $id: Int!\n  $date: timestamp!\n) {\n  insert_seen_one(object: {movie_id: $id, date: $date}) {\n    id\n  }\n}\n"
  }
};
})() |json}];



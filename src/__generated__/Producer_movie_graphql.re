
/* @generated */

module Types = {
  [@ocaml.warning "-30"];
  type fragment_producer = {person: fragment_producer_person}
  and fragment_producer_person = {
    id: string,
    name: string,
  };

  type fragment = {producer: array(fragment_producer)};
};

module Internal = {
  type fragmentRaw;
  let fragmentConverter: Js.Dict.t(Js.Dict.t(Js.Dict.t(string))) = [%raw
    {json| {} |json}
  ];
  let fragmentConverterMap = ();
  let convertFragment = v =>
    v->ReasonRelay.convertObj(
      fragmentConverter,
      fragmentConverterMap,
      Js.undefined,
    );
};

type t;
type fragmentRef;
external getFragmentRef:
  ReasonRelay.fragmentRefs([> | `Producer_movie]) => fragmentRef =
  "%identity";

module Utils = {};

type relayOperationNode;

type operationType = ReasonRelay.fragmentNode(relayOperationNode);



let node: operationType = [%raw {json| {
  "argumentDefinitions": [],
  "kind": "Fragment",
  "metadata": null,
  "name": "Producer_movie",
  "selections": [
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
      "selections": [
        {
          "alias": null,
          "args": null,
          "concreteType": "person",
          "kind": "LinkedField",
          "name": "person",
          "plural": false,
          "selections": [
            {
              "alias": null,
              "args": null,
              "kind": "ScalarField",
              "name": "id",
              "storageKey": null
            },
            {
              "alias": null,
              "args": null,
              "kind": "ScalarField",
              "name": "name",
              "storageKey": null
            }
          ],
          "storageKey": null
        }
      ],
      "storageKey": "movie_people(where:{\"job\":{\"_eq\":\"producer\"}})"
    }
  ],
  "type": "movie",
  "abstractKey": null
} |json}];



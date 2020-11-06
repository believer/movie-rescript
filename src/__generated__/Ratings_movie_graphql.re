/* @generated */

module Types = {
  [@ocaml.warning "-30"];
  type fragment_ratings = {
    id: string,
    rating: int,
  };

  type fragment = {ratings: array(fragment_ratings)};
};

module Internal = {
  type fragmentRaw;
  let fragmentConverter: Js.Dict.t(Js.Dict.t(Js.Dict.t(string))) = [%raw
    {json| {} |json}
  ];
  let fragmentConverterMap = ();
  let convertFragment = v =>
    v
    ->ReasonRelay._convertObj(
        fragmentConverter,
        fragmentConverterMap,
        Js.undefined,
      );
};

type t;
type fragmentRef;
external getFragmentRef:
  ReasonRelay.fragmentRefs([> | `Ratings_movie]) => fragmentRef =
  "%identity";

module Utils = {};

type operationType = ReasonRelay.fragmentNode;

let node: operationType = [%raw
  {json| {
  "argumentDefinitions": [],
  "kind": "Fragment",
  "metadata": null,
  "name": "Ratings_movie",
  "selections": [
    {
      "alias": null,
      "args": null,
      "concreteType": "rating",
      "kind": "LinkedField",
      "name": "ratings",
      "plural": true,
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
          "name": "rating",
          "storageKey": null
        }
      ],
      "storageKey": null
    }
  ],
  "type": "movie",
  "abstractKey": null
} |json}
];

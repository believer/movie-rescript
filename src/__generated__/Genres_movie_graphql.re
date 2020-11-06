/* @generated */

module Types = {
  [@ocaml.warning "-30"];
  type fragment_genres = {genre: fragment_genres_genre}
  and fragment_genres_genre = {
    id: string,
    name: string,
  };

  type fragment = {genres: array(fragment_genres)};
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
  ReasonRelay.fragmentRefs([> | `Genres_movie]) => fragmentRef =
  "%identity";

module Utils = {};

type operationType = ReasonRelay.fragmentNode;

let node: operationType = [%raw
  {json| {
  "argumentDefinitions": [],
  "kind": "Fragment",
  "metadata": null,
  "name": "Genres_movie",
  "selections": [
    {
      "alias": "genres",
      "args": null,
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
      "storageKey": null
    }
  ],
  "type": "movie",
  "abstractKey": null
} |json}
];

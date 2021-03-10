/* @generated */
%%raw("/* @generated */")
module Types = {
  @@ocaml.warning("-30")
  
  type rec fragment_composer = {
    person: fragment_composer_person,
  }
   and fragment_composer_person = {
    id: string,
    name: string,
  }
  
  
  type fragment = {
    composer: array<fragment_composer>,
  }
}

module Internal = {
  type fragmentRaw
  let fragmentConverter: 
    Js.Dict.t<Js.Dict.t<Js.Dict.t<string>>> = 
    %raw(
      json`{}`
    )
  
  let fragmentConverterMap = ()
  let convertFragment = v => v->RescriptRelay.convertObj(
    fragmentConverter, 
    fragmentConverterMap, 
    Js.undefined
  )
}
type t
type fragmentRef
external getFragmentRef:
  RescriptRelay.fragmentRefs<[> | #Composer_movie]> => fragmentRef = "%identity"


module Utils = {

}
type relayOperationNode
type operationType = RescriptRelay.fragmentNode<relayOperationNode>


let node: operationType = %raw(json` {
  "argumentDefinitions": [],
  "kind": "Fragment",
  "metadata": null,
  "name": "Composer_movie",
  "selections": [
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
      "storageKey": "movie_people(where:{\"job\":{\"_eq\":\"composer\"}})"
    }
  ],
  "type": "movie",
  "abstractKey": null
} `)



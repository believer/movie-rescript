/* @generated */
%%raw("/* @generated */")
module Types = {
  @@ocaml.warning("-30")
  
  type rec fragment_director = {
    person: fragment_director_person,
  }
   and fragment_director_person = {
    id: string,
    name: string,
  }
  
  
  type fragment = {
    director: array<fragment_director>,
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
  RescriptRelay.fragmentRefs<[> | #Director_movie]> => fragmentRef = "%identity"


module Utils = {

}
type relayOperationNode
type operationType = RescriptRelay.fragmentNode<relayOperationNode>


let node: operationType = %raw(json` {
  "argumentDefinitions": [],
  "kind": "Fragment",
  "metadata": null,
  "name": "Director_movie",
  "selections": [
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
      "storageKey": "movie_people(where:{\"job\":{\"_eq\":\"director\"}})"
    }
  ],
  "type": "movie",
  "abstractKey": null
} `)



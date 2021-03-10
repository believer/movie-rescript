/* @generated */
%%raw("/* @generated */")
module Types = {
  @@ocaml.warning("-30")
  
  type rec fragment_cast = {
    person: fragment_cast_person,
  }
   and fragment_cast_person = {
    id: string,
    name: string,
  }
  
  
  type fragment = {
    cast: array<fragment_cast>,
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
  RescriptRelay.fragmentRefs<[> | #Cast_movie]> => fragmentRef = "%identity"


module Utils = {

}
type relayOperationNode
type operationType = RescriptRelay.fragmentNode<relayOperationNode>


let node: operationType = %raw(json` {
  "argumentDefinitions": [],
  "kind": "Fragment",
  "metadata": null,
  "name": "Cast_movie",
  "selections": [
    {
      "alias": "cast",
      "args": [
        {
          "kind": "Literal",
          "name": "order_by",
          "value": {
            "person": {
              "movie_people_aggregate": {
                "count": "desc"
              }
            }
          }
        },
        {
          "kind": "Literal",
          "name": "where",
          "value": {
            "job": {
              "_eq": "cast"
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
      "storageKey": "movie_people(order_by:{\"person\":{\"movie_people_aggregate\":{\"count\":\"desc\"}}},where:{\"job\":{\"_eq\":\"cast\"}})"
    }
  ],
  "type": "movie",
  "abstractKey": null
} `)



open Js.Promise
open Fetch

exception Graphql_error(string)

let fetchQuery: (unit => Js.Promise.t<'a>) => RescriptRelay.Network.fetchFunctionPromise = (
  getAccessTokenSilently,
  operation,
  variables,
  _cacheConfig,
  _uploadables,
) =>
  getAccessTokenSilently()
  |> then_(token =>
    fetchWithInit(
      "https://shining-fowl-19.hasura.app/v1beta1/relay",
      RequestInit.make(
        ~method_=Post,
        ~body=Js.Dict.fromList(list{
          ("query", Js.Json.string(operation.text)),
          ("variables", variables),
        })
        |> Js.Json.object_
        |> Js.Json.stringify
        |> BodyInit.make,
        ~headers=HeadersInit.make({
          "content-type": "application/json",
          "Authorization": "Bearer " ++ token,
          "accept": "application/json",
        }),
        (),
      ),
    )
  )
  |> then_(resp =>
    if Response.ok(resp) {
      Response.json(resp)
    } else {
      reject(Graphql_error("Request failed: " ++ Response.statusText(resp)))
    }
  )

let network = getAccessTokenSilently =>
  RescriptRelay.Network.makePromiseBased(~fetchFunction=fetchQuery(getAccessTokenSilently), ())

let environment = getAccessTokenSilently =>
  RescriptRelay.Environment.make(
    ~network=network(getAccessTokenSilently),
    ~store=RescriptRelay.Store.make(
      ~source=RescriptRelay.RecordSource.make(),
      ~gcReleaseBufferSize=10, // This sets the query cache size to 10
      (),
    ),
    (),
  )

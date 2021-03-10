module Route = {
  type t =
    | AddMovie
    | Feed
    | Person(string)
    | Movie(string)
    | Search(string)

  let fromPath = path =>
    switch path {
    | list{} => Feed
    | list{"add"} => AddMovie
    | list{"movie", id} => Movie(id)
    | list{"person", id} => Person(id)
    | list{"search", query} => Search(query)
    | _ => Feed
    }

  let toPath = route =>
    switch route {
    | Feed => "/"
    | AddMovie => "/add"
    | Person(id) => "/person/" ++ id
    | Movie(id) => "/movie/" ++ id
    | Search(query) => "/search/" ++ query
    }

  let go = path => path->toPath->RescriptReactRouter.push
}

module Link = {
  let handleLinkClick = (to_, e) => {
    ReactEvent.Mouse.preventDefault(e)
    Route.go(to_)
  }

  @react.component
  let make = (~className="", ~to_: Route.t, ~children) => {
    let href = Route.toPath(to_)

    <a className href onClick={handleLinkClick(to_)}> children </a>
  }
}

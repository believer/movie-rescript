module Route = {
  type t =
    | AddMovie
    | Feed
    | Person(string)
    | Movie(string);

  let fromPath = path =>
    switch (path) {
    | [] => Feed
    | ["add"] => AddMovie
    | ["movie", id] => Movie(id)
    | ["person", id] => Person(id)
    | _ => Feed
    };

  let toPath = route =>
    switch (route) {
    | Feed => "/"
    | AddMovie => "/add"
    | Person(id) => "/person/" ++ id
    | Movie(id) => "/movie/" ++ id
    };

  let go = path => path->toPath->ReasonReactRouter.push;
};

module Link = {
  let handleLinkClick = (to_, e) => {
    ReactEvent.Mouse.preventDefault(e);
    Route.go(to_);
  };

  [@react.component]
  let make = (~className="", ~to_: Route.t, ~children) => {
    let href = Route.toPath(to_);

    <a className href onClick={handleLinkClick(to_)}> children </a>;
  };
};

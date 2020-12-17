@react.component
let make = (~to_: Router.Route.t, ~children) =>
  <Router.Link className="text-indigo-600" to_> children </Router.Link>

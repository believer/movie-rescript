@react.component
let make = (~to_: Router.Route.t, ~children) =>
  <Router.Link className="text-blue-600 underline" to_> children </Router.Link>

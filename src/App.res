@bs.val
external import_: string => Js.Promise.t<React.component<'props>> = "import"

@bs.module("react")
external lazy_: (unit => Js.Promise.t<React.component<'props>>) => React.component<'props> = "lazy"

@bs.new external emptyObj: unit => Js.t<{.}> = "Object"

let movieComp = lazy_(() => import_("./pages/MoviePage.bs.js"))
let personComp = lazy_(() => import_("./pages/PersonPage.bs.js"))
let addMovieComp = lazy_(() => import_("./pages/AddMoviePage.bs.js"))
let feedComp = lazy_(() => import_("./pages/FeedPage.bs.js"))

@react.component
let make = () => {
  let url = ReasonReactRouter.useUrl()
  let path = Router.Route.fromPath(url.path)
  let {Auth0.loginWithRedirect: loginWithRedirect, isAuthenticated, logout, user} = Auth0.useAuth0()

  <>
    {switch (isAuthenticated, user) {
    | (false, _) | (true, None) =>
      <Layout.Button onClick={_ => loginWithRedirect()}> {React.string("Log in")} </Layout.Button>
    | (true, Some(user)) =>
      <div className="mt-8 grid grid-md">
        <div className="flex">
          <Link to_=Feed> <Icon.Movie /> </Link>
          <div className="ml-8">
            <Router.Link to_=AddMovie> {React.string("Add movie")} </Router.Link>
          </div>
          <div className="flex ml-auto">
            {switch user.picture {
            | Some(src) => <img className="w-8 h-8 mr-4 rounded-full" src />
            | None => React.null
            }}
            <button className="text-sm text-gray-700" onClick={_ => logout({returnTo: Web.origin})}>
              {React.string("Log out")}
            </button>
          </div>
        </div>
      </div>
    }}
    <React.Suspense
      fallback={<div className="flex flex-col items-center justify-center h-screen text-gray-600">
        <Icon.Movie /> {React.string("Loading")}
      </div>}>
      {switch path {
      | Feed => React.createElement(feedComp, emptyObj())
      | AddMovie => React.createElement(addMovieComp, emptyObj())
      | Movie(id) => React.createElement(movieComp, {"id": id})
      | Person(id) => React.createElement(personComp, {"id": id})
      }}
    </React.Suspense>
  </>
}

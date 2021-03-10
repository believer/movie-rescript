let movieComp = ReactLazy.lazy_(() => ReactLazy.import_("./pages/MoviePage.bs.js"))
let personComp = ReactLazy.lazy_(() => ReactLazy.import_("./pages/PersonPage.bs.js"))
let addMovieComp = ReactLazy.lazy_(() => ReactLazy.import_("./pages/AddMoviePage.bs.js"))
let feedComp = ReactLazy.lazy_(() => ReactLazy.import_("./pages/FeedPage.bs.js"))
let searchComp = ReactLazy.lazy_(() => ReactLazy.import_("./pages/SearchPage.bs.js"))

@react.component
let make = () => {
  let url = RescriptReactRouter.useUrl()
  let path = Router.Route.fromPath(url.path)
  let {Auth0.loginWithRedirect: loginWithRedirect, isAuthenticated, logout, user} = Auth0.useAuth0()

  <>
    {switch (isAuthenticated, user) {
    | (false, _) | (true, None) =>
      <Layout.Button onClick={_ => loginWithRedirect()}> {React.string("Log in")} </Layout.Button>
    | (true, Some(user)) => <Navigation logout user />
    }}
    <React.Suspense
      fallback={<div className="flex flex-col items-center justify-center h-screen text-gray-600">
        <Icon.Movie /> {React.string("Loading")}
      </div>}>
      {switch path {
      | Feed => React.createElement(feedComp, ReactLazy.emptyObj())
      | AddMovie => React.createElement(addMovieComp, ReactLazy.emptyObj())
      | Movie(id) => React.createElement(movieComp, {"id": id})
      | Person(id) => React.createElement(personComp, {"id": id})
      | Search(query) => React.createElement(searchComp, {"query": query})
      }}
    </React.Suspense>
  </>
}

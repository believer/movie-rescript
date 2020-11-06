[@react.component]
let make = () => {
  let url = ReasonReactRouter.useUrl();
  let path = Router.Route.fromPath(url.path);
  let Auth0.{loginWithRedirect, isAuthenticated, logout, user} =
    Auth0.useAuth0();

  <>
    {switch (isAuthenticated, user) {
     | (false, _)
     | (true, None) =>
       <button onClick={_ => loginWithRedirect()}>
         {React.string("Log in")}
       </button>
     | (true, Some(user)) =>
       <div className="mt-8 grid grid-md">
         <div className="flex justify-between">
           <Link to_=Feed> {React.string("Movies")} </Link>
           <div className="flex">
             {switch (user.picture) {
              | Some(src) => <img className="w-8 h-8 mr-4 rounded-full" src />
              | None => React.null
              }}
             <button
               className="text-sm text-gray-700"
               onClick={_ => logout({returnTo: Web.origin})}>
               {React.string("Log out")}
             </button>
           </div>
         </div>
       </div>
     }}
    {switch (path) {
     | Feed => <FeedPage />
     | AddMovie => <AddMoviePage />
     | Movie(id) => <MoviePage id />
     | Person(id) => <PersonPage id />
     }}
  </>;
};

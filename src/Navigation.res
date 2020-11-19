module Menu = {
  type t = Open | Closed
}

@react.component
let make = (~logout: Auth0.logout => unit, ~user: Auth0.user) => {
  let (displayMenu, setDisplayMenu) = React.useState(() => Menu.Closed)

  let handleClickOutside = _ => {
    setDisplayMenu(_ => Menu.Closed)
  }

  let divRef = Hooks.useClickOutside(handleClickOutside)

  <div className="mt-8 grid grid-md">
    <div className="flex col-start-3 col-end-3 items-center">
      <Link to_=Feed> <Icon.Movie /> </Link>
      <div className="ml-8">
        <Router.Link to_=AddMovie> {React.string("Add movie")} </Router.Link>
      </div>
      <div className="flex ml-auto relative">
        {switch user.picture {
        | Some(src) =>
          <img className="cursor-pointer w-8 h-8 rounded-full" src onClick={_ => setDisplayMenu(_ =>
                switch displayMenu {
                | Open => Closed
                | Closed => Open
                }
              )} />
        | None => React.null
        }}
        {switch displayMenu {
        | Open =>
          <div
            className="absolute bg-white border left mt-2 p-4 rounded-md
          shadow-lg w-24 z-10"
            ref={ReactDOM.Ref.domRef(divRef)}
            style={ReactDOMStyle.make(~top="100%", ~left="50%", ~transform="translateX(-50%)", ())}>
            <button
              className="text-sm text-gray-700 text-center w-full"
              onClick={_ => logout({returnTo: Web.origin})}>
              {React.string("Log out")}
            </button>
          </div>
        | Closed => React.null
        }}
      </div>
    </div>
  </div>
}

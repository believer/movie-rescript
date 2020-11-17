module Provider = {
  @react.component @bs.module("@auth0/auth0-react")
  external make: (
    ~children: React.element,
    ~domain: string,
    ~clientId: string,
    ~redirectUri: string,
    ~audience: string,
  ) => React.element = "Auth0Provider"
}

type logout = {returnTo: string}

type user = {
  name: string,
  email: string,
  picture: option<string>,
}

type useAuth<'a> = {
  getAccessTokenSilently: unit => Js.Promise.t<'a>,
  user: option<user>,
  isLoading: bool,
  isAuthenticated: bool,
  loginWithRedirect: unit => unit,
  logout: logout => unit,
}

@bs.module("@auth0/auth0-react")
external useAuth0: unit => useAuth<'a> = "useAuth0"

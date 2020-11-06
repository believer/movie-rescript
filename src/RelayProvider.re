[@react.component]
let make = (~children) => {
  let Auth0.{
        isLoading,
        getAccessTokenSilently,
        loginWithRedirect,
        isAuthenticated,
      } =
    Auth0.useAuth0();

  switch (isLoading, isAuthenticated) {
  | (true, _) =>
    <div
      className="flex flex-col items-center justify-center h-screen text-gray-600">
      <Icon.Movie />
      {React.string("Loading")}
    </div>
  | (false, false) =>
    <div className="flex items-center justify-center h-screen">
      <button onClick={_ => loginWithRedirect()}>
        {React.string("Log in")}
      </button>
    </div>
  | (false, true) =>
    <ReasonRelay.Context.Provider
      environment={RelayEnv.environment(getAccessTokenSilently)}>
      children
    </ReasonRelay.Context.Provider>
  };
};

[@react.component]
let make = (~children) => {
  let Auth0.{getAccessTokenSilently, loginWithRedirect, isAuthenticated} =
    Auth0.useAuth0();

  switch (isAuthenticated) {
  | false =>
    <div className="flex items-center justify-center h-screen">
      <button onClick={_ => loginWithRedirect()}>
        {React.string("Log in")}
      </button>
    </div>
  | true =>
    <ReasonRelay.Context.Provider
      environment={RelayEnv.environment(getAccessTokenSilently)}>
      children
    </ReasonRelay.Context.Provider>
  };
};

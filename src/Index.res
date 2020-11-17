ReactExperimental.renderConcurrentRootAtElementWithId(
  <Auth0.Provider
    domain="believer.eu.auth0.com"
    clientId="nPxC7G7y7S4fdDnKK9U5o65KkZn07Yxc"
    redirectUri=Web.origin
    audience="https://believer.eu.auth0.com/api/v2/">
    <RelayProvider>
      <React.Suspense
        fallback={<div className="flex flex-col items-center justify-center h-screen text-gray-600">
          <Icon.Movie /> {React.string("Loading")}
        </div>}>
        <App />
      </React.Suspense>
    </RelayProvider>
  </Auth0.Provider>,
  "root",
)

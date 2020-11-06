ReactExperimental.renderConcurrentRootAtElementWithId(
  <Auth0.Provider
    domain="believer.eu.auth0.com"
    clientId="nPxC7G7y7S4fdDnKK9U5o65KkZn07Yxc"
    redirectUri=Web.origin
    audience="https://believer.eu.auth0.com/api/v2/">
    <RelayProvider>
      <React.Suspense
        fallback={
          <div
            className="flex flex-col items-center justify-center h-screen text-gray-600">
            <svg
              className="w-6 h-6 mb- mb-44"
              xmlns="http://www.w3.org/2000/svg"
              fill="none"
              viewBox="0 0 24 24"
              stroke="currentColor">
              <path
                strokeLinecap="round"
                strokeLinejoin="round"
                strokeWidth="2"
                d="M7 4v16M17 4v16M3 8h4m10 0h4M3 12h18M3 16h4m10 0h4M4 20h16a1 1 0 001-1V5a1 1 0 00-1-1H4a1 1 0 00-1 1v14a1 1 0 001 1z"
              />
            </svg>
            {React.string("Loading")}
          </div>
        }>
        <App />
      </React.Suspense>
    </RelayProvider>
  </Auth0.Provider>,
  "root",
);

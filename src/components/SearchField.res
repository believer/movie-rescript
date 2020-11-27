@react.component
let make = () => {
  let url = ReasonReactRouter.useUrl()
  let path = Router.Route.fromPath(url.path)
  let (searchQuery, setSearchQuery) = React.useState(() => {
    switch path {
    | Search(query) => query
    | Feed | AddMovie | Movie(_) | Person(_) => ""
    }
  })

  let onSubmit = e => {
    e->ReactEvent.Form.preventDefault
    Router.Route.go(Search(searchQuery))
  }

  <form
    className="flex focus-within:text-indigo-500 items-center mr-4 relative rounded text-gray-500"
    onSubmit>
    <div className="absolute left-2 pointer-events-none"> <Icon.Search /> </div>
    <input
      className="pl-8 px-4 py-1 focus:ring-2 focus:outline-none focus:ring-offset-1 focus:ring-indigo-300 rounded border-2 border-gray-300
      text-gray-800"
      onChange={e => {
        let value = (e->ReactEvent.Form.target)["value"]
        setSearchQuery(_ => value)
      }}
      type_="text"
      value={searchQuery}
    />
  </form>
}

module MovieOverviewFragment = %relay.fragment(
  `
  fragment MovieOverview_movie on movie {
    overview
  }
`
)

@react.component
let make = (~movie) => {
  let data = MovieOverviewFragment.use(movie)

  <>
    <h2 className="flex items-center mb-4 text-lg font-bold">
      {React.string("Synopsis")} <hr className="flex-1 ml-8" />
    </h2>
    {switch data.overview {
    | Some(overview) =>
      <div className="mb-8"> <Layout.Paragraph> {React.string(overview)} </Layout.Paragraph> </div>
    | None => React.null
    }}
  </>
}

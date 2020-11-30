module WatchDatesFragment = %relay.fragment(
  `
  fragment WatchDates_movie on movie {
    dates_watched {
      date
      id
    }
  }
`
)

module AddWatchMutation = %relay.mutation(
  `
  mutation WatchDatesMutation($id: Int!, $date: timestamp!) {
    insert_seen_one(object: {movie_id: $id, date: $date}) {
      id
    }
  }
`
)

@react.component
let make = (~id, ~movie) => {
  let data = WatchDatesFragment.use(movie)
  let (mutate, _isMutating) = AddWatchMutation.use()

  <>
    <MovieSection title="Seen on dates">
      {data.dates_watched
      ->Belt.Array.map(watch =>
        <div key=watch.id>
          {Intl.DateTime.makeFromString(~date=watch.date, ~locale=Some("sv-SE"), ())->React.string}
        </div>
      )
      ->React.array}
    </MovieSection>
    {switch id {
    | Some(id) =>
      <button
        className="mb-8 bg-indigo-500 rounded text-white px-4 py-2 text-xs"
        onClick={_ => {
          mutate(
            ~variables={
              id: id,
              date: Js.Date.make()->Js.Date.toISOString,
            },
            (),
          )->ignore
        }}>
        {React.string("Add watch")}
      </button>
    | None => React.null
    }}
  </>
}

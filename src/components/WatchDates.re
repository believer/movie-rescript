module WatchDatesFragment = [%relay.fragment
  {|
  fragment WatchDates_movie on movie {
    dates_watched {
      date
      id
    }
  }
|}
];

[@react.component]
let make = (~movie) => {
  let data = WatchDatesFragment.use(movie);

  <MovieSection title="Seen on dates">
    {data.dates_watched
     ->Belt.Array.map(watch => {
         <div key={watch.id}>
           {Intl.DateTime.makeFromString(
              ~date=watch.date,
              ~locale=Some("sv-SE"),
              (),
            )
            ->React.string}
         </div>
       })
     ->React.array}
  </MovieSection>;
};

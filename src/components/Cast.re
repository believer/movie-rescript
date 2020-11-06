module CastFragment = [%relay.fragment
  {|
  fragment Cast_movie on movie {
    cast: movie_people(
      where: {job: {_eq: "cast"}},
      order_by: {person: {movie_people_aggregate: {count: desc}}}
    ) {
      person {
        id
        name
      }
    }
  }
|}
];

[@react.component]
let make = (~movie) => {
  let data = CastFragment.use(movie);

  <MovieSection length={Belt.Array.length(data.cast)} title="Cast">
    {data.cast
     ->Belt.Array.map(({person}) => {
         <li key={person.id}>
           <Link to_={Person(person.id)}> {React.string(person.name)} </Link>
         </li>
       })
     ->React.array}
  </MovieSection>;
};

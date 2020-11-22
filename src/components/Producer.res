module ProducerFragment = %relay.fragment(
  `
  fragment Producer_movie on movie {
    producer: movie_people(where: {job: {_eq: "producer"}}) {
      person {
        id
        name
      }
    }
  }
`
)

@react.component
let make = (~movie) => {
  let data = ProducerFragment.use(movie)

  <MovieSection title="Producer">
    {data.producer
    ->Belt.Array.map(({person}) =>
      <li key=person.id> <Link to_=Person(person.id)> {React.string(person.name)} </Link> </li>
    )
    ->React.array}
  </MovieSection>
}

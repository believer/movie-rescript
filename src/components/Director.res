module DirectorFragment = %relay.fragment(
  `
  fragment Director_movie on movie {
    director: movie_people(where: {job: {_eq: "director"}}) {
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
  let data = DirectorFragment.use(movie)

  <MovieSection title="Director">
    {data.director
    ->Belt.Array.map(({person}) =>
      <li key=person.id> <Link to_=Person(person.id)> {React.string(person.name)} </Link> </li>
    )
    ->React.array}
  </MovieSection>
}

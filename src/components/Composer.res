module ComposerFragment = %relay.fragment(
  `
  fragment Composer_movie on movie {
    composer: movie_people(where: {job: {_eq: "composer"}}) {
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
  let data = ComposerFragment.use(movie)

  <MovieSection title="Composer">
    {data.composer
    ->Belt.Array.map(({person}) =>
      <li key=person.id> <Link to_=Person(person.id)> {React.string(person.name)} </Link> </li>
    )
    ->React.array}
  </MovieSection>
}

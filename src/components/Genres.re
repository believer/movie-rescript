module GenresFragment = [%relay.fragment
  {|
  fragment Genres_movie on movie {
    genres: movie_genres {
      genre {
        id
        name
      }
    }
  }
|}
];

[@react.component]
let make = (~movie, ~numberOfGenres=3) => {
  let data = GenresFragment.use(movie);

  <div>
    {data.genres
     ->Belt.Array.keepWithIndex((_, i) => i < numberOfGenres)
     ->Belt.Array.map(({genre}) => genre.name)
     ->Js.Array2.joinWith(" | ")
     ->React.string}
  </div>;
};

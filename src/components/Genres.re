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
let make = (~movie) => {
  let data = GenresFragment.use(movie);

  <div>
    {data.genres
     ->Belt.Array.keepWithIndex((_, i) => i < 3)
     ->Belt.Array.map(({genre}) => genre.name)
     ->Js.Array2.joinWith(" | ")
     ->React.string}
  </div>;
};

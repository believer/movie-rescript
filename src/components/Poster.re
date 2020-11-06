module PosterFragment = [%relay.fragment
  {|
  fragment Poster_movie on movie {
    poster
  }
|}
];

[@react.component]
let make = (~movie) => {
  let data = PosterFragment.use(movie);

  switch (data.poster) {
  | Some(poster) =>
    <img
      className="rounded-md transform hover:scale-105 transition-transform duration-150 ease-in-out"
      src={"https://image.tmdb.org/t/p/w500" ++ poster}
    />
  | None => React.null
  };
};

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
    <div className="relative">
      <img
        className="relative z-10 rounded transform hover:scale-105 transition-transform duration-150 ease-in-out"
        src={"https://image.tmdb.org/t/p/w500" ++ poster}
      />
      <img
        className="absolute rounded"
        src={"https://image.tmdb.org/t/p/w500" ++ poster}
        style={ReactDOMStyle.make(
          ~top="12px",
          ~filter="blur(20px)",
          ~transform="scale(0.9)",
          (),
        )}
      />
    </div>
  | None => React.null
  };
};

module MovieQuery = [%relay.query
  {|
  query MoviePageQuery($id: ID!, $genreLimit: Int!) {
    movie: node(id: $id) {
      __typename
      ... on movie {
        id
        title
        ...MovieOverview_movie
        ...Cast_movie
        ...Composer_movie
        ...Director_movie
        ...Producer_movie
        ...Poster_movie
        ...Ratings_movie
        ...MovieMeta_movie
        ...Genres_movie @arguments(genreLimit: $genreLimit)
        ...WatchDates_movie
      }
    }
  }
|}
];

[@react.component]
let make = (~id) => {
  let data = MovieQuery.use(~variables={id, genreLimit: 10}, ());

  switch (data.movie) {
  | Some(`movie({title, fragmentRefs})) =>
    <>
      <div className="my-8 grid grid-md">
        <div className="grid grid-movie grid-gap-8">
          <Poster movie=fragmentRefs />
          <div>
            <h1 className="flex justify-between mb-2 text-4xl font-bold">
              {React.string(title)}
              <Rating movie=fragmentRefs size=Rating.Large />
            </h1>
            <MovieMeta movie=fragmentRefs />
            <MovieOverview movie=fragmentRefs />
            <WatchDates movie=fragmentRefs />
            <Director movie=fragmentRefs />
            <Producer movie=fragmentRefs />
            <Composer movie=fragmentRefs />
            <Cast movie=fragmentRefs />
          </div>
        </div>
      </div>
    </>
  | _ => React.null
  };
};

let default = make;

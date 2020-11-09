module MovieQuery = [%relay.query
  {|
  query MoviePageQuery($id: ID!, $genreLimit: Int!) {
    movie: node(id: $id) {
      __typename
      ... on movie {
        id
        overview
        title
        ...Cast_movie
        ...Composer_movie
        ...Director_movie
        ...Producer_movie
        ...Poster_movie
        ...Ratings_movie
        ...MovieMeta_movie
        ...Genres_movie @arguments(genreLimit: $genreLimit)
      }
    }
  }
|}
];

[@react.component]
let make = (~id) => {
  let data = MovieQuery.use(~variables={id, genreLimit: 10}, ());

  switch (data.movie) {
  | Some(`movie({overview, title, fragmentRefs})) =>
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
            <h2 className="flex items-center mb-4 text-lg font-bold">
              {React.string("Synopsis")}
              <hr className="flex-1 ml-8" />
            </h2>
            {switch (overview) {
             | Some(overview) =>
               <div className="mb-8">
                 <Layout.Paragraph>
                   {React.string(overview)}
                 </Layout.Paragraph>
               </div>
             | None => React.null
             }}
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

module MovieMetaFragment = [%relay.fragment
  {|
  fragment MovieMeta_movie on movie {
    imdb_id
    release_date
    runtime
    tagline
  }
|}
];

[@react.component]
let make = (~movie) => {
  let data = MovieMetaFragment.use(movie);

  <div className="mb-8 text-sm text-gray-600 space-y-1">
    {switch (data.tagline) {
     | Some(tagline) =>
       <div className="text-gray-700"> {React.string(tagline)} </div>
     | None => React.null
     }}
    <div className="flex space-x-1">
      {switch (data.release_date) {
       | Some(releaseDate) =>
         <>
           <div> {React.string(releaseDate)} </div>
           <div> {React.string({j|\u2022|j})} </div>
         </>
       | None => React.null
       }}
      <Runtime runtime={data.runtime} />
      <div> {React.string({j|\u2022|j})} </div>
      <Genres movie />
      <div> {React.string({j|\u2022|j})} </div>
      <a
        className="text-yellow-800"
        href={"https://www.imdb.com/title/" ++ data.imdb_id}
        target="_blank"
        rel="noreferrer noopener">
        {React.string("IMDb")}
      </a>
    </div>
  </div>;
};

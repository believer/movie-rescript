module MovieMetaFragment = %relay.fragment(`
  fragment MovieMeta_movie on movie {
    imdb_id
    release_date
    runtime
    tagline
  }
`)

module Bullet = {
  @react.component
  let make = () => <div className="hidden md:block"> {React.string(j`\\u2022`)} </div>
}

@react.component
let make = (~movie) => {
  let data = MovieMetaFragment.use(movie)

  <div className="mb-8 text-sm text-gray-600 space-y-1">
    {switch data.tagline {
    | Some(tagline) => <div className="text-gray-800"> {React.string(tagline)} </div>
    | None => React.null
    }}
    <div className="flex flex-col md:flex-row md:space-x-1">
      {switch data.release_date {
      | Some(releaseDate) => <> <div> {React.string(releaseDate)} </div> <Bullet /> </>
      | None => React.null
      }}
      <Runtime runtime=data.runtime />
      <Bullet />
      <Genres movie />
      <Bullet />
      <a
        className="text-yellow-800"
        href={"https://www.imdb.com/title/" ++ data.imdb_id}
        target="_blank"
        rel="noreferrer noopener">
        {React.string("IMDb")}
      </a>
    </div>
  </div>
}

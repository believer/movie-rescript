[@bs.val] external tmdbApiKey: string = "process.env.TMDB_API_KEY";

let baseUrl = "https://api.themoviedb.org/3";

type state('a) =
  | NotCalled
  | Loading
  | Error
  | NoData
  | Data('a);

module Movie = {
  module Credits = {
    module Cast = {
      type t = {
        id: int,
        name: string,
      };
    };

    module Crew = {
      type t = {
        department: string,
        id: int,
        job: string,
        name: string,
      };
    };

    type t = {
      cast: array(Cast.t),
      crew: array(Crew.t),
    };
  };

  module Genre = {
    type t = {name: string};
  };

  type t = {
    genres: array(Genre.t),
    imdb_id: option(string),
    overview: option(string),
    poster_path: option(string),
    release_date: string,
    runtime: option(int),
    tagline: option(string),
    title: string,
    credits: Credits.t,
  };
};

let useMovie = () => {
  let (movie, setMovie) = React.useState(() => NotCalled);

  let getMovie = id => {
    Request.make(
      ~url=baseUrl ++ "/movie/" ++ id ++ "?api_key=" ++ tmdbApiKey,
      ~responseType=JsonAsAny: Request.responseType(Movie.t),
      (),
    )
    ->Future.get(res =>
        switch (res) {
        | Ok({response}) =>
          switch (response) {
          | Some(movie) =>
            Request.make(
              ~url=
                baseUrl ++ "/movie/" ++ id ++ "/credits?api_key=" ++ tmdbApiKey,
              ~responseType=JsonAsAny: Request.responseType(Movie.Credits.t),
              (),
            )
            ->Future.get(res =>
                switch (res) {
                | Ok({response}) =>
                  switch (response) {
                  | Some(credits) => setMovie(_ => Data({...movie, credits}))
                  | None => setMovie(_ => NoData)
                  }
                | Error(_) => setMovie(_ => Error)
                }
              )
          | None => setMovie(_ => NoData)
          }
        | Error(_) => setMovie(_ => Error)
        }
      );
  };

  (movie, getMovie);
};

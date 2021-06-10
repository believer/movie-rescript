module PosterFragment = %relay(`
  fragment Poster_movie on movie {
    poster
  }
`)

type t = Feed

@react.component
let make = (~movie, ~size=?) => {
  let data = PosterFragment.use(movie)

  let sizeClass = switch size {
  | Some(Feed) => "md:h-full"
  | None => ""
  }

  switch data.poster {
  | Some(poster) =>
    <div className={Cn.fromList(list{"md:relative", sizeClass})}>
      <img
        className={Cn.fromList(list{
          "md:relative md:z-10 rounded transform md:hover:scale-105 transition-transform duration-150 ease-in-out object-fit",
          sizeClass,
        })}
        src={"https://image.tmdb.org/t/p/w500" ++ poster}
      />
      <img
        className={Cn.fromList(list{"absolute rounded object-fit hidden md:block", sizeClass})}
        src={"https://image.tmdb.org/t/p/w500" ++ poster}
        style={ReactDOMStyle.make(~top="12px", ~filter="blur(20px)", ~transform="scale(0.9)", ())}
      />
    </div>
  | None => React.null
  }
}

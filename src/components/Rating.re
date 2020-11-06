module RatingFragment = [%relay.fragment
  {|
  fragment Ratings_movie on movie {
    ratings {
      id
      rating
    }
  }
|}
];

type size =
  | Small
  | Large;

[@react.component]
let make = (~movie, ~size=Small) => {
  let data = RatingFragment.use(movie);

  let (iconSize, fontSize) =
    switch (size) {
    | Small => ("w-3 h-3", "text-xs")
    | Large => ("w-6 h-6", "text-3xl")
    };

  switch (data.ratings->Belt.Array.get(0)) {
  | Some({rating}) =>
    <div className=Cn.("flex items-center" + fontSize)>
      <svg
        className=Cn.("mr-1" + iconSize)
        xmlns="http://www.w3.org/2000/svg"
        fill="#F6AD55"
        viewBox="0 0 24 24"
        stroke="#F6AD55">
        <path
          strokeLinecap="round"
          strokeLinejoin="round"
          strokeWidth="2"
          d="M11.049 2.927c.3-.921 1.603-.921 1.902 0l1.519 4.674a1 1 0 00.95.69h4.915c.969 0 1.371 1.24.588 1.81l-3.976 2.888a1 1 0 00-.363 1.118l1.518 4.674c.3.922-.755 1.688-1.538 1.118l-3.976-2.888a1 1 0 00-1.176 0l-3.976 2.888c-.783.57-1.838-.197-1.538-1.118l1.518-4.674a1 1 0 00-.363-1.118l-3.976-2.888c-.784-.57-.38-1.81.588-1.81h4.914a1 1 0 00.951-.69l1.519-4.674z"
        />
      </svg>
      {React.int(rating)}
    </div>
  | None => React.null
  };
};

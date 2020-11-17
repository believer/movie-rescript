module PersonQuery = [%relay.query
  {|
  query PersonPageQuery($id: ID!) {
    node(id: $id) {
      __typename
      ... on person {
        id
        name
        jobs: movie_people(
          order_by: { movie: { release_date: desc } }
        ) {
          job
          movie {
            id
            title
            year
          }
        }
      }
    }
  }
|}
];

module PersonSection = {
  [@react.component]
  let make =
      (~moviesByJob: array(PersonQuery.Types.response_node_jobs), ~title) => {
    <MovieSection title>
      {moviesByJob
       ->Belt.Array.map(({movie}) => {
           <li key={movie.id}>
             <Link to_={Movie(movie.id)}> {React.string(movie.title)} </Link>
             {switch (movie.year) {
              | Some(year) =>
                <div className="text-xs text-gray-700">
                  {React.string(year)}
                </div>
              | None => React.null
              }}
           </li>
         })
       ->React.array}
    </MovieSection>;
  };
};

[@react.component]
let make = (~id) => {
  let data = PersonQuery.use(~variables={id: id}, ());

  switch (data.node) {
  | Some({name, jobs}) =>
    let cast = jobs->Belt.Array.keep(({job}) => job == Cast);
    let producer = jobs->Belt.Array.keep(({job}) => job == Producer);
    let director = jobs->Belt.Array.keep(({job}) => job == Director);
    let composer = jobs->Belt.Array.keep(({job}) => job == Composer);
    let writer = jobs->Belt.Array.keep(({job}) => job == Writer);

    <div className="my-8 grid grid-md">
      <div className="grid grid-person grid-gap-8">
        <h1 className="flex justify-between mb-2 text-4xl font-bold">
          {React.string(name)}
        </h1>
        <PersonSection moviesByJob=cast title="Cast" />
        <PersonSection moviesByJob=director title="Director" />
        <PersonSection moviesByJob=producer title="Producer" />
        <PersonSection moviesByJob=composer title="Composer" />
        <PersonSection moviesByJob=writer title="Writer" />
      </div>
    </div>;
  | _ => React.null
  };
};

let default = make;

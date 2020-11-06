module PersonQuery = [%relay.query
  {|
  query PersonPageQuery($id: ID!) {
    node(id: $id) {
      __typename
      ... on person {
        id
        name
        jobs: movie_people(order_by: {movie: {release_date: desc}}) {
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

[@react.component]
let make = (~id) => {
  let data = PersonQuery.use(~variables={id: id}, ());

  switch (data.node) {
  | Some({name, jobs}) =>
    <ul>
      {React.string(name)}
      {jobs
       ->Belt.Array.map(({job, movie}) => {
           <li key={movie.id}>
             <Router.Link to_={Movie(movie.id)}>
               {React.string(movie.title)}
             </Router.Link>
             <div className="text-xs text-gray-700">
               {React.string(Job.toString(job))}
             </div>
           </li>
         })
       ->React.array}
    </ul>
  | _ => React.null
  };
};

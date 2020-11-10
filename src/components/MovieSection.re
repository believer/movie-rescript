[@react.component]
let make = (~children, ~title) => {
  switch (React.Children.count(children)) {
  | 0 => React.null
  | _ =>
    <div className="mb-8">
      <h2 className="flex items-center mb-4 text-lg font-bold">
        {React.string(title)}
        <hr className="flex-1 ml-8" />
      </h2>
      <ul className="text-sm grid grid-cast grid-row-gap-2"> children </ul>
    </div>
  };
};

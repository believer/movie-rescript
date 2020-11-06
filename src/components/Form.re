module TextField = {
  [@react.component]
  let make = (~onChange, ~name, ~label, ~value) => {
    <div>
      <label className="block mb-1 text-sm font-bold" htmlFor=name>
        {React.string(label)}
      </label>
      <input
        className="block px-4 py-1 mr-4 border"
        id=name
        name
        type_="text"
        onChange
        value
      />
    </div>;
  };
};

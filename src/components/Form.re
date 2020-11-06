module TextField = {
  [@react.component]
  let make = (~onChange, ~name, ~label, ~value) => {
    <div>
      <label className="block mb-1 text-sm font-bold" htmlFor=name>
        {React.string(label)}
      </label>
      <input
        className="block w-full px-4 py-2 mr-4 bg-gray-100 border border-gray-300 rounded-sm"
        id=name
        name
        type_="text"
        onChange
        value
      />
    </div>;
  };
};

@react.component
let make = (~title) => {
  <h2 className="flex items-center mb-4 text-lg font-bold">
    {React.string(title)} <hr className="flex-1 ml-8" />
  </h2>
}

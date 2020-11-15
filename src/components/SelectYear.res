let years =
  Belt.Array.make(10, 2011)
  ->Belt.Array.mapWithIndex((i, year) => year + i)
  ->Belt.Array.map(string_of_int)
  ->Belt.Array.reverse

@react.component
let make = (~onChange) => {
  <div className="flex justify-end mb-8 relative">
    <select
      className="appearance-none bg-gray-200 px-4 md:pr-8 py-2 rounded w-full md:w-auto border
      border-gray-400"
      onChange={e => {
        let value = (e->ReactEvent.Form.target)["value"]
        onChange(value)
      }}>
      {years->Belt.Array.map(year => {
        <option key=year value=year> {React.string(year)} </option>
      })->React.array}
    </select>
    <div
      className="absolute inset-y-0 right-0 flex items-center px-2 text-gray-700 pointer-events-none">
      <svg className="w-4 h-4 fill-current" xmlns="http://www.w3.org/2000/svg" viewBox="0 0 20 20">
        <path d="M9.293 12.95l.707.707L15.657 8l-1.414-1.414L10 10.828 5.757 6.586 4.343 8z" />
      </svg>
    </div>
  </div>
}

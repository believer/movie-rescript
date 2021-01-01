let currentYear = Js.Date.make()->Js.Date.getFullYear
let startYear = 2011

let years =
  Belt.Array.make(int_of_float(currentYear) - startYear + 1, startYear)
  ->Belt.Array.mapWithIndex((i, year) => year + i)
  ->Belt.Array.map(string_of_int)
  ->Belt.Array.reverse

@react.component
let make = (~onChange) => {
  <div className="flex justify-end mb-8 relative">
    <select
      className="appearance-none border-gray-300 px-4 md:pr-8 py-2 rounded
      w-full md:w-auto border-2 focus:ring-2 focus:outline-none
      focus:ring-offset-1 focus:ring-indigo-300"
      onChange={e => {
        let value = (e->ReactEvent.Form.target)["value"]
        onChange(value)
      }}>
      {years
      ->Belt.Array.map(year => {
        <option key=year value=year> {React.string(year)} </option>
      })
      ->React.array}
    </select>
    <div
      className="absolute inset-y-0 right-0 flex items-center px-2 text-gray-700 pointer-events-none">
      <Icon.ChevronDown />
    </div>
  </div>
}

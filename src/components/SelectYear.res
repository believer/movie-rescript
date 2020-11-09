let years =
  Belt.Array.make(10, 2011)
  ->Belt.Array.mapWithIndex((i, year) => year + i)
  ->Belt.Array.map(string_of_int)
  ->Belt.Array.reverse

@react.component
let make = (~onChange) => {
  <div className="flex justify-end mb-8">
    <select
      onChange={e => {
        let value = (e->ReactEvent.Form.target)["value"]
        onChange(value)
      }}>
      {years->Belt.Array.map(year => {
        <option key=year value=year> {React.string(year)} </option>
      })->React.array}
    </select>
  </div>
}

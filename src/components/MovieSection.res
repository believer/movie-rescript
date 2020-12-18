@react.component
let make = (~children, ~title) => {
  switch React.Children.count(children) {
  | 0 => React.null
  | _ =>
    <div className="mb-8">
      <SectionHeader title /> <ul className="text-sm grid grid-cols-3 gap-y-2"> children </ul>
    </div>
  }
}

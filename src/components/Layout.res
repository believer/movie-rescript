module Paragraph = {
  @react.component
  let make = (~children) => <p className="text-sm text-gray-700"> children </p>
}

module Button = {
  @react.component
  let make = (~children, ~onClick, ~disabled=false) =>
    <button
      className="inline-block w-full px-5 py-2 mt-4 text-gray-100 bg-gray-900 rounded disabled:bg-gray-500"
      disabled
      onClick>
      children
    </button>
}

module Base = {
  type t = Movie | Person | AddMovie

  @react.component
  let make = (~grid: t, ~children) => {
    let gridStyle = switch grid {
    | Movie => "grid-movie gap-20"
    | Person => "grid-cols-1"
    | AddMovie => ""
    }

    <div className="my-8 grid grid-md">
      <div className={Cn.fromList(list{"grid gap-8 col-start-3 col-end-3", gridStyle})}>
        children
      </div>
    </div>
  }
}

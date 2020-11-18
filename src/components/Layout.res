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
  @react.component
  let make = (~grid=?, ~children) => {
    <div className="my-8 grid grid-md">
      <div
        className={Cn.fromList(list{
          "grid grid-gap-8",
          ("grid-" ++ grid->Belt.Option.getWithDefault(""))->Cn.onSome(grid),
        })}>
        children
      </div>
    </div>
  }
}

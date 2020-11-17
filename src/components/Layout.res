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

module Paragraph = {
  [@react.component]
  let make = (~children) => {
    <p className="text-sm text-gray-700"> children </p>;
  };
};

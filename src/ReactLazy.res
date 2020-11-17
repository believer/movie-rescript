@bs.val
external import_: string => Js.Promise.t<React.component<'props>> = "import"

@bs.module("react")
external lazy_: (unit => Js.Promise.t<React.component<'props>>) => React.component<'props> = "lazy"

@bs.new external emptyObj: unit => Js.t<{.}> = "Object"

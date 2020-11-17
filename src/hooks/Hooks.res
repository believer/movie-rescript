@bs.val external document: {..} = "document"
external elm: Dom.element => Js.t<'a> = "%identity"

let handleClickOutside = (domElement: Dom.element, e, fn) =>
  !(domElement->elm)["contains"](e["target"]) ? fn(e) : ()

let useClickOutside = onClickOutside => {
  let elementRef = React.useRef(Js.Nullable.null)

  let handleMouseDown = e => {
    elementRef.current
    ->Js.Nullable.toOption
    ->Belt.Option.map(refValue => handleClickOutside(refValue, e, onClickOutside))
    ->ignore
  }

  React.useEffect0(() => {
    document["addEventListener"]("mousedown", handleMouseDown)->ignore

    Some(() => document["removeMouseDownEventListener"]("mousedown", handleMouseDown))
  })

  elementRef
}

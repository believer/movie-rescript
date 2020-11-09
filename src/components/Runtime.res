@react.component
let make = (~runtime) => {
  let runtimeInHours = runtime->float_of_int /. 60.
  let hours = runtimeInHours->Js.Math.floor
  let minutes = Js.Math.round(mod_float(runtimeInHours, 1.0) *. 60.)->int_of_float

  <div>
    {switch (hours, minutes) {
    | (0, m) => m->string_of_int ++ " min"
    | (h, 0) => h->string_of_int ++ " h"
    | (h, m) => h->string_of_int ++ " h " ++ m->string_of_int ++ " min"
    } |> React.string}
  </div>
}

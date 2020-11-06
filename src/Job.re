type t =
  | Cast
  | Composer
  | Director
  | Producer
  | Writer;

let parse = job =>
  switch (Js.Json.stringify(job)) {
  | "\"cast\"" => Cast
  | "\"composer\"" => Composer
  | "\"director\"" => Director
  | "\"producer\"" => Producer
  | _ => Writer
  };

let serialize = job =>
  switch (job) {
  | Cast => Js.Json.parseExn("\"cast\"")
  | Composer => Js.Json.parseExn("\"composer\"")
  | Director => Js.Json.parseExn("\"director\"")
  | Producer => Js.Json.parseExn("\"producer\"")
  | Writer => Js.Json.parseExn("\"writer\"")
  };

let toString =
  fun
  | Cast => "cast"
  | Composer => "composer"
  | Director => "director"
  | Producer => "producer"
  | Writer => "writer";

let isValid = (department, job) =>
  switch (department, job) {
  | ("Writing", "Screenplay")
  | ("Sound", "Original Music Composer")
  | ("Production", "Producer")
  | ("Production", "Associate Producer")
  | ("Directing", "Director")
  | ("Cast", "Cast") => true
  | _ => false
  };

let parseTmdb = (department, job) =>
  switch (department, job) {
  | ("Writing", "Screenplay") => Some(Writer)
  | ("Sound", "Original Music Composer") => Some(Composer)
  | ("Production", "Producer") => Some(Producer)
  | ("Production", "Associate Producer") => Some(Producer)
  | ("Directing", "Director") => Some(Director)
  | ("Cast", "Cast") => Some(Cast)
  | _ => None
  };

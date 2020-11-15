/* @generated */

type enum_seen_update_column = pri [> | `date | `id | `movie_id];

type enum_seen_constraint = pri [> | `seen_pkey];

type enum_rating_update_column =
  pri [> | `created_at | `id | `movie_id | `rating | `updated_at];

type enum_rating_constraint = pri [> | `rating_pkey];

type enum_person_update_column = pri [> | `id | `name | `original_id];

type enum_person_constraint = pri [> | `person_original_id_key | `person_pkey];

type enum_movie_update_column =
  pri [>
    | `created_at
    | `id
    | `imdb_id
    | `imdb_rating
    | `overview
    | `poster
    | `release_date
    | `runtime
    | `tagline
    | `title
    | `updated_at
  ];

type enum_movie_person_update_column =
  pri [> | `id | `job | `movie_id | `person_id];

type enum_movie_person_constraint =
  pri [> | `movie_person_movie_id_person_id_job_key | `movie_person_pkey];

type enum_movie_genre_update_column = pri [> | `genre_id | `id | `movie_id];

type enum_movie_genre_constraint = pri [> | `movie_genre_pkey];

type enum_movie_constraint = pri [> | `movie_imdb_id_key | `movie_pkey];

type enum_genre_update_column = pri [> | `id | `name];

type enum_genre_constraint = pri [> | `genre_name_key | `genre_pkey];

module Types = {
  [@ocaml.warning "-30"];
  type response_insert_movie_one = {title: string}
  and movie_genre_insert_input = {
    genre: option(genre_obj_rel_insert_input),
    genre_id: option(int),
    id: option(int),
    movie_id: option(int),
  }
  and genre_obj_rel_insert_input = {
    data: genre_insert_input,
    on_conflict: option(genre_on_conflict),
  }
  and genre_insert_input = {
    id: option(int),
    name: option(string),
  }
  and genre_on_conflict = {
    [@bs.as "constraint"]
    constraint_: enum_genre_constraint,
    update_columns: array(enum_genre_update_column),
    where: option(genre_bool_exp),
  }
  and genre_bool_exp = {
    _and: option(array(option(genre_bool_exp))),
    _not: option(genre_bool_exp),
    _or: option(array(option(genre_bool_exp))),
    id: option(int_comparison_exp),
    name: option(string_comparison_exp),
  }
  and int_comparison_exp = {
    _eq: option(int),
    _gt: option(int),
    _gte: option(int),
    _in: option(array(int)),
    _is_null: option(bool),
    _lt: option(int),
    _lte: option(int),
    _neq: option(int),
    _nin: option(array(int)),
  }
  and string_comparison_exp = {
    _eq: option(string),
    _gt: option(string),
    _gte: option(string),
    _ilike: option(string),
    _in: option(array(string)),
    _is_null: option(bool),
    _like: option(string),
    _lt: option(string),
    _lte: option(string),
    _neq: option(string),
    _nilike: option(string),
    _nin: option(array(string)),
    _nlike: option(string),
    _nsimilar: option(string),
    _similar: option(string),
  }
  and movie_person_insert_input = {
    id: option(int),
    job: option(Job.t),
    movie: option(movie_obj_rel_insert_input),
    movie_id: option(int),
    person: option(person_obj_rel_insert_input),
    person_id: option(int),
  }
  and movie_obj_rel_insert_input = {
    data: movie_insert_input,
    on_conflict: option(movie_on_conflict),
  }
  and movie_insert_input = {
    created_at: option(string),
    dates_watched: option(seen_arr_rel_insert_input),
    id: option(int),
    imdb_id: option(string),
    imdb_rating: option(string),
    movie_genres: option(movie_genre_arr_rel_insert_input),
    movie_people: option(movie_person_arr_rel_insert_input),
    overview: option(string),
    poster: option(string),
    ratings: option(rating_arr_rel_insert_input),
    release_date: option(string),
    runtime: option(int),
    tagline: option(string),
    title: option(string),
    updated_at: option(string),
  }
  and seen_arr_rel_insert_input = {
    data: array(seen_insert_input),
    on_conflict: option(seen_on_conflict),
  }
  and seen_insert_input = {
    date: option(string),
    id: option(int),
    movie: option(movie_obj_rel_insert_input),
    movie_id: option(int),
  }
  and seen_on_conflict = {
    [@bs.as "constraint"]
    constraint_: enum_seen_constraint,
    update_columns: array(enum_seen_update_column),
    where: option(seen_bool_exp),
  }
  and seen_bool_exp = {
    _and: option(array(option(seen_bool_exp))),
    _not: option(seen_bool_exp),
    _or: option(array(option(seen_bool_exp))),
    date: option(timestamp_comparison_exp),
    id: option(int_comparison_exp),
    movie: option(movie_bool_exp),
    movie_id: option(int_comparison_exp),
  }
  and timestamp_comparison_exp = {
    _eq: option(string),
    _gt: option(string),
    _gte: option(string),
    _in: option(array(string)),
    _is_null: option(bool),
    _lt: option(string),
    _lte: option(string),
    _neq: option(string),
    _nin: option(array(string)),
  }
  and movie_bool_exp = {
    _and: option(array(option(movie_bool_exp))),
    _not: option(movie_bool_exp),
    _or: option(array(option(movie_bool_exp))),
    created_at: option(timestamp_comparison_exp),
    dates_watched: option(seen_bool_exp),
    id: option(int_comparison_exp),
    imdb_id: option(string_comparison_exp),
    imdb_rating: option(string_comparison_exp),
    movie_genres: option(movie_genre_bool_exp),
    movie_people: option(movie_person_bool_exp),
    overview: option(string_comparison_exp),
    poster: option(string_comparison_exp),
    ratings: option(rating_bool_exp),
    release_date: option(date_comparison_exp),
    runtime: option(int_comparison_exp),
    tagline: option(string_comparison_exp),
    title: option(string_comparison_exp),
    updated_at: option(timestamp_comparison_exp),
  }
  and movie_genre_bool_exp = {
    _and: option(array(option(movie_genre_bool_exp))),
    _not: option(movie_genre_bool_exp),
    _or: option(array(option(movie_genre_bool_exp))),
    genre: option(genre_bool_exp),
    genre_id: option(int_comparison_exp),
    id: option(int_comparison_exp),
    movie_id: option(int_comparison_exp),
  }
  and movie_person_bool_exp = {
    _and: option(array(option(movie_person_bool_exp))),
    _not: option(movie_person_bool_exp),
    _or: option(array(option(movie_person_bool_exp))),
    id: option(int_comparison_exp),
    job: option(job_comparison_exp),
    movie: option(movie_bool_exp),
    movie_id: option(int_comparison_exp),
    person: option(person_bool_exp),
    person_id: option(int_comparison_exp),
  }
  and job_comparison_exp = {
    _eq: option(Job.t),
    _gt: option(Job.t),
    _gte: option(Job.t),
    _in: option(array(Job.t)),
    _is_null: option(bool),
    _lt: option(Job.t),
    _lte: option(Job.t),
    _neq: option(Job.t),
    _nin: option(array(Job.t)),
  }
  and person_bool_exp = {
    _and: option(array(option(person_bool_exp))),
    _not: option(person_bool_exp),
    _or: option(array(option(person_bool_exp))),
    id: option(int_comparison_exp),
    movie_people: option(movie_person_bool_exp),
    name: option(string_comparison_exp),
    original_id: option(int_comparison_exp),
  }
  and rating_bool_exp = {
    _and: option(array(option(rating_bool_exp))),
    _not: option(rating_bool_exp),
    _or: option(array(option(rating_bool_exp))),
    created_at: option(timestamp_comparison_exp),
    id: option(int_comparison_exp),
    movie_id: option(int_comparison_exp),
    rating: option(int_comparison_exp),
    updated_at: option(timestamp_comparison_exp),
  }
  and date_comparison_exp = {
    _eq: option(string),
    _gt: option(string),
    _gte: option(string),
    _in: option(array(string)),
    _is_null: option(bool),
    _lt: option(string),
    _lte: option(string),
    _neq: option(string),
    _nin: option(array(string)),
  }
  and movie_genre_arr_rel_insert_input = {
    data: array(movie_genre_insert_input),
    on_conflict: option(movie_genre_on_conflict),
  }
  and movie_genre_on_conflict = {
    [@bs.as "constraint"]
    constraint_: enum_movie_genre_constraint,
    update_columns: array(enum_movie_genre_update_column),
    where: option(movie_genre_bool_exp),
  }
  and movie_person_arr_rel_insert_input = {
    data: array(movie_person_insert_input),
    on_conflict: option(movie_person_on_conflict),
  }
  and movie_person_on_conflict = {
    [@bs.as "constraint"]
    constraint_: enum_movie_person_constraint,
    update_columns: array(enum_movie_person_update_column),
    where: option(movie_person_bool_exp),
  }
  and rating_arr_rel_insert_input = {
    data: array(rating_insert_input),
    on_conflict: option(rating_on_conflict),
  }
  and rating_insert_input = {
    created_at: option(string),
    id: option(int),
    movie_id: option(int),
    rating: option(int),
    updated_at: option(string),
  }
  and rating_on_conflict = {
    [@bs.as "constraint"]
    constraint_: enum_rating_constraint,
    update_columns: array(enum_rating_update_column),
    where: option(rating_bool_exp),
  }
  and movie_on_conflict = {
    [@bs.as "constraint"]
    constraint_: enum_movie_constraint,
    update_columns: array(enum_movie_update_column),
    where: option(movie_bool_exp),
  }
  and person_obj_rel_insert_input = {
    data: person_insert_input,
    on_conflict: option(person_on_conflict),
  }
  and person_insert_input = {
    id: option(int),
    movie_people: option(movie_person_arr_rel_insert_input),
    name: option(string),
    original_id: option(int),
  }
  and person_on_conflict = {
    [@bs.as "constraint"]
    constraint_: enum_person_constraint,
    update_columns: array(enum_person_update_column),
    where: option(person_bool_exp),
  };

  type response = {insert_movie_one: option(response_insert_movie_one)};
  type rawResponse = response;
  type variables = {
    imdbId: option(string),
    overview: option(string),
    runtime: option(int),
    poster: option(string),
    releaseDate: option(string),
    tagline: option(string),
    title: option(string),
    rating: option(int),
    genres: array(movie_genre_insert_input),
    people: array(movie_person_insert_input),
    watchDates: array(seen_insert_input),
  };
};

module Internal = {
  type wrapResponseRaw;
  let wrapResponseConverter: Js.Dict.t(Js.Dict.t(Js.Dict.t(string))) = [%raw
    {json| {"__root":{"insert_movie_one":{"n":""}}} |json}
  ];
  let wrapResponseConverterMap = ();
  let convertWrapResponse = v =>
    v
    ->ReasonRelay._convertObj(
        wrapResponseConverter,
        wrapResponseConverterMap,
        Js.null,
      );

  type responseRaw;
  let responseConverter: Js.Dict.t(Js.Dict.t(Js.Dict.t(string))) = [%raw
    {json| {"__root":{"insert_movie_one":{"n":""}}} |json}
  ];
  let responseConverterMap = ();
  let convertResponse = v =>
    v
    ->ReasonRelay._convertObj(
        responseConverter,
        responseConverterMap,
        Js.undefined,
      );

  type wrapRawResponseRaw = wrapResponseRaw;
  let convertWrapRawResponse = convertWrapResponse;

  type rawResponseRaw = responseRaw;
  let convertRawResponse = convertResponse;

  let variablesConverter: Js.Dict.t(Js.Dict.t(Js.Dict.t(string))) = [%raw
    {json| {"__root":{"imdbId":{"n":""},"overview":{"n":""},"runtime":{"n":""},"poster":{"n":""},"releaseDate":{"n":""},"tagline":{"n":""},"title":{"n":""},"rating":{"n":""},"genres":{"r":"movie_genre_insert_input"},"people":{"r":"movie_person_insert_input"},"watchDates":{"r":"seen_insert_input"}},"Int_comparison_exp":{"_eq":{"n":""},"_gt":{"n":""},"_gte":{"n":""},"_in":{"n":""},"_is_null":{"n":""},"_lt":{"n":""},"_lte":{"n":""},"_neq":{"n":""},"_nin":{"n":""}},"String_comparison_exp":{"_eq":{"n":""},"_gt":{"n":""},"_gte":{"n":""},"_ilike":{"n":""},"_in":{"n":""},"_is_null":{"n":""},"_like":{"n":""},"_lt":{"n":""},"_lte":{"n":""},"_neq":{"n":""},"_nilike":{"n":""},"_nin":{"n":""},"_nlike":{"n":""},"_nsimilar":{"n":""},"_similar":{"n":""}},"date_comparison_exp":{"_eq":{"n":""},"_gt":{"n":""},"_gte":{"n":""},"_in":{"n":""},"_is_null":{"n":""},"_lt":{"n":""},"_lte":{"n":""},"_neq":{"n":""},"_nin":{"n":""}},"genre_bool_exp":{"_and":{"n":"","na":"","r":"genre_bool_exp"},"_not":{"n":"","r":"genre_bool_exp"},"_or":{"n":"","na":"","r":"genre_bool_exp"},"id":{"n":"","r":"Int_comparison_exp"},"name":{"n":"","r":"String_comparison_exp"}},"genre_insert_input":{"id":{"n":""},"name":{"n":""}},"genre_obj_rel_insert_input":{"data":{"r":"genre_insert_input"},"on_conflict":{"n":"","r":"genre_on_conflict"}},"genre_on_conflict":{"where":{"n":"","r":"genre_bool_exp"}},"job_comparison_exp":{"_eq":{"n":"","c":"Job"},"_gt":{"n":"","c":"Job"},"_gte":{"n":"","c":"Job"},"_in":{"n":"","c":"Job"},"_is_null":{"n":""},"_lt":{"n":"","c":"Job"},"_lte":{"n":"","c":"Job"},"_neq":{"n":"","c":"Job"},"_nin":{"n":"","c":"Job"}},"movie_bool_exp":{"_and":{"n":"","na":"","r":"movie_bool_exp"},"_not":{"n":"","r":"movie_bool_exp"},"_or":{"n":"","na":"","r":"movie_bool_exp"},"created_at":{"n":"","r":"timestamp_comparison_exp"},"dates_watched":{"n":"","r":"seen_bool_exp"},"id":{"n":"","r":"Int_comparison_exp"},"imdb_id":{"n":"","r":"String_comparison_exp"},"imdb_rating":{"n":"","r":"String_comparison_exp"},"movie_genres":{"n":"","r":"movie_genre_bool_exp"},"movie_people":{"n":"","r":"movie_person_bool_exp"},"overview":{"n":"","r":"String_comparison_exp"},"poster":{"n":"","r":"String_comparison_exp"},"ratings":{"n":"","r":"rating_bool_exp"},"release_date":{"n":"","r":"date_comparison_exp"},"runtime":{"n":"","r":"Int_comparison_exp"},"tagline":{"n":"","r":"String_comparison_exp"},"title":{"n":"","r":"String_comparison_exp"},"updated_at":{"n":"","r":"timestamp_comparison_exp"}},"movie_genre_arr_rel_insert_input":{"data":{"r":"movie_genre_insert_input"},"on_conflict":{"n":"","r":"movie_genre_on_conflict"}},"movie_genre_bool_exp":{"_and":{"n":"","na":"","r":"movie_genre_bool_exp"},"_not":{"n":"","r":"movie_genre_bool_exp"},"_or":{"n":"","na":"","r":"movie_genre_bool_exp"},"genre":{"n":"","r":"genre_bool_exp"},"genre_id":{"n":"","r":"Int_comparison_exp"},"id":{"n":"","r":"Int_comparison_exp"},"movie_id":{"n":"","r":"Int_comparison_exp"}},"movie_genre_insert_input":{"genre":{"n":"","r":"genre_obj_rel_insert_input"},"genre_id":{"n":""},"id":{"n":""},"movie_id":{"n":""}},"movie_genre_on_conflict":{"where":{"n":"","r":"movie_genre_bool_exp"}},"movie_insert_input":{"created_at":{"n":""},"dates_watched":{"n":"","r":"seen_arr_rel_insert_input"},"id":{"n":""},"imdb_id":{"n":""},"imdb_rating":{"n":""},"movie_genres":{"n":"","r":"movie_genre_arr_rel_insert_input"},"movie_people":{"n":"","r":"movie_person_arr_rel_insert_input"},"overview":{"n":""},"poster":{"n":""},"ratings":{"n":"","r":"rating_arr_rel_insert_input"},"release_date":{"n":""},"runtime":{"n":""},"tagline":{"n":""},"title":{"n":""},"updated_at":{"n":""}},"movie_obj_rel_insert_input":{"data":{"r":"movie_insert_input"},"on_conflict":{"n":"","r":"movie_on_conflict"}},"movie_on_conflict":{"where":{"n":"","r":"movie_bool_exp"}},"movie_person_arr_rel_insert_input":{"data":{"r":"movie_person_insert_input"},"on_conflict":{"n":"","r":"movie_person_on_conflict"}},"movie_person_bool_exp":{"_and":{"n":"","na":"","r":"movie_person_bool_exp"},"_not":{"n":"","r":"movie_person_bool_exp"},"_or":{"n":"","na":"","r":"movie_person_bool_exp"},"id":{"n":"","r":"Int_comparison_exp"},"job":{"n":"","r":"job_comparison_exp"},"movie":{"n":"","r":"movie_bool_exp"},"movie_id":{"n":"","r":"Int_comparison_exp"},"person":{"n":"","r":"person_bool_exp"},"person_id":{"n":"","r":"Int_comparison_exp"}},"movie_person_insert_input":{"id":{"n":""},"job":{"n":"","c":"Job"},"movie":{"n":"","r":"movie_obj_rel_insert_input"},"movie_id":{"n":""},"person":{"n":"","r":"person_obj_rel_insert_input"},"person_id":{"n":""}},"movie_person_on_conflict":{"where":{"n":"","r":"movie_person_bool_exp"}},"person_bool_exp":{"_and":{"n":"","na":"","r":"person_bool_exp"},"_not":{"n":"","r":"person_bool_exp"},"_or":{"n":"","na":"","r":"person_bool_exp"},"id":{"n":"","r":"Int_comparison_exp"},"movie_people":{"n":"","r":"movie_person_bool_exp"},"name":{"n":"","r":"String_comparison_exp"},"original_id":{"n":"","r":"Int_comparison_exp"}},"person_insert_input":{"id":{"n":""},"movie_people":{"n":"","r":"movie_person_arr_rel_insert_input"},"name":{"n":""},"original_id":{"n":""}},"person_obj_rel_insert_input":{"data":{"r":"person_insert_input"},"on_conflict":{"n":"","r":"person_on_conflict"}},"person_on_conflict":{"where":{"n":"","r":"person_bool_exp"}},"rating_arr_rel_insert_input":{"data":{"r":"rating_insert_input"},"on_conflict":{"n":"","r":"rating_on_conflict"}},"rating_bool_exp":{"_and":{"n":"","na":"","r":"rating_bool_exp"},"_not":{"n":"","r":"rating_bool_exp"},"_or":{"n":"","na":"","r":"rating_bool_exp"},"created_at":{"n":"","r":"timestamp_comparison_exp"},"id":{"n":"","r":"Int_comparison_exp"},"movie_id":{"n":"","r":"Int_comparison_exp"},"rating":{"n":"","r":"Int_comparison_exp"},"updated_at":{"n":"","r":"timestamp_comparison_exp"}},"rating_insert_input":{"created_at":{"n":""},"id":{"n":""},"movie_id":{"n":""},"rating":{"n":""},"updated_at":{"n":""}},"rating_on_conflict":{"where":{"n":"","r":"rating_bool_exp"}},"seen_arr_rel_insert_input":{"data":{"r":"seen_insert_input"},"on_conflict":{"n":"","r":"seen_on_conflict"}},"seen_bool_exp":{"_and":{"n":"","na":"","r":"seen_bool_exp"},"_not":{"n":"","r":"seen_bool_exp"},"_or":{"n":"","na":"","r":"seen_bool_exp"},"date":{"n":"","r":"timestamp_comparison_exp"},"id":{"n":"","r":"Int_comparison_exp"},"movie":{"n":"","r":"movie_bool_exp"},"movie_id":{"n":"","r":"Int_comparison_exp"}},"seen_insert_input":{"date":{"n":""},"id":{"n":""},"movie":{"n":"","r":"movie_obj_rel_insert_input"},"movie_id":{"n":""}},"seen_on_conflict":{"where":{"n":"","r":"seen_bool_exp"}},"timestamp_comparison_exp":{"_eq":{"n":""},"_gt":{"n":""},"_gte":{"n":""},"_in":{"n":""},"_is_null":{"n":""},"_lt":{"n":""},"_lte":{"n":""},"_neq":{"n":""},"_nin":{"n":""}}} |json}
  ];
  let variablesConverterMap = {"Job": Job.serialize};
  let convertVariables = v =>
    v
    ->ReasonRelay._convertObj(
        variablesConverter,
        variablesConverterMap,
        Js.undefined,
      );
};

module Utils = {
  external seen_update_column_toString: enum_seen_update_column => string =
    "%identity";
  external seen_constraint_toString: enum_seen_constraint => string =
    "%identity";
  external rating_update_column_toString: enum_rating_update_column => string =
    "%identity";
  external rating_constraint_toString: enum_rating_constraint => string =
    "%identity";
  external person_update_column_toString: enum_person_update_column => string =
    "%identity";
  external person_constraint_toString: enum_person_constraint => string =
    "%identity";
  external movie_update_column_toString: enum_movie_update_column => string =
    "%identity";
  external movie_person_update_column_toString:
    enum_movie_person_update_column => string =
    "%identity";
  external movie_person_constraint_toString:
    enum_movie_person_constraint => string =
    "%identity";
  external movie_genre_update_column_toString:
    enum_movie_genre_update_column => string =
    "%identity";
  external movie_genre_constraint_toString:
    enum_movie_genre_constraint => string =
    "%identity";
  external movie_constraint_toString: enum_movie_constraint => string =
    "%identity";
  external genre_update_column_toString: enum_genre_update_column => string =
    "%identity";
  external genre_constraint_toString: enum_genre_constraint => string =
    "%identity";
  open Types;
  let make_person_on_conflict =
      (~constraint_, ~update_columns, ~where=?, ()): person_on_conflict => {
    constraint_,
    update_columns,
    where,
  };

  let make_person_insert_input =
      (~id=?, ~movie_people=?, ~name=?, ~original_id=?, ())
      : person_insert_input => {
    id,
    movie_people,
    name,
    original_id,
  };

  let make_person_obj_rel_insert_input =
      (~data, ~on_conflict=?, ()): person_obj_rel_insert_input => {
    data,
    on_conflict,
  };

  let make_movie_on_conflict =
      (~constraint_, ~update_columns, ~where=?, ()): movie_on_conflict => {
    constraint_,
    update_columns,
    where,
  };

  let make_rating_on_conflict =
      (~constraint_, ~update_columns, ~where=?, ()): rating_on_conflict => {
    constraint_,
    update_columns,
    where,
  };

  let make_rating_insert_input =
      (~created_at=?, ~id=?, ~movie_id=?, ~rating=?, ~updated_at=?, ())
      : rating_insert_input => {
    created_at,
    id,
    movie_id,
    rating,
    updated_at,
  };

  let make_rating_arr_rel_insert_input =
      (~data, ~on_conflict=?, ()): rating_arr_rel_insert_input => {
    data,
    on_conflict,
  };

  let make_movie_person_on_conflict =
      (~constraint_, ~update_columns, ~where=?, ()): movie_person_on_conflict => {
    constraint_,
    update_columns,
    where,
  };

  let make_movie_person_arr_rel_insert_input =
      (~data, ~on_conflict=?, ()): movie_person_arr_rel_insert_input => {
    data,
    on_conflict,
  };

  let make_movie_genre_on_conflict =
      (~constraint_, ~update_columns, ~where=?, ()): movie_genre_on_conflict => {
    constraint_,
    update_columns,
    where,
  };

  let make_movie_genre_arr_rel_insert_input =
      (~data, ~on_conflict=?, ()): movie_genre_arr_rel_insert_input => {
    data,
    on_conflict,
  };

  let make_date_comparison_exp =
      (
        ~_eq=?,
        ~_gt=?,
        ~_gte=?,
        ~_in=?,
        ~_is_null=?,
        ~_lt=?,
        ~_lte=?,
        ~_neq=?,
        ~_nin=?,
        (),
      )
      : date_comparison_exp => {
    _eq,
    _gt,
    _gte,
    _in,
    _is_null,
    _lt,
    _lte,
    _neq,
    _nin,
  };

  let make_rating_bool_exp =
      (
        ~_and=?,
        ~_not=?,
        ~_or=?,
        ~created_at=?,
        ~id=?,
        ~movie_id=?,
        ~rating=?,
        ~updated_at=?,
        (),
      )
      : rating_bool_exp => {
    _and,
    _not,
    _or,
    created_at,
    id,
    movie_id,
    rating,
    updated_at,
  };

  let make_person_bool_exp =
      (
        ~_and=?,
        ~_not=?,
        ~_or=?,
        ~id=?,
        ~movie_people=?,
        ~name=?,
        ~original_id=?,
        (),
      )
      : person_bool_exp => {
    _and,
    _not,
    _or,
    id,
    movie_people,
    name,
    original_id,
  };

  let make_job_comparison_exp =
      (
        ~_eq=?,
        ~_gt=?,
        ~_gte=?,
        ~_in=?,
        ~_is_null=?,
        ~_lt=?,
        ~_lte=?,
        ~_neq=?,
        ~_nin=?,
        (),
      )
      : job_comparison_exp => {
    _eq,
    _gt,
    _gte,
    _in,
    _is_null,
    _lt,
    _lte,
    _neq,
    _nin,
  };

  let make_movie_person_bool_exp =
      (
        ~_and=?,
        ~_not=?,
        ~_or=?,
        ~id=?,
        ~job=?,
        ~movie=?,
        ~movie_id=?,
        ~person=?,
        ~person_id=?,
        (),
      )
      : movie_person_bool_exp => {
    _and,
    _not,
    _or,
    id,
    job,
    movie,
    movie_id,
    person,
    person_id,
  };

  let make_movie_genre_bool_exp =
      (
        ~_and=?,
        ~_not=?,
        ~_or=?,
        ~genre=?,
        ~genre_id=?,
        ~id=?,
        ~movie_id=?,
        (),
      )
      : movie_genre_bool_exp => {
    _and,
    _not,
    _or,
    genre,
    genre_id,
    id,
    movie_id,
  };

  let make_movie_bool_exp =
      (
        ~_and=?,
        ~_not=?,
        ~_or=?,
        ~created_at=?,
        ~dates_watched=?,
        ~id=?,
        ~imdb_id=?,
        ~imdb_rating=?,
        ~movie_genres=?,
        ~movie_people=?,
        ~overview=?,
        ~poster=?,
        ~ratings=?,
        ~release_date=?,
        ~runtime=?,
        ~tagline=?,
        ~title=?,
        ~updated_at=?,
        (),
      )
      : movie_bool_exp => {
    _and,
    _not,
    _or,
    created_at,
    dates_watched,
    id,
    imdb_id,
    imdb_rating,
    movie_genres,
    movie_people,
    overview,
    poster,
    ratings,
    release_date,
    runtime,
    tagline,
    title,
    updated_at,
  };

  let make_timestamp_comparison_exp =
      (
        ~_eq=?,
        ~_gt=?,
        ~_gte=?,
        ~_in=?,
        ~_is_null=?,
        ~_lt=?,
        ~_lte=?,
        ~_neq=?,
        ~_nin=?,
        (),
      )
      : timestamp_comparison_exp => {
    _eq,
    _gt,
    _gte,
    _in,
    _is_null,
    _lt,
    _lte,
    _neq,
    _nin,
  };

  let make_seen_bool_exp =
      (~_and=?, ~_not=?, ~_or=?, ~date=?, ~id=?, ~movie=?, ~movie_id=?, ())
      : seen_bool_exp => {
    _and,
    _not,
    _or,
    date,
    id,
    movie,
    movie_id,
  };

  let make_seen_on_conflict =
      (~constraint_, ~update_columns, ~where=?, ()): seen_on_conflict => {
    constraint_,
    update_columns,
    where,
  };

  let make_seen_insert_input =
      (~date=?, ~id=?, ~movie=?, ~movie_id=?, ()): seen_insert_input => {
    date,
    id,
    movie,
    movie_id,
  };

  let make_seen_arr_rel_insert_input =
      (~data, ~on_conflict=?, ()): seen_arr_rel_insert_input => {
    data,
    on_conflict,
  };

  let make_movie_insert_input =
      (
        ~created_at=?,
        ~dates_watched=?,
        ~id=?,
        ~imdb_id=?,
        ~imdb_rating=?,
        ~movie_genres=?,
        ~movie_people=?,
        ~overview=?,
        ~poster=?,
        ~ratings=?,
        ~release_date=?,
        ~runtime=?,
        ~tagline=?,
        ~title=?,
        ~updated_at=?,
        (),
      )
      : movie_insert_input => {
    created_at,
    dates_watched,
    id,
    imdb_id,
    imdb_rating,
    movie_genres,
    movie_people,
    overview,
    poster,
    ratings,
    release_date,
    runtime,
    tagline,
    title,
    updated_at,
  };

  let make_movie_obj_rel_insert_input =
      (~data, ~on_conflict=?, ()): movie_obj_rel_insert_input => {
    data,
    on_conflict,
  };

  let make_movie_person_insert_input =
      (~id=?, ~job=?, ~movie=?, ~movie_id=?, ~person=?, ~person_id=?, ())
      : movie_person_insert_input => {
    id,
    job,
    movie,
    movie_id,
    person,
    person_id,
  };

  let make_string_comparison_exp =
      (
        ~_eq=?,
        ~_gt=?,
        ~_gte=?,
        ~_ilike=?,
        ~_in=?,
        ~_is_null=?,
        ~_like=?,
        ~_lt=?,
        ~_lte=?,
        ~_neq=?,
        ~_nilike=?,
        ~_nin=?,
        ~_nlike=?,
        ~_nsimilar=?,
        ~_similar=?,
        (),
      )
      : string_comparison_exp => {
    _eq,
    _gt,
    _gte,
    _ilike,
    _in,
    _is_null,
    _like,
    _lt,
    _lte,
    _neq,
    _nilike,
    _nin,
    _nlike,
    _nsimilar,
    _similar,
  };

  let make_int_comparison_exp =
      (
        ~_eq=?,
        ~_gt=?,
        ~_gte=?,
        ~_in=?,
        ~_is_null=?,
        ~_lt=?,
        ~_lte=?,
        ~_neq=?,
        ~_nin=?,
        (),
      )
      : int_comparison_exp => {
    _eq,
    _gt,
    _gte,
    _in,
    _is_null,
    _lt,
    _lte,
    _neq,
    _nin,
  };

  let make_genre_bool_exp =
      (~_and=?, ~_not=?, ~_or=?, ~id=?, ~name=?, ()): genre_bool_exp => {
    _and,
    _not,
    _or,
    id,
    name,
  };

  let make_genre_on_conflict =
      (~constraint_, ~update_columns, ~where=?, ()): genre_on_conflict => {
    constraint_,
    update_columns,
    where,
  };

  let make_genre_insert_input = (~id=?, ~name=?, ()): genre_insert_input => {
    id,
    name,
  };

  let make_genre_obj_rel_insert_input =
      (~data, ~on_conflict=?, ()): genre_obj_rel_insert_input => {
    data,
    on_conflict,
  };

  let make_movie_genre_insert_input =
      (~genre=?, ~genre_id=?, ~id=?, ~movie_id=?, ())
      : movie_genre_insert_input => {
    genre,
    genre_id,
    id,
    movie_id,
  };

  let makeVariables =
      (
        ~imdbId=?,
        ~overview=?,
        ~runtime=?,
        ~poster=?,
        ~releaseDate=?,
        ~tagline=?,
        ~title=?,
        ~rating=?,
        ~genres,
        ~people,
        ~watchDates,
        (),
      )
      : variables => {
    imdbId,
    overview,
    runtime,
    poster,
    releaseDate,
    tagline,
    title,
    rating,
    genres,
    people,
    watchDates,
  };

  let make_response_insert_movie_one = (~title): response_insert_movie_one => {
    title: title,
  };

  let makeOptimisticResponse = (~insert_movie_one=?, ()): rawResponse => {
    insert_movie_one: insert_movie_one,
  };
};

type operationType = ReasonRelay.mutationNode;

let node: operationType = [%raw
  {json| (function(){
var v0 = {
  "defaultValue": null,
  "kind": "LocalArgument",
  "name": "genres"
},
v1 = {
  "defaultValue": null,
  "kind": "LocalArgument",
  "name": "imdbId"
},
v2 = {
  "defaultValue": null,
  "kind": "LocalArgument",
  "name": "overview"
},
v3 = {
  "defaultValue": null,
  "kind": "LocalArgument",
  "name": "people"
},
v4 = {
  "defaultValue": null,
  "kind": "LocalArgument",
  "name": "poster"
},
v5 = {
  "defaultValue": null,
  "kind": "LocalArgument",
  "name": "rating"
},
v6 = {
  "defaultValue": null,
  "kind": "LocalArgument",
  "name": "releaseDate"
},
v7 = {
  "defaultValue": null,
  "kind": "LocalArgument",
  "name": "runtime"
},
v8 = {
  "defaultValue": null,
  "kind": "LocalArgument",
  "name": "tagline"
},
v9 = {
  "defaultValue": null,
  "kind": "LocalArgument",
  "name": "title"
},
v10 = {
  "defaultValue": null,
  "kind": "LocalArgument",
  "name": "watchDates"
},
v11 = [
  {
    "fields": [
      {
        "fields": [
          {
            "kind": "Variable",
            "name": "data",
            "variableName": "watchDates"
          }
        ],
        "kind": "ObjectValue",
        "name": "dates_watched"
      },
      {
        "kind": "Variable",
        "name": "imdb_id",
        "variableName": "imdbId"
      },
      {
        "fields": [
          {
            "kind": "Variable",
            "name": "data",
            "variableName": "genres"
          }
        ],
        "kind": "ObjectValue",
        "name": "movie_genres"
      },
      {
        "fields": [
          {
            "kind": "Variable",
            "name": "data",
            "variableName": "people"
          }
        ],
        "kind": "ObjectValue",
        "name": "movie_people"
      },
      {
        "kind": "Variable",
        "name": "overview",
        "variableName": "overview"
      },
      {
        "kind": "Variable",
        "name": "poster",
        "variableName": "poster"
      },
      {
        "fields": [
          {
            "items": [
              {
                "fields": [
                  {
                    "kind": "Variable",
                    "name": "rating",
                    "variableName": "rating"
                  }
                ],
                "kind": "ObjectValue",
                "name": "data.0"
              }
            ],
            "kind": "ListValue",
            "name": "data"
          }
        ],
        "kind": "ObjectValue",
        "name": "ratings"
      },
      {
        "kind": "Variable",
        "name": "release_date",
        "variableName": "releaseDate"
      },
      {
        "kind": "Variable",
        "name": "runtime",
        "variableName": "runtime"
      },
      {
        "kind": "Variable",
        "name": "tagline",
        "variableName": "tagline"
      },
      {
        "kind": "Variable",
        "name": "title",
        "variableName": "title"
      }
    ],
    "kind": "ObjectValue",
    "name": "object"
  }
],
v12 = {
  "alias": null,
  "args": null,
  "kind": "ScalarField",
  "name": "title",
  "storageKey": null
};
return {
  "fragment": {
    "argumentDefinitions": [
      (v0/*: any*/),
      (v1/*: any*/),
      (v2/*: any*/),
      (v3/*: any*/),
      (v4/*: any*/),
      (v5/*: any*/),
      (v6/*: any*/),
      (v7/*: any*/),
      (v8/*: any*/),
      (v9/*: any*/),
      (v10/*: any*/)
    ],
    "kind": "Fragment",
    "metadata": null,
    "name": "AddMoviePageMutation",
    "selections": [
      {
        "alias": null,
        "args": (v11/*: any*/),
        "concreteType": "movie",
        "kind": "LinkedField",
        "name": "insert_movie_one",
        "plural": false,
        "selections": [
          (v12/*: any*/)
        ],
        "storageKey": null
      }
    ],
    "type": "mutation_root",
    "abstractKey": null
  },
  "kind": "Request",
  "operation": {
    "argumentDefinitions": [
      (v1/*: any*/),
      (v2/*: any*/),
      (v7/*: any*/),
      (v4/*: any*/),
      (v6/*: any*/),
      (v8/*: any*/),
      (v9/*: any*/),
      (v5/*: any*/),
      (v0/*: any*/),
      (v3/*: any*/),
      (v10/*: any*/)
    ],
    "kind": "Operation",
    "name": "AddMoviePageMutation",
    "selections": [
      {
        "alias": null,
        "args": (v11/*: any*/),
        "concreteType": "movie",
        "kind": "LinkedField",
        "name": "insert_movie_one",
        "plural": false,
        "selections": [
          (v12/*: any*/),
          {
            "alias": null,
            "args": null,
            "kind": "ScalarField",
            "name": "id",
            "storageKey": null
          }
        ],
        "storageKey": null
      }
    ]
  },
  "params": {
    "cacheID": "128de2de324ed4a4d2f4c1ce28b5e951",
    "id": null,
    "metadata": {},
    "name": "AddMoviePageMutation",
    "operationKind": "mutation",
    "text": "mutation AddMoviePageMutation(\n  $imdbId: String\n  $overview: String\n  $runtime: Int\n  $poster: String\n  $releaseDate: date\n  $tagline: String\n  $title: String\n  $rating: Int\n  $genres: [movie_genre_insert_input!]!\n  $people: [movie_person_insert_input!]!\n  $watchDates: [seen_insert_input!]!\n) {\n  insert_movie_one(object: {imdb_id: $imdbId, overview: $overview, runtime: $runtime, poster: $poster, release_date: $releaseDate, tagline: $tagline, title: $title, ratings: {data: [{rating: $rating}]}, movie_genres: {data: $genres}, movie_people: {data: $people}, dates_watched: {data: $watchDates}}) {\n    title\n    id\n  }\n}\n"
  }
};
})() |json}
];

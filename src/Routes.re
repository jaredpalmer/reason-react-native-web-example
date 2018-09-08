open ReasonReact.Router;

type t =
  | Home
  | About
  | Greet(option(string))
  | NotFound;

exception RouteToNotFound;

let match = (url: url) =>
  switch (url.path) {
  | [] => Home
  | ["about"] => About
  | ["greet"] => Greet(None)
  | ["greet", greeting] => Greet(Some(greeting))
  | _ => NotFound
  };

let toHref =
  fun
  | Home => "/"
  | About => "/about"
  | Greet(optionalGreeting) =>
    "/greet/"
    ++ (
      switch (optionalGreeting) {
      | None => ""
      | Some(greeting) => greeting
      }
    )
  | NotFound => raise(RouteToNotFound);

/* This lets us push a Routes.t instead of a string to transition to a new  screen */
let push = route => route |> toHref |> push;

/* On the server, we need a way to parse the path in req, but ReasonReact.Router doesn't
   expose this logic publicly. So we just copy it here - note that it won't work for search or hash, though
   that'd be fairly trivial to add */
let serverMatch = (path: string): t => {
  let urlPath: list(string) =
    switch (path) {
    | ""
    | "/" => []
    | raw =>
      /* remove the preceeding /, which every pathname seems to have */
      let raw = Js.String.sliceToEnd(~from=1, raw);
      /* remove the trailing /, which some pathnames might have. Ugh */
      let raw =
        switch (Js.String.get(raw, Js.String.length(raw) - 1)) {
        | "/" => Js.String.slice(~from=0, ~to_=-1, raw)
        | _ => raw
        };
      raw |> Js.String.split("/") |> Array.to_list;
    };
  Js.log(urlPath);
  match({path: urlPath, hash: "", search: ""});
};

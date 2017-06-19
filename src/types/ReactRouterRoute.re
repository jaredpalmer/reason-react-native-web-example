external route : ReactRe.reactClass = "Route" [@@bs.module "react-router-dom"];

type rrfn = Js.t {. _match : Js.t {. url : string}};

let make exact::(exact: bool) path::(path: string) component::(component: 'a) =>
  ReasonReact.wrapJsForReason
    reactClass::route
    props::{"exact": Js.Boolean.to_js_boolean exact, "path": path, "component": component};

[@bs.module "react-router-dom"] external route : ReasonReact.reactClass = "Route";

type rrfn = {. "_match": {. "url": string}};

let make = (~exact: bool, ~path: string, ~component: 'a, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=route,
    ~props={"exact": Js.Boolean.to_js_boolean(exact), "path": path, "component": component},
    children
  );

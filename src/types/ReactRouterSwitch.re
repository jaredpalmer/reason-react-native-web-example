[@bs.module "react-router-dom"] external _switch : ReasonReact.reactClass = "Switch";

let make = (children) =>
  ReasonReact.wrapJsForReason(~reactClass=_switch, ~props=Js.Obj.empty(), children);

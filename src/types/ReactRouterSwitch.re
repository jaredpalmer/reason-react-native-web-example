external _switch : ReactRe.reactClass = "Switch" [@@bs.module "react-router-dom"];

let make children =>
  ReasonReact.wrapJsForReason reactClass::_switch props::(Js.Obj.empty ()) children;

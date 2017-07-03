external browserRouter : ReactRe.reactClass = "BrowserRouter" [@@bs.module "react-router-dom"];

let make children =>
  ReasonReact.wrapJsForReason reactClass::browserRouter props::(Js.Obj.empty ()) children;

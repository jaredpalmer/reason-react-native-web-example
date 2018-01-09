[@bs.module "react-router-dom"]
external browserRouter : ReasonReact.reactClass =
  "BrowserRouter";

let make = (children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=browserRouter,
    ~props=Js.Obj.empty(),
    children
  );

external navLink : ReactRe.reactClass = "NavLink" [@@bs.module "react-router-dom"];

let make
    _to::(_to: string)
    activeClassName::(activeClassName: option string)=?
    className::(className: option string)=?
    children =>
  ReasonReact.wrapJsForReason
    reactClass::navLink
    props::{
      "activeClassName": Js.Null_undefined.from_opt activeClassName,
      "className": Js.Null_undefined.from_opt className,
      "to": _to
    }
    children;

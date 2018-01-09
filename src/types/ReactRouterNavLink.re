[@bs.module "react-router-dom"] external navLink : ReasonReact.reactClass = "NavLink";

let make =
    (~_to: string, ~activeClassName: option(string)=?, ~className: option(string)=?, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=navLink,
    ~props={
      "activeClassName": Js.Null_undefined.from_opt(activeClassName),
      "className": Js.Null_undefined.from_opt(className),
      "to": _to
    },
    children
  );

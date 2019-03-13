[@bs.module "../../../src/TextLinkNative"]
external link: ReasonReact.reactClass = "default";

let make =
    (
      ~href: option(string)=?,
      ~style: option(BsReactNative.Style.t)=?,
      ~onPress,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=link,
    ~props={
      "href": Js.Nullable.fromOption(href),
      "style": Js.Nullable.fromOption(style),
      "onPress": onPress,
    },
    children,
  );

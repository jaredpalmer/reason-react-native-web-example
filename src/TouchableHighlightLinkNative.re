[@bs.module "../../../src/TouchableHighlightLinkNative"]
external link: ReasonReact.reactClass = "default";

let make =
    (
      ~href: option(string)=?,
      ~style: option(BsReactNative.Style.t)=?,
      ~activeOpacity: option(float)=?,
      ~underlayColor: option(string)=?,
      ~onPress=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=link,
    ~props={
      "href": Js.Nullable.fromOption(href),
      "style": Js.Nullable.fromOption(style),
      "activeOpacity": Js.Nullable.fromOption(activeOpacity),
      "underlayColor": Js.Nullable.fromOption(underlayColor),
      "onPress": onPress,
    },
    children,
  );

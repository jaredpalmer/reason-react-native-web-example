[@bs.module "../../../src/TextLinkNative"] [@react.component]
external make:
  (
    ~href: string,
    ~style: ReactNative.Style.t=?,
    ~onPress: ReactEvent.Mouse.t => unit=?,
    ~children: React.element
  ) =>
  React.element =
  "default";

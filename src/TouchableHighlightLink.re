[@react.component]
let make =
    (
      ~route: Routes.t,
      ~style: ReactNative.Style.t=?,
      ~activeOpacity: float=?,
      ~underlayColor: string=?,
      ~children,
    ) => {
  let href = Routes.toHref(route);
  let click = event => {
    ReactEvent.Mouse.preventDefault(event);
    ReasonReactRouter.push(href);
  };
  <TouchableHighlightLinkNative
    href style activeOpacity underlayColor onPress=click>
    children
  </TouchableHighlightLinkNative>;
};

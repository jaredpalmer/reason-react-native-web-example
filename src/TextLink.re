[@react.component]
let make = (~route: Routes.t, ~style: ReactNative.Style.t=?, ~children) => {
  let href = Routes.toHref(route);
  let click = event => {
    ReactEvent.Mouse.preventDefault(event);
    ReasonReactRouter.push(href);
  };
  <TextLinkNative style href onPress=click> children </TextLinkNative>;
};

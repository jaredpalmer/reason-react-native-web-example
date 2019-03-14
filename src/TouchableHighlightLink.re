let component = ReasonReact.statelessComponent("TouchableHighlightLink");

let make =
    (
      ~route: Routes.t,
      ~style: option(BsReactNative.Style.t)=?,
      ~activeOpacity: option(float)=?,
      ~underlayColor: option(string)=?,
      children,
    ) => {
  let href = Routes.toHref(route);
  let click = event => {
    ReactEvent.Mouse.preventDefault(event);
    ReasonReact.Router.push(href);
  };
  {
    ...component,
    render: _self => {
      <TouchableHighlightLinkNative
        href ?style ?activeOpacity ?underlayColor onPress=click>
        ...children
      </TouchableHighlightLinkNative>;
    },
  };
};

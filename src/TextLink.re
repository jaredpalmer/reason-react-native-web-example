let component = ReasonReact.statelessComponent("TextLink");

let make = (~route: Routes.t, children) => {
  let href = Routes.toHref(route);
  let click = (event) => {
    ReactEvent.Mouse.preventDefault(event);
    ReasonReact.Router.push(href);
  };
  {
    ...component,
    render: _self => {
      <TextLinkNative
        href=href
        onPress={click}
      >
        children
      </TextLinkNative>
    },
  }
};
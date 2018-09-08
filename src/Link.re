/* This component renders an <a>. When JS is working, it'll trigger a client-side
   route transition to the provided route, but it falls back to a server
   transition as well. Obviously this component is web-only, but you could easily
   make a native-compliant version that did essentiall the same thing! */
let component = ReasonReact.statelessComponent("Link");

let make = (~route: Routes.t, children) => {
  ...component,
  render: self => {
    let href = Routes.toHref(route);
    ReasonReact.createDomElement(
      "a",
      ~props={
        "href": href,
        "onClick":
          self.handle((event, _self) => {
            ReactEvent.Mouse.preventDefault(event);
            ReasonReact.Router.push(href);
          }),
      },
      children,
    );
  },
};

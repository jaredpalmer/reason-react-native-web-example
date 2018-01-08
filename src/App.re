open BsReactNative;

let component = ReasonReact.statelessComponent("App");

let make = (_children) => {
  let renderHomeRoute = (_) => <Home />;
  let renderAboutRoute = (_) => <About />;
  {
    ...component,
    render: (_self) =>
      <View>
        <ReactRouterNavLink _to="/">
          (ReasonReact.stringToElement("Home"))
        </ReactRouterNavLink>
        <ReactRouterNavLink _to="/about">
          (ReasonReact.stringToElement("About"))
        </ReactRouterNavLink>
        <ReactRouterSwitch>
          <ReactRouterRoute path="/" component=renderHomeRoute exact=true />
          <ReactRouterRoute
            path="/about"
            component=renderAboutRoute
            exact=true
          />
        </ReactRouterSwitch>
      </View>
  }
};

let jsComponent = ReasonReact.wrapReasonForJs(~component, (_) => make([||]));

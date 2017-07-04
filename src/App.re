open ReactNative;

let component = ReasonReact.statelessComponent "App";

let make _children => {
  let renderHomeRoute _ => <Home />;
  let renderAboutRoute _ => <About />;
  {
    ...component,
    render: fun () _ =>
      <ReactRouterBrowserRouter>
        <View>
          <ReactRouterNavLink _to="/"> (ReactRe.stringToElement "Home") </ReactRouterNavLink>
          <ReactRouterNavLink _to="/about"> (ReactRe.stringToElement "About") </ReactRouterNavLink>
          <ReactRouterSwitch>
            <ReactRouterRoute path="/" component=renderHomeRoute exact=true />
            <ReactRouterRoute path="/about" component=renderAboutRoute exact=true />
          </ReactRouterSwitch>
        </View>
      </ReactRouterBrowserRouter>
  }
};

let jsComponent = ReasonReact.wrapReasonForJs ::component (fun _ => make [||]);

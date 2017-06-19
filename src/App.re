open ReactNative;

let component = ReasonReact.statelessComponent "App";

let make _children => {
  ...component,
  render: fun () _ => {
    let renderHomeRoute _ => <Home />;
    let renderAboutRoute _ => <About />;
    <View>
      <ReactRouterNavLink _to="/"> (ReactRe.stringToElement "Home") </ReactRouterNavLink>
      <ReactRouterNavLink _to="/about"> (ReactRe.stringToElement "About") </ReactRouterNavLink>
      <ReactRouterSwitch>
        <ReactRouterRoute path="/" component=renderHomeRoute exact=true />
        <ReactRouterRoute path="/about" component=renderAboutRoute exact=true />
      </ReactRouterSwitch>
    </View>
  }
};

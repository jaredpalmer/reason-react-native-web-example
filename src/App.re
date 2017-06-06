open ReactRouter;

open ReactNative;

module App = {
  include ReactRe.Component;
  let name = "App";
  type props = unit;
  let render _ =>
    <View>
      <NavLink _to="/"> (ReactRe.stringToElement "Home") </NavLink>
      <NavLink _to="/about"> (ReactRe.stringToElement "About") </NavLink>
      <RRSwitch>
        <Route path="/" component=(fun _ => <Home />) exact=true />
        <Route path="/about" component=(fun _ => <About />) exact=true />
      </RRSwitch>
    </View>;
};

include ReactRe.CreateComponent App;

let createElement = wrapProps ();

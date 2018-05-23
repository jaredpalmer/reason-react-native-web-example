/* App is the actual entry point for the application. It matches on the route prop to determine which
   sub-component to render */
open BsReactNative;

let styles =
  StyleSheet.create(
    Style.(
      {
        "navBar":
          style([
            flexDirection(Row),
            backgroundColor("#f1f1f1"),
            paddingVertical(Pt(8.)),
            paddingHorizontal(Pt(16.)),
          ]),
        "link":
          style([
            paddingVertical(Pt(4.)),
            paddingHorizontal(Pt(8.)),
            marginRight(Pt(8.)),
          ]),
      }
    ),
  );

let component = ReasonReact.statelessComponent("App");

let make = (~route: Routes.t, _children) => {
  ...component,
  render: _self =>
    <View>
      <View style=styles##navBar>
        <View style=styles##link>
          <Link route=Home> (ReasonReact.string("Home")) </Link>
        </View>
        <View style=styles##link>
          <Link route=About> (ReasonReact.string("About")) </Link>
        </View>
        <View style=styles##link>
          <Link route=(Greet(Some("Hello!")))>
            (ReasonReact.string("Greet"))
          </Link>
        </View>
      </View>
      (
        switch (route) {
        | Home => <Home />
        | About => <About />
        | Greet(greeting) => <Greet ?greeting />
        | NotFound =>
          <View>
            <Text> ("404 - Route Not Found :(" |> ReasonReact.string) </Text>
          </View>
        }
      )
    </View>,
};

let default =
  ReasonReact.wrapReasonForJs(~component, jsProps =>
    make(~route=jsProps##route, [||])
  );

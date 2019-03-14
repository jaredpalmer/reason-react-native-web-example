/* App is the actual entry point for the application. It matches on the route prop to determine which
   sub-component to render */
open BsReactNative;

let styles =
  StyleSheet.create(
    {
      Style.{
        "navBar":
          style([
            flexDirection(Row),
            backgroundColor("#f1f1f1"->String),
            height(44.->Pt),
          ]),
        "link": style([justifyContent(Center), paddingHorizontal(16.->Pt)]),
      };
    },
  );

let component = ReasonReact.statelessComponent("App");

let make = (~route: Routes.t, _children) => {
  ...component,
  render: _self =>
    <View>
      <View style=styles##navBar>
        <TouchableHighlightLink
          route=Home
          style=styles##link
          activeOpacity=1.0
          underlayColor="#DEDEDE">
          <Text> {"Home" |> ReasonReact.string} </Text>
        </TouchableHighlightLink>
        <TouchableHighlightLink
          route=About
          style=styles##link
          activeOpacity=1.0
          underlayColor="#DEDEDE">
          <Text> {"About" |> ReasonReact.string} </Text>
        </TouchableHighlightLink>
        <TouchableHighlightLink
          route={Greet(Some("Hello!"))}
          style=styles##link
          activeOpacity=1.0
          underlayColor="#DEDEDE">
          <Text> {"Greet" |> ReasonReact.string} </Text>
        </TouchableHighlightLink>
      </View>
      {switch (route) {
       | Home => <Home />
       | About => <About />
       | Greet(greeting) => <Greet ?greeting />
       | NotFound =>
         <View>
           <Text> {"404 - Route Not Found :(" |> ReasonReact.string} </Text>
         </View>
       }}
    </View>,
};

let default =
  ReasonReact.wrapReasonForJs(~component, jsProps =>
    make(~route=jsProps##route, [||])
  );

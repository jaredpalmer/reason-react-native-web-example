/* App is the actual entry point for the application. It matches on the route prop to determine which
   sub-component to render */
open ReactNative;

let styles =
  Style.(
    StyleSheet.create({
      "navBar":
        style(
          ~flexDirection=`row,
          ~backgroundColor="#f1f1f1",
          ~height=44.->dp,
          (),
        ),
      "link": style(~justifyContent=`center, ~paddingHorizontal=16.->dp, ()),
    })
  );

[@react.component]
let make = (~serverUrl: ReasonReactRouter.url) => {
  let url = ReasonReactRouter.useUrl(~serverUrl, ());
  let route = Routes.match(url);

  <View>
    <View style=styles##navBar>
      <TouchableHighlightLink
        route=Home
        style=styles##link
        activeOpacity=1.0
        underlayColor="#DEDEDE">
        <Text> "Home"->React.string </Text>
      </TouchableHighlightLink>
      <TouchableHighlightLink
        route=About
        style=styles##link
        activeOpacity=1.0
        underlayColor="#DEDEDE">
        <Text> "About"->React.string </Text>
      </TouchableHighlightLink>
      <TouchableHighlightLink
        route={Greet(Some("Hello!"))}
        style=styles##link
        activeOpacity=1.0
        underlayColor="#DEDEDE">
        <Text> "Greet"->React.string </Text>
      </TouchableHighlightLink>
    </View>
    {switch (route) {
     | Home => <Home />
     | About => <About />
     | Greet(greeting) => <Greet ?greeting />
     | NotFound =>
       <View> <Text> "404 - Route Not Found :("->React.string </Text> </View>
     }}
  </View>;
};

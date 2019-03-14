open BsReactNative;

let styles =
  StyleSheet.create(
    {
      Style.{
        "wrapper":
          style([
            flexDirection(Column),
            backgroundColor(String("#3398FF")),
            marginVertical(Pt(16.)),
            marginHorizontal(Pt(32.)),
            paddingVertical(Pt(64.)),
          ]),
        "text":
          style([
            color(String("#fff")),
            fontSize(Float(17.)),
            fontWeight(`_500),
            marginLeft(Pt(15.)),
          ]),
        "link": style([color("#3398FF"->String)]),
      };
    },
  );

let component = ReasonReact.statelessComponent("About");

let make = _children => {
  ...component,
  render: _self =>
    <View>
      <View style=styles##wrapper>
        <Text style=styles##text value="React Native Web is Awesome" />
      </View>
      <Text>
        "Internal link: "->ReasonReact.string
        <TextLink route={Greet(Some("Bonjour"))} style=styles##link>
          "Bonjour"->ReasonReact.string
        </TextLink>
      </Text>
      <Text>
        "External link: "->ReasonReact.string
        <TextLinkNative
          href="https://github.com/jaredpalmer/reason-react-native-web-example"
          style=styles##link>
          "Github"->ReasonReact.string
        </TextLinkNative>
      </Text>
    </View>,
};

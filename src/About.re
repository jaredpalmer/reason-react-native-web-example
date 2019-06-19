open ReactNative;

let styles =
  Style.(
    StyleSheet.create({
      "wrapper":
        style(
          ~flexDirection=`column,
          ~backgroundColor="#3398FF",
          ~marginVertical=16.->dp,
          ~marginHorizontal=32.->dp,
          ~paddingVertical=64.->dp,
          (),
        ),
      "text":
        style(
          ~color="#fff",
          ~fontSize=17.,
          ~fontWeight=`_500,
          ~marginLeft=15.->dp,
          (),
        ),
      "link": style(~color="#3398FF", ()),
    })
  );

[@react.component]
let make = () => {
  <View>
    <View style=styles##wrapper>
      <Text style=styles##text>
        "React Native Web is Awesome"->React.string
      </Text>
    </View>
    <Text>
      "Internal link: "->React.string
      <TextLink route={Greet(Some("Bonjour"))} style=styles##link>
        "Bonjour"->React.string
      </TextLink>
    </Text>
    <Text>
      "External link: "->React.string
      <TextLinkNative
        href="https://github.com/jaredpalmer/reason-react-native-web-example"
        style=styles##link>
        "Github"->React.string
      </TextLinkNative>
    </Text>
  </View>;
};

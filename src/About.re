open BsReactNative;

let styles =
  StyleSheet.create(
    {
      open Style;
      {
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
      };
    },
  );

let component = ReasonReact.statelessComponent("About");

let make = _children => {
  ...component,
  render: _self =>
    <View style=styles##wrapper>
      <Text style=styles##text value="React Native Web is Awesome" />
    </View>,
};

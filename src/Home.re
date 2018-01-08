open BsReactNative;

let styles =
  StyleSheet.create(
    Style.(
      {
        "wrapper":
          style([
            flexDirection(Column),
            backgroundColor("#6698FF"),
            marginVertical(Pt(16.)),
            marginHorizontal(Pt(32.)),
            paddingVertical(Pt(64.))
          ]),
        "text":
          style([
            color("#fff"),
            fontSize(Float(17.)),
            fontWeight(`_500),
            marginLeft(Pt(15.))
          ])
      }
    )
  );

let component = ReasonReact.statelessComponent("Home");

let make = (_children) => {
  ...component,
  render: (_self) =>
    <View style=styles##wrapper>
      <Text style=styles##text value="Reason is awesome!" />
    </View>
};

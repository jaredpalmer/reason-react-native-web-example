open ReactNative;

let styles =
  StyleSheet.create
    Style.(
      {
        "wrapper":
          style [
            flexDirection `column,
            backgroundColor "#6698FF",
            marginVertical 16.,
            marginHorizontal 32.,
            paddingVertical 64.
          ],
        "text": style [color "#fff", fontSize 17., fontWeight `_500, marginLeft 15.]
      }
    );

let component = ReasonReact.statelessComponent "Home";

let make _children => {
  ...component,
  render: fun () _ =>
    <View style=styles##wrapper> <Text style=styles##text value="Reason is awesome!" /> </View>
};

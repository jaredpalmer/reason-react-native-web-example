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

module Home = {
  include ReactRe.Component;
  let name = "Home";
  type props = unit;
  let render _ =>
    <View style=styles##wrapper> <Text style=styles##text value="Reason is awesome!" /> </View>;
};

include ReactRe.CreateComponent Home;

let createElement = wrapProps ();

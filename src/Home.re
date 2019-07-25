open ReactNative;

let styles =
  Style.(
    StyleSheet.create({
      "wrapper":
        style(
          ~flexDirection=`column,
          ~backgroundColor="#6698FF",
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
    })
  );

[@react.component]
let make = () => {
  <View style=styles##wrapper>
    <Text style=styles##text> "Reason is awesome!"->React.string </Text>
  </View>;
};

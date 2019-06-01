open ReactNative;

let styles =
  Style.(
    StyleSheet.create({
      "wrapper":
        style(
          ~flexDirection=`column,
          ~backgroundColor="#6698FF",
          ~marginVertical=16.->pt,
          ~marginHorizontal=32.->pt,
          ~paddingVertical=64.->pt,
          (),
        ),
      "text":
        style(
          ~color="#fff",
          ~fontSize=17.,
          ~fontWeight=`_500,
          ~marginLeft=15.->pt,
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

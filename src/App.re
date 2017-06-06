open ReactNative;


/**
 * React Native Web actually pushes a ton of stuff into props, we just need
 * one property though to get ReactRe to compile and not yell at us */
type root = Js.t {. className : string};

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

module App = {
  include ReactRe.Component.JsProps;
  let name = "App";
  type props = {
    /* An array of Meetup.com events */
    rootTag: root
  };
  let render _ =>
    <View style=styles##wrapper> <Text style=styles##text value="Reason is awesome!" /> </View>;
  /* Tell Reason-React how to transform JS props into ReasonML */
  type jsProps = Js.t {. rootTag : root};
  let jsPropsToReasonProps = Some (fun jsProps => {rootTag: jsProps##rootTag});
};

include ReactRe.CreateComponent App;

let createElement ::rootTag => wrapProps {rootTag: rootTag};

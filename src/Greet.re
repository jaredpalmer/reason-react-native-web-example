open BsReactNative;

let component = ReasonReact.statelessComponent("Greet");

let make = (~greeting=?, _children) => {
  ...component,
  render: _self =>
    switch (greeting) {
    | Some(g) => <Text> (g |> ReasonReact.string) </Text>
    | None => <Text> ("No greeting provided" |> ReasonReact.string) </Text>
    },
};

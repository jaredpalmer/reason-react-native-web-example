open ReactNative;

[@react.component]
let make = (~greeting=?) => {
  switch (greeting) {
  | Some(g) => <Text> g->React.string </Text>
  | None => <Text> "No greeting provided"->React.string </Text>
  };
};

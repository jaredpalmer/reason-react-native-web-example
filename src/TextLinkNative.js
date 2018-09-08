// @flow
import * as React from "react";
import { Text } from "react-native";

type PropsType = {
  style?: Object,
  onPress: () => void,
  href: string,
  children?: React.Node
};

function Link(props: PropsType, context: Object) {
  const {
    href,
    style,
    onPress,
    ...otherProps
  } = props;

  return (
    <Text
      {...otherProps}
      accessibilityRole="link"
      href={href}
      onPress={onPress}
      style={style}
    />
  );
}

Link.displayName = "Link";

export default Link;
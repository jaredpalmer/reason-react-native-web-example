// @flow
import * as React from "react";
import { Text } from "react-native";

type PropsType = {
  style?: Object,
  onPress: () => void,
  href: string,
  children?: React.Node
};

function TextNativeLink(props: PropsType, context: Object) {
  const { href, style, onPress, ...otherProps } = props;

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

TextNativeLink.displayName = "TextNativeLink";

export default TextNativeLink;

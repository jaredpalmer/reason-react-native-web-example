// @flow
import * as React from "react";
import { Text } from "react-native";

function TextNativeLink(props) {
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

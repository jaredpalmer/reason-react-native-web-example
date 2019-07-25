// @flow
import * as React from "react";
import { TouchableHighlight, View } from "react-native";

function TouchableHighlightLinkNative(props) {
  const {
    href,
    style,
    activeOpacity,
    underlayColor,
    onPress,
    children,
    ...otherProps
  } = props;

  return (
    <TouchableHighlight
      {...otherProps}
      accessibilityRole="link"
      href={href}
      onPress={onPress}
      style={style}
      activeOpacity={activeOpacity}
      underlayColor={underlayColor}
    >
      <View>{children}</View>
    </TouchableHighlight>
  );
}

TouchableHighlightLinkNative.displayName = "TouchableHighlightLinkNative";

export default TouchableHighlightLinkNative;

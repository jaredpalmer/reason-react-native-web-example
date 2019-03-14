// @flow
import * as React from "react";
import { TouchableHighlight, View } from "react-native";

type PropsType = {
  style?: Object,
  onPress: () => void,
  href: string,
  activeOpacity: number,
  underlayColor: string,
  children?: React.Node
};

function TouchableHighlightLinkNative(props: PropsType, context: Object) {
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

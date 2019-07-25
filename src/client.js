import { AppRegistry } from "react-native";

const App = require("../lib/js/src/App.bs").make;

// register the app
AppRegistry.registerComponent("App", () => App);

AppRegistry.runApplication("App", {
  rootTag: document.getElementById("react-root")
});

if (module.hot) {
  module.hot.accept();
}

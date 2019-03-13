import { AppRegistry } from "react-native";

const ClientRoot = require("../lib/js/src/ClientRoot.bs").default;

// register the app
AppRegistry.registerComponent("App", () => ClientRoot);

AppRegistry.runApplication("App", {
  rootTag: document.getElementById("react-root")
});

if (module.hot) {
  module.hot.accept();
}

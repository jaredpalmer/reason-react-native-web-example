// adding this hack for now until react-art supports SSR.
// reference: https://github.com/necolas/react-native-web/issues/737#issuecomment-355729136
if (typeof document === 'undefined') {
  global.document = {
    createElement: () => null,
  };
}

let app = require("./server").default;
const express = require("express");

if (module.hot) {
  module.hot.accept("./server", function() {
    console.log("🔁  HMR Reloading `./server`...");
    try {
      app = require("./server").default;
    } catch (error) {
      console.error(error);
    }
  });
  console.info("✅  Server-side HMR Enabled!");
}

const port = process.env.PORT || 3000;

export default express()
  .use((req, res) => app.handle(req, res))
  .listen(port, function(err) {
    if (err) {
      console.error(err);
      return;
    }
    console.log(`> Started on port ${port}`);
  });

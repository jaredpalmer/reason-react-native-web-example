import React from "react";
import compression from "compression";
import express from "express";
import helmet from "helmet";
import hpp from "hpp";
import morgan from "morgan";

import { AppRegistry } from "react-native";
import ReactDOMServer from "react-dom/server";

const App = require("../lib/js/src/App.bs").make;
const Routes = require("../lib/js/src/Routes.bs");
const assets = require(process.env.RAZZLE_ASSETS_MANIFEST);

const server = express();

server
  .disable("x-powered-by")
  .use(morgan(process.env.NODE_ENV === "production" ? "combined" : "dev"))
  .use(helmet())
  .use(hpp())
  .use(compression())
  .use(express.static(process.env.RAZZLE_PUBLIC_DIR))
  .get("/*", (req, res) => {
    const serverUrl = Routes.serverMatch(req.path);
    const ServerRoot = () => <App serverUrl={serverUrl} />;

    AppRegistry.registerComponent("App", () => ServerRoot);
    const { element, getStyleElement } = AppRegistry.getApplication("App", {});
    const markup = ReactDOMServer.renderToString(element);
    const initialStyles = ReactDOMServer.renderToStaticMarkup(
      getStyleElement()
    );

    res.send(
      `<!doctype html>
          <html lang="en" style="height:100%;overflow: hidden;">
            <head>
              <meta httpEquiv="X-UA-Compatible" content="IE=edge" />
              <meta charSet='utf-8' />
              <title>Reason React Native Web</title>
              <meta name="viewport" content="width=device-width, initial-scale=1">
              <meta name="description" content="We are the ReasonML community in NYC">
              <meta name="keywords" content="reason,reasonml,react,new york,nyc,2017,red badger,facebook">
              <link rel="shortcut icon" href="/favicon.ico">
              ${
                assets.client.css
                  ? `<link rel="stylesheet" href="${assets.client.css}">`
                  : ""
              }
              ${initialStyles}
            </head>
            <body style="height:100%;overflow: hidden;">
              <div id="react-root" style="display:flex;height:100%;">${markup}</div>
            </body>
            <script src="${assets.client.js}" defer></script>
          </html>`
    );
  });

export default server;

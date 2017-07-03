import React from 'react';
import compression from 'compression';
import express from 'express';
import helmet from 'helmet';
import hpp from 'hpp';
import morgan from 'morgan';

// import ReactNative, { AppRegistry } from 'react-native';
// import ReactDOMServer from 'react-dom/server';

const assets = require(process.env.RAZZLE_ASSETS_MANIFEST);

const server = express();

server
  .disable('x-powered-by')
  .use(morgan(process.env.NODE_ENV === 'production' ? 'combined' : 'dev'))
  .use(helmet())
  .use(hpp())
  .use(compression())
  .use(express.static(process.env.RAZZLE_PUBLIC_DIR))
  .get('/*', (req, res) => {
    // @ todo SSR

    // AppRegistry.registerComponent('App', () => App);
    // const { element, stylesheet } = AppRegistry.getApplication('App');
    // const markup = ReactDOMServer.renderToString(element);
    const markup = '';
    res.send(
      `<!doctype html>
    <html lang="en">
    <head>
        <meta httpEquiv="X-UA-Compatible" content="IE=edge" />
        <meta charSet='utf-8' />
        <title>Reason React Native Web</title>
        <meta name="viewport" content="width=device-width, initial-scale=1">
        <meta name="description" content="We are the ReasonML community in NYC">
        <meta name="keywords" content="reason,reasonml,react,new york,nyc,2017,red badger,facebook">
        <link rel="shortcut icon" href="/favicon.ico">
        ${assets.client.css
          ? `<link rel="stylesheet" href="${assets.client.css}">`
          : ''}
        <script src="${assets.client.js}" defer></script>
    </head>
    <body>
        <div id="root">${markup}</div>
    </body>
</html>`
    );
  });

export default server;

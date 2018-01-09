'use strict';

// in order for SSR to work, the react-native-web babel transform needs to be
// run on any code that references 'react-native'. So, we're overriding razzle's
// default "externals" configuration to also whitelist any deps that start with
// 'bs-react-native'. This will add those deps to the server bundle, but should
// also run the babel transform on them to switch 'react-native' --> 'react-native-web'

const nodeExternals = require('webpack-node-externals');

module.exports = {
  modify: (config, { target, dev }) => {
    if (target === 'node') {
      config.externals = [
        nodeExternals({
          whitelist: [
            dev ? 'webpack/hot/poll?300' : null,
            /\.(eot|woff|woff2|ttf|otf)$/,
            /\.(svg|png|jpg|jpeg|gif|ico)$/,
            /\.(mp4|mp3|ogg|swf|webp)$/,
            /\.(css|scss|sass|sss|less)$/,
            mod => mod.indexOf('bs-react-native') === 0,
          ].filter(x => x),
        }),
      ];
    }
    return config;
  },
};

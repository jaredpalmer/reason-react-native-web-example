'use strict';

const path = require('path');

module.exports = {
  modify(config, { target, dev }, webpack) {
    config.module.rules[
      config.module.rules.findIndex(rule => rule.loader == 'babel-loader')
    ].include.push(
      path.resolve(__dirname, 'node_modules/react-native-uncompiled')
    );

    return config;
  },
};

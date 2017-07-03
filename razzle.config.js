'use strict';

const path = require('path');

module.exports = {
  modify(config, { target, dev }, webpack) {
    config.module.rules[1].include.push(
      path.resolve(__dirname, 'node_modules/react-native-uncompiled')
    );

    return config;
  },
};

import 'sanitize.css/sanitize.css';
import './global.css';

import ReactNative, { AppRegistry } from 'react-native';

import React from 'react';

const Root = require('../lib/js/src/root').comp;

const initialState = window.__DATA__;

// register the app
AppRegistry.registerComponent('App', () => Root);

AppRegistry.runApplication('App', {
  rootTag: document.getElementById('root'),
});

if (module.hot) {
  module.hot.accept();
}

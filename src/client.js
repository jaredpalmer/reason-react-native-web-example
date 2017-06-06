import 'sanitize.css/sanitize.css';
import './global.css';

import ReactNative, { AppRegistry } from 'react-native';

import React from 'react';

const App = require('../lib/js/src/app').comp;

const initialState = window.__DATA__;

// register the app
AppRegistry.registerComponent('App', () => App);

AppRegistry.runApplication('App', {
  rootTag: document.getElementById('root'),
});

if (module.hot) {
  module.hot.accept();
}

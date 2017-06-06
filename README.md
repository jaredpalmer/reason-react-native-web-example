# Reason React Native Web Example

## Installation

```bash
git clone git@github.com:jaredpalmer/reason-react-native-web-example.git
cd reason-react-native-web-example && yarn
yarn dev
```

Go ahead and edit `App.re`.

## NPM Scripts

- *`yarn dev`*: Run BS and Webpack together
- *`yarn bsb-watch`*: Run BuckleScript compiler in watch mode
- *`yarn js-watch`*: Run Razzle (Webpack compiler) in development
- *`yarn build`*: Build for production
- *`yarn start`*: Start production
- *`yarn run clean`*: Clean up build artifacts and directories


## Todo

- [ ] SSR (having a module resolution issue with React Native). You can uncomment
lines in `src/server.js` and see what happens.

#### Author
- Jared Palmer [@jaredpalmer](https://twitter.com/jaredpalmer)

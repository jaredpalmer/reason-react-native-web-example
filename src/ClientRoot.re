/* This is where we bootstrap the client-side app and initiate the subscription to watch the
   url. This is also where you could add Providers for things like Redux or Apollo */
[@react.component]
let make = () => {
  let url = ReasonReactRouter.useUrl();
  let route = Routes.match(url);

  <App route />;
};

let default = make;

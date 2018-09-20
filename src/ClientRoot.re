/* This is where we bootstrap the client-side app and initiate the subscription to watch the
   url. This is also where you could add Providers for things like Redux or Apollo */
open Routes;

open ReasonReact.Router;

type state = Routes.t;

type action =
  | ChangeRoute(Routes.t);

let component = ReasonReact.reducerComponent("App");

let getInitialState: unit => state = () => Home;

let make = _children => {
  ...component,
  initialState: () => dangerouslyGetInitialUrl() |> Routes.match,
  reducer: (action, _state) =>
    switch (action) {
    | ChangeRoute(route) => ReasonReact.Update(route)
    },
  didMount: self => {
    let watcherID = ReasonReact.Router.watchUrl(url => self.send(ChangeRoute(url |> Routes.match)));
    self.onUnmount(() => ReasonReact.Router.unwatchUrl(watcherID));
  },
  render: ({state}) => <App route=state />,
};

let default = ReasonReact.wrapReasonForJs(~component, _jsProps => make([||]));

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
  subscriptions: ({send}) => [
    Sub(
      () => watchUrl(url => send(ChangeRoute(url |> Routes.match))),
      unwatchUrl,
    ),
  ],
  render: ({state}) => <App route=state />,
};

let default = ReasonReact.wrapReasonForJs(~component, _jsProps => make([||]));

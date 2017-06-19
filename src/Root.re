let component = ReasonReact.statelessComponent "Root";

let make _children => {
  ...component,
  render: fun () _self => <ReactRouterBrowserRouter> <App /> </ReactRouterBrowserRouter>
};

let jsComponent = ReasonReact.wrapReasonForJs ::component (fun _ => make [||]);

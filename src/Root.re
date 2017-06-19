let component = ReasonReact.statelessComponent "Root";

let make ::rootTag _children => {
  let logProps props => Js.log props;
  {
    ...component,
    render: fun () _self => {
      logProps rootTag;
      <ReactRouterBrowserRouter> <App /> </ReactRouterBrowserRouter>
    }
  }
};

let jsComponent =
  ReasonReact.wrapReasonForJs ::component (fun jsProps => make rootTag::jsProps##rootTag [||]);

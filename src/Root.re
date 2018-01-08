let component = ReasonReact.statelessComponent("Root");

let make = (~rootTag, _children) => {
  let logProps = (props) => Js.log(props);
  {
    ...component,
    render: (_self) => {
      logProps(rootTag);
      <ReactRouterBrowserRouter> <App /> </ReactRouterBrowserRouter>
    }
  }
};

let jsComponent =
  ReasonReact.wrapReasonForJs(
    ~component,
    (jsProps) => make(~rootTag=jsProps##rootTag, [||])
  );

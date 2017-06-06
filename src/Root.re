open ReactRouter;


/**
 * React Native Web actually pushes a ton of stuff into props, we just need
 * one property though to get ReactRe to compile and not yell at us */
type root = Js.t {. className : string};

module Root = {
  include ReactRe.Component.JsProps;
  let name = "Root";
  type props = {
    rootTag: root
  };
  let render _ => <BrowserRouter> <App /> </BrowserRouter>;
  /* Tell Reason-React how to transform JS props into ReasonML */
  type jsProps = Js.t {. rootTag : root};
  let jsPropsToReasonProps = Some (fun jsProps => {rootTag: jsProps##rootTag});
};

include ReactRe.CreateComponent Root;

let createElement ::rootTag => wrapProps {rootTag: rootTag};

module Page = {
  include ReactRe.Component;
  type props = {message: string};
  let name = "Page";
  let handleClick {props} event => {
    Js.log "clicked!";
    None
  };
  let render {props, updater} =>
    <p onClick=(updater handleClick)>
      (ReactRe.stringToElement props.message)
    </p>;
};

include ReactRe.CreateComponent Page;

/* The actual call exposed to consumers, via JSX */
let createElement ::message => wrapProps {message: message};

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


/* NB: These *must* be declared for the JSX syntax to work. */
include ReactRe.CreateComponent Page;
let createElement ::message => wrapProps {message: message};

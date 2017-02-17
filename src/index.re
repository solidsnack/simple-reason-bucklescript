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

/*let p = <Page message="Hello!" />;*/

ReactDOMRe.render <p/> (ReasonJs.Document.getElementById "index");


module Impl (T: { type t; }) => {
  type t_htmlElement = T.t;

  let ofElement : Dom.element => Js.null t_htmlElement = [%bs.raw {|
    function (element) {
      // BEWARE: Assumes "contentEditable" uniquely identifies an HTMLELement
      return element.contentEditable !== undefined ?  element : null;
    }
  |}];
  
  let ofElement : Dom.element => option t_htmlElement = fun self => Js.Null.to_opt (ofElement self)
  [@@deprecated "Consider using Element.asHtmlElement or Element.unsafeAsHtmlElement instead"];

  external accessKey : t_htmlElement => string = "" [@@bs.get];
  external setAccessKey : t_htmlElement => string => unit = "accessKey" [@@bs.set];
  external accessKeyLabel : t_htmlElement => string = "" [@@bs.get];
  external contentEditable : t_htmlElement => string /* enum */ = "" [@@bs.get];
  let contentEditable : t_htmlElement => DomTypesRe.contentEditable = fun self => DomTypesRe.decodeContentEditable (contentEditable self);
  external setContentEditable : t_htmlElement => string /* enum */ => unit = "contentEditable" [@@bs.set];
  let setContentEditable : t_htmlElement => DomTypesRe.contentEditable => unit = fun  self value => setContentEditable self (DomTypesRe.encodeContentEditable value);
  external isContentEditable : t_htmlElement => bool = "" [@@bs.get];
  external contextMenu : t_htmlElement => Dom.htmlElement = "" [@@bs.get]; /* returns HTMLMenuElement */
  external setContextMenu : t_htmlElement => Dom.htmlElement => unit = "contextMenu" [@@bs.set]; /* accepts and returns HTMLMenuElement */
  external dataset : t_htmlElement => Dom.domStringMap = "" [@@bs.get];
  external dir : t_htmlElement => string /* enum */ = "" [@@bs.get];
  let dir : t_htmlElement => DomTypesRe.dir = fun self => DomTypesRe.decodeDir (dir self);
  external setDir : t_htmlElement => string /* enum */ => unit = "dir" [@@bs.set];
  let setDir : t_htmlElement => DomTypesRe.dir => unit = fun self value => setDir self (DomTypesRe.encodeDir value);
  external draggable : t_htmlElement => bool = "" [@@bs.get];
  external setDraggable : t_htmlElement => Js.boolean => unit = "draggable" [@@bs.set];
  /*let setDraggable : t_htmlElement => bool => unit = fun self value => setDraggable self (Js.Boolean.to_js_boolean value);*/ /* temproarily removed to reduce codegen size */
  external dropzone : t_htmlElement => Dom.domSettableTokenList = "" [@@bs.get];
  external hidden : t_htmlElement => bool = "" [@@bs.get];
  external setHidden : t_htmlElement => Js.boolean => unit = "hidden" [@@bs.set];
  /*let setHidden : t_htmlElement => bool => unit = fun self value => setHidden self (Js.Boolean.to_js_boolean value);*/ /* temproarily removed to reduce codegen size */
  external itemScope : t_htmlElement => bool = "" [@@bs.get]; /* experimental */
  external setItemScope : t_htmlElement => Js.boolean => unit = "itemScope" [@@bs.set]; /* experimental */
  /*let setItemScope : t_htmlElement => bool => unit = fun self value => setItemScope self (Js.Boolean.to_js_boolean value);*/ /* temproarily removed to reduce codegen size */
  external itemType : t_htmlElement => Dom.domSettableTokenList = "" [@@bs.get]; /* experimental */
  external itemId : t_htmlElement => string = "" [@@bs.get]; /* experimental */
  external setItemId : t_htmlElement => string => unit = "itemId" [@@bs.set]; /* experimental */
  external itemRef : t_htmlElement => Dom.domSettableTokenList = "" [@@bs.get]; /* experimental */
  external itemProp : t_htmlElement => Dom.domSettableTokenList = "" [@@bs.get]; /* experimental */
  external itemValue : t_htmlElement => Js.t {..} = "" [@@bs.get]; /* experimental */
  external setItemValue : t_htmlElement => Js.t {..} => unit = "itemValue" [@@bs.set]; /* experimental */
  external lang : t_htmlElement => string = "" [@@bs.get];
  external setLang : t_htmlElement => string => unit = "lang" [@@bs.set];
  external offsetHeight : t_htmlElement => int = "" [@@bs.get]; /* experimental */
  external offsetLeft : t_htmlElement => int = "" [@@bs.get]; /* experimental */
  external offsetParent : t_htmlElement => Dom.element = "" [@@bs.get]; /* experimental */
  external offsetTop : t_htmlElement => int = "" [@@bs.get]; /* experimental, but widely supported */
  external offsetWidth : t_htmlElement => int = "" [@@bs.get]; /* experimental */
  /*external properties : r => HTMLPropertiesCollection.t = "properties" [@@bs.get]; /* experimental */*/
  external spellcheck : t_htmlElement => bool = "" [@@bs.get];
  external setSpellcheck : t_htmlElement => Js.boolean => unit = "spellcheck" [@@bs.set];
  /*let setSpellcheck : t_htmlElement => bool => unit = fun self value => setSpellcheck self (Js.Boolean.to_js_boolean value);*/ /* temproarily removed to reduce codegen size */
  external style : t_htmlElement => Dom.cssStyleDeclaration = "" [@@bs.get];
  external setStyle : t_htmlElement => Dom.cssStyleDeclaration => unit = "style" [@@bs.set];
  external tabIndex : t_htmlElement => int = "" [@@bs.get];
  external setTabIndex : t_htmlElement => int => unit = "tabIndex" [@@bs.set];
  external title : t_htmlElement => string = "" [@@bs.get];
  external setTitle : t_htmlElement => string => unit = "title" [@@bs.set];
  external translate : t_htmlElement => bool = "" [@@bs.get]; /* experimental */
  external setTranslate : t_htmlElement => Js.boolean => unit = "translate" [@@bs.set]; /* experimental */
  /*let setTranslate : t_htmlElement => bool => unit = fun self value => setTranslate self (Js.Boolean.to_js_boolean value);*/ /* temproarily removed to reduce codegen size */

  external blur : unit = "" [@@bs.send.pipe: t_htmlElement];
  external click : unit = "" [@@bs.send.pipe: t_htmlElement];
  external focus : unit = "" [@@bs.send.pipe: t_htmlElement];
  external forceSpellCheck : unit = "" [@@bs.send.pipe: t_htmlElement]; /* experimental */


  /* TODO: element-spcific, should be pulled out */
  external value : t_htmlElement => string = "" [@@bs.get]; /* HTMLInputElement */
  external checked : t_htmlElement => bool = "" [@@bs.get]; /* HTMLInputElement */
  external type_ : t_htmlElement => string = "" [@@bs.get]; /* HTMLStyleElement */
  external setType : t_htmlElement => string => unit = "type" [@@bs.set]; /* HTMLStyleElement */
  external rel : t_htmlElement => string = "" [@@bs.get]; /* HTMLLinkElement */
  external setRel : t_htmlElement => string => unit = "rel" [@@bs.set]; /* HTMLLinkElement */
  external href : t_htmlElement => string = "" [@@bs.get]; /* HTMLLinkElement, HTMLAnchorElement */
  external setHref : t_htmlElement => string => unit = "href" [@@bs.set]; /* HTMLLinkElement, HTMLAnchorElement */
};

/* TODO
module Tree (T: { type t; }) => {
  include ElementRe.Tree { type t = Type };
  include Impl { type t = Type };
};

include Tree { type t = Dom.htmlElement };
*/

include NodeRe.Impl { type t = Dom.htmlElement };
include EventTargetRe.Impl { type t = Dom.htmlElement };
include ElementRe.Impl { type t = Dom.htmlElement };
include Impl { type t = Dom.htmlElement };

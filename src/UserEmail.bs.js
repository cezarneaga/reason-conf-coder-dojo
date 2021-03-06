// Generated by BUCKLESCRIPT VERSION 3.0.0, PLEASE EDIT WITH CARE
'use strict';

var Curry = require("bs-platform/lib/js/curry.js");
var React = require("react");
var Js_json = require("bs-platform/lib/js/js_json.js");
var ReasonReact = require("reason-react/src/ReasonReact.js");
var ReasonApollo = require("reason-apollo/src/ReasonApollo.bs.js");
var Caml_exceptions = require("bs-platform/lib/js/caml_exceptions.js");

var Graphql_error = Caml_exceptions.create("UserEmail-ReactTemplate.GetEmail.Graphql_error");

var query = "query   {\nuser(login: \"cezarneaga\")  {\nemail  \n}\n}";

function parse(value) {
  var match = Js_json.decodeObject(value);
  if (match) {
    var value$1 = match[0]["user"];
    var match$1 = Js_json.decodeNull(value$1);
    var tmp;
    if (match$1) {
      tmp = /* None */0;
    } else {
      var match$2 = Js_json.decodeObject(value$1);
      var tmp$1;
      if (match$2) {
        var value$2 = match$2[0]["email"];
        var match$3 = Js_json.decodeString(value$2);
        var tmp$2;
        if (match$3) {
          tmp$2 = match$3[0];
        } else {
          throw Graphql_error;
        }
        tmp$1 = /* record */[/* email */tmp$2];
      } else {
        throw Graphql_error;
      }
      tmp = /* Some */[tmp$1];
    }
    return {
            user: tmp
          };
  } else {
    throw Graphql_error;
  }
}

function make() {
  return {
          query: query,
          variables: null,
          parse: parse
        };
}

function makeWithVariables() {
  return {
          query: query,
          variables: null,
          parse: parse
        };
}

function ret_type() {
  return /* module */[];
}

var MT_Ret = /* module */[];

var GetEmail = /* module */[
  /* Graphql_error */Graphql_error,
  /* query */query,
  /* parse */parse,
  /* make */make,
  /* makeWithVariables */makeWithVariables,
  /* ret_type */ret_type,
  /* MT_Ret */MT_Ret
];

var GetEmailQuery = ReasonApollo.CreateQuery([
      query,
      parse
    ]);

var component = ReasonReact.statelessComponent("Page");

function make$1() {
  return /* record */[
          /* debugName */component[/* debugName */0],
          /* reactClassInternal */component[/* reactClassInternal */1],
          /* handedOffState */component[/* handedOffState */2],
          /* willReceiveProps */component[/* willReceiveProps */3],
          /* didMount */component[/* didMount */4],
          /* didUpdate */component[/* didUpdate */5],
          /* willUnmount */component[/* willUnmount */6],
          /* willUpdate */component[/* willUpdate */7],
          /* shouldUpdate */component[/* shouldUpdate */8],
          /* render */(function () {
              var emailQuery = make(/* () */0);
              return ReasonReact.element(/* None */0, /* None */0, Curry.app(GetEmailQuery[/* make */3], [
                              /* Some */[emailQuery.variables],
                              /* None */0,
                              /* None */0,
                              /* None */0,
                              /* None */0,
                              /* None */0,
                              /* None */0,
                              /* None */0,
                              /* None */0,
                              (function (param) {
                                  var result = param[/* result */0];
                                  if (typeof result === "number") {
                                    if (result === 0) {
                                      return React.createElement("div", undefined, "Loading");
                                    } else {
                                      return React.createElement("div", undefined, "No Data");
                                    }
                                  } else if (result.tag) {
                                    var match = result[0].user;
                                    if (match) {
                                      return match[0][/* email */0];
                                    } else {
                                      return "No user";
                                    }
                                  } else {
                                    console.log(result[0]);
                                    return React.createElement("div", undefined, null);
                                  }
                                })
                            ]));
            }),
          /* initialState */component[/* initialState */10],
          /* retainedProps */component[/* retainedProps */11],
          /* reducer */component[/* reducer */12],
          /* subscriptions */component[/* subscriptions */13],
          /* jsElementWrapped */component[/* jsElementWrapped */14]
        ];
}

exports.GetEmail = GetEmail;
exports.GetEmailQuery = GetEmailQuery;
exports.component = component;
exports.make = make$1;
/* GetEmailQuery Not a pure module */

type user = {email: string};

module GetEmail = [%graphql
  {|
   {
    user (login:"cezarneaga")@bsRecord {
      email
    }
  }
|}
];

module GetEmailQuery = ReasonApollo.CreateQuery(GetEmail);

let component = ReasonReact.statelessComponent("Page");

let make = _children => {
  ...component,
  render: (_) => {
    let emailQuery = GetEmail.make();
    <GetEmailQuery variables=emailQuery##variables>
      ...(
           ({result}) =>
             switch (result) {
             | NoData => <div> (ReasonReact.string("No Data")) </div>
             | Loading => <div> (ReasonReact.string("Loading")) </div>
             | Error(error) =>
               Js.log(error);
               <div> ReasonReact.null </div>;
             | Data(response) =>
               switch (response##user) {
               | None => ReasonReact.string("No user")
               | Some(user) => ReasonReact.string(user.email)
               }
             }
         )
    </GetEmailQuery>;
  },
};
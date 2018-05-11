module GetIssues = [%graphql
  {|
  query {
    repository(owner: "facebook", name:"reason") {
    id
    issues(orderBy: {
      field: UPDATED_AT,
      direction: DESC
    },first:10) {
        nodes {
          id
          title
        }
      }
  }
  }
|}
];

module GetIssuesQuery = ReasonApollo.CreateQuery(GetIssues);

let component = ReasonReact.statelessComponent("Page");

let make = _children => {
  ...component,
  render: (_) => {
    let issuesQuery = GetIssues.make();
    <GetIssuesQuery variables=issuesQuery##variables>
      ...(
           ({result}) =>
             switch (result) {
             | NoData => <div> (ReasonReact.string("No Data")) </div>
             | Loading => <div> (ReasonReact.string("Loading")) </div>
             | Error(error) =>
               Js.log(error);
               <div> ReasonReact.null </div>;
             | Data(response) =>
               <ul>
                 (
                   switch (response##repository) {
                   | None => ReasonReact.string("None")
                   | Some(repository) =>
                     switch (repository##issues##nodes) {
                     | None => ReasonReact.string("None")
                     | Some(nodes) =>
                       nodes
                       |> Array.map(node =>
                            switch (node) {
                            | None => ReasonReact.string("None")
                            | Some(node) =>
                              <li key=node##id>
                                (ReasonReact.string(node##title))
                              </li>
                            }
                          )
                       |> ReasonReact.array
                     }
                   }
                 )
               </ul>
             }
         )
    </GetIssuesQuery>;
  },
};
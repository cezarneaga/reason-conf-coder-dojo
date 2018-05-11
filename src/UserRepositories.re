module GetRepositories = [%graphql
  {|
  query {
    viewer {
      repositories (first: 10){
        nodes {
          name
          viewerHasStarred
        }
      }
    }
  }
|}
];

module GetRepositoriesQuery = ReasonApollo.CreateQuery(GetRepositories);

let component = ReasonReact.statelessComponent("Page");

let make = _children => {
  ...component,
  render: (_) => {
    let repositoriesQuery = GetRepositories.make();
    <GetRepositoriesQuery variables=repositoriesQuery##variables>
      ...(
           ({result}) =>
             switch (result) {
             | NoData => <div> (ReasonReact.string("No Data")) </div>
             | Loading => <div> (ReasonReact.string("Loading")) </div>
             | Error(error) =>
               Js.log(error);
               <div> ReasonReact.null </div>;
             | Data(response) =>
               switch (response##viewer##repositories##nodes) {
               | None => ReasonReact.string("None")
               | Some(nodes) =>
                 <ul>
                   (
                     nodes
                     |> Array.map(node =>
                          switch (node) {
                          | None => ReasonReact.string("WHYYY")
                          | Some(node) =>
                            <li key=node##name>
                              (ReasonReact.string(node##name ++ " "))
                              (
                                node##viewerHasStarred ?
                                  ReasonReact.string({j|★|j}) :
                                  ReasonReact.string({j|☆|j})
                              )
                            </li>
                          }
                        )
                     |> ReasonReact.array
                   )
                 </ul>
               }
             }
         )
    </GetRepositoriesQuery>;
  },
};
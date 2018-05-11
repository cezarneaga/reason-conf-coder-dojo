ReactDOMRe.renderToElementWithId(
  <ReasonApollo.Provider client=Client.instance>
    <UserEmail />
  </ReasonApollo.Provider>,
  "index1",
);

ReactDOMRe.renderToElementWithId(
  <ReasonApollo.Provider client=Client.instance>
    <UserRepositories />
  </ReasonApollo.Provider>,
  "index2",
);

ReactDOMRe.renderToElementWithId(
  <ReasonApollo.Provider client=Client.instance>
    <OpenIssues />
  </ReasonApollo.Provider>,
  "index3",
);
/* Create an InMemoryCache */
let inMemoryCache = ApolloInMemoryCache.createInMemoryCache();

/* Create an HTTP Link and add the token*/
let httpLink =
  ApolloLinks.createHttpLink(
    ~uri="https://api.github.com/graphql",
    ~headers=
      Js.Json.object_(
        Js.Dict.fromList([
          ("Authorization", Js.Json.string("bearer token")),
        ]),
      ),
    (),
  );

let instance =
  ReasonApollo.createApolloClient(~link=httpLink, ~cache=inMemoryCache, ());
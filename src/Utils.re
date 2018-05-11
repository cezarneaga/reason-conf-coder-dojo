let (|?>) = (fn, opt) =>
  switch (opt) {
  | None => None
  | Some(value) => fn(value)
  };

let (|?>>) = (fn, opt) =>
  switch (opt) {
  | None => None
  | Some(value) => Some(fn(value))
  };

let (|?) = (opt, default) =>
  switch (opt) {
  | None => default
  | Some(value) => value
  };
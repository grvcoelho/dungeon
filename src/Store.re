type t('action, 'state) = {
  mutable state: 'state,
  mutable reducer: ('state, 'action) => 'state
}

let create = (~initialState, ~reducer, ()) => {
  state: initialState,
  reducer,
}

type t('action, 'state) = {
  mutable state: 'state,
  mutable reducer: ('state, 'action) => 'state
}

let create = (~initialState, ~reducer) => {
  state: initialState,
  reducer,
}

let dispatch = (store, action) => 
  store.state = store.reducer(store.state, action)

let getState = store => store.state

type cardKind = Attack | Skill | Power
type cardRarity = Normal | Uncommon | Rare
type cardTarget = Self | Enemy | AllEnemies

type effect = int => int

type card = {
  name: string,
  cost: int,
  kind: cardKind,
  rarity: cardRarity,
  target: cardTarget,
  effects: list(effect),
} 

type hero = {
  name: string,
  hp: int,
  cards: array(card),
}

type enemy = {
  name: string,
  hp: int,
  intentions: list(effect),
}

let strike: card = {
  name: "Strike",
  cost: 1,
  rarity: Normal,
  target: Enemy,
  kind: Attack,
  effects: [
    (a) => a,
  ]
}

let defend: card = {
  name: "Defend",
  cost: 1,
  rarity: Normal,
  target: Self,
  kind: Skill,
  effects: [
    (a) => a,
  ]
}

let knight = {
  name: "Knight",
  hp: 80,
  cards: [|
    strike,
    defend,
  |]
}

let gargoyle = {
  name: "Gargoyle",
  hp: 30,
  intentions: [
    (a) => a,
  ]
}

type state = {
  mutable counter: int
}

let initialState = {
  counter: 0
}

type action = 
  | Increment
  | IncrementBy(int)
  | Decrement

let reducer = (state, action) => 
  switch (action) {
    | Increment => {
      state.counter = state.counter + 1
      state
    }

    | IncrementBy(n) => {
      state.counter = state.counter + n
      state
    }

    | Decrement => {
      state.counter = state.counter - 1
      state
    }
  }

let store = Store.create(~initialState, ~reducer)

Store.dispatch(store, Increment)
Store.dispatch(store, Increment)
Store.dispatch(store, Increment)
Store.dispatch(store, IncrementBy(10))
Store.dispatch(store, Decrement)

Js.log(Store.getState(store))

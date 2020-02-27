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
  mutable counter: int,
}

type action = 
  | Increment
  | Decrement

let initialState = {
  counter: 1,
}

let reducer = (state, action) => {
  switch (action) {
    | Increment => {
      state.counter = state.counter + 1
      state
    }

    | Decrement => {
      state.counter = state.counter - 1
      state
    }  
  }
}

let store = Store.create(~initialState, ~reducer)

Js.log(store)
// Js.log((knight, gargoyle))

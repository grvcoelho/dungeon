let strike: Card.t = {
  name: "Strike",
  cost: 1,
  damage: 9,
  block: 0,
  kind: Attack,
  rarity: Common,
}

let defend: Card.t = {
  name: "Defend",
  cost: 1,
  damage: 0,
  block: 8,
  kind: Skill,
  rarity: Common,
}

let flare: Card.t = {
  name: "Flare",
  cost: 0,
  damage: 4,
  block: 3,
  kind: Attack,
  rarity: Uncommon,
}

let deck: Deck.t = [
  strike,
  defend,
  flare,
]

let emptyDeck: Deck.t = []

let pickRandom = list => List.nth(list, Random.int(List.length(list)))

let (card, newDeck) = Deck.draw(pickRandom, emptyDeck)

Js.log(card)
Js.log(Array.of_list(newDeck))

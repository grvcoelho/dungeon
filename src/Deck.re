type t = list(Card.t)
type cardPicker = t => Card.t

let without = element => switch (element) {
  | Some(element) => List.filter(e => e !== element)
  | None => (x) => x
}

let draw = (cardPicker, deck) => {
  let card = switch (deck) {
    | [] => None
    | deck => Some(cardPicker(deck))
  }

  let newDeck = without(card, deck); 

  (card, newDeck)
}

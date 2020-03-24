type kind = Attack | Skill | Power
type rarity = Common | Uncommon | Rare

type t = {
  name: string,
  cost: int,
  damage: int,
  block: int,
  kind,
  rarity,
}

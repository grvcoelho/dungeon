# dungeon
:dragon: An attempt at a dungeon rogue-like deck game

## Entities, Capabilities and Concepts

- **Energy**: used to play cards, renewed every **turn**
- **Cards:** can be played to many effects (attacking, blocking, applying debuffs, etc)
- **Relics:** provide the same effects of cards but passively
- **Hero:** they have Health Points, Energy, a default deck, starting relic, etc
- **Enemies**: they have health, rarity (chance of facing off), **intentions** (which can be the same effects of cards
- **Deck**: the group of cards a one has in a run. Cards can be added and removed. In a **fight** cards are shuffled into and drawn from the **draw pile** and discarded on the **discard pile**
- **Hand:** the cards one is currently holding
- **Floor**: can hold a fight or event
- **Fight**: an enemy face-off

### Card Props

- Name 
- Cost (of energy)
- Rarity
- Upgrade properties: cards can be upgraded and have their properties changed
- Target: cards can target the enemy, the hero itself
- **Effects**: a card can have many effects and these effects can also be influenced by external conditions (such as debuffs, enemy intent, etc)

### Card Effects

- Attack Damage: damage an enemy with one or more attacks
- Block: add block to the character. It lasts until the start of the next turn
- Buffs & Debuffs: can apply some buffs or debuffs to the character or enemies

### Enemies

* Like heroes they have name, max HP, etc
* They can have different **intentions** (just like card effects) with different probabilities and patterns

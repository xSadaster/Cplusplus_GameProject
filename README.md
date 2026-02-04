# C++ Game project made by
## Kalle, Papu & Akseli

# To play: Download the .Game.exe and run it

## Controls
Use **q** in map or combat for a prompt to exit the program.
Use **wasd** to move in the map.

The goal is to beat the boss in the bottom right corner.
You may need to kill some enemies for a chance to gain extra potions,
or maybe converse with a.. suspicious shopkeeper to gain attack power in exchange for something.
Good luck.

Enemies have a slight chance of spawning in the forest e.g. green ('A') ~1% chance 
but mainly do it on the bridges ('H'). ~75%
Drinking a potion or checking enemy stats doesn't take your "turn" in combat.

# This project was developed as part of a school assignment to practice C++ programming and uses the following methods.

Class Design & OOP (Object-oriented programming) Hierarchy.
Abstract base class: GameComponent (Purely virtual).
Concrete derived class: Character (not used directly).
Further subclasses: Player (and its variants: Tank, Warrior, Berserker),
Enemy, that inherited Character and (and the variant: Boss)

All classes used constructors, default and parameterized and destructors.
Attack and Health were encapsulated as private members and had setters/getters.
Player name was protected as well.

Polymorphism
Virtual functions (show(), act()) were overridden in derived classes.

Operator Overloading
Overloaded << to display enemy stats with cout in combat.
Overloaded + and - for Player to allow stat changes in the “shop”

Constructors & Destructors
All main classes have both default and parameterized constructors (with default values).
Destructors are defined for proper cleanup.

Dynamic Object Creation
The player character is created dynamically using new based on user input/class selection.

Data Structures
The map was stored as a fixed-size array.
A map was used to track how many of each enemy types the player had defeated, and was
displayed at the end of the game.
Tile properties were stored in structs.

Gameplay Features
Turn-based combat with random enemy encounters.
(The boss wasn’t randomized)
Potions for healing (acquired via RNG (Random number generation) after combat).
Shop tile where the player could trade HP for ATK.
Map data structure for displaying defeated enemy types and counts.
Boss fight as the win condition.

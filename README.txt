//----------------------------------------------------------------------
Title:
War Of Empires


Student Info:
name : Marwan Taha (marwanta)
ID: #########
name : Hassan Yousif (hassanyo)
ID: #########
name : Omar Yousif (omaryo)
ID: #########


//----------------------------------------------------------------------
General Introduction:
Students have been alloud to pick a game by their liking, get the
teachers to accept it, and redo the game as OOP as they have learned so
far.

//-----------------------------------------------------------------------
prensentation of the game we picked:

The massively popular web game "Age of War" has been remastered for
the best mobile experience.

Take control of a number of different units and a number of different
turrets to defend your base and destroy your enemy.
There is a time limit on each unite spawn based on its value.
Requires gold to spawn new unites, enemy kills give experience
and Gold according to enemy unit value.
Gaining experience unlocks a new Era, which has stronger units to send
to battle.
The stronger army advances over his enemy, when there isnt any enemy
unites left to fight, ally unites walk to the front of the enemy castle,
and start attackingit, when the enemy castle reaches 0, the other team
wins.

In this game, you start at the caveman age, then evolve! There are
a total of n ages, each with its own unique units and turrets.
Can you advance faster than your enemy?

Tools to use:
planning to use the SFML library, and possibly a little bit of OpenGL.

Link to the game:
https://www.y8.com/games/age_of_war

//----------------------------------------------------------------------
Design:

The game was built upon one match, which we choose as such to save us 
from great lacking in graphics. But we certainly did harden up the Enemy
side to make for a scaling game.

This one match describes above, is a fight between two Emprires, one
to the right, one to the left. The left Empire is on the player's side,
which the player can control via the UserInterface. While the left
Empire is the Enemy Empire, controlled by a class called AI( by
controlling the enemy decisions, the class AI is what controlls the
pace of the match).

Each Empire has 2 type of melee fighters, and 4 types of range fighters
including a tank. The empire can pay money to these fighters to send
them to battle. Each fighter has different set fo health, damage, and 
attack range when necessary. The classes are prepared to get leveled up
but there was no time to implement those functionalities within the 
UserInterface.

Each Empire also has a Special ability, which is sending a Kite
Balloon towards Enemy Empire. On its way, The KiteBalloon drops a bomb
every 5+(rand()%20)/10) secounds, each bomb carries a certain amount
of damage, and damages any enemy fighters which it hits.

In Addition, Each Empire also has 2 sets of turrets, which has a pixel
range to attack enemy fighters who gets close to ally castle. with an
option to pay extra money to update The turrets.

Over Time, The enemy Empire levels up the abilities of it's fighters
and KiteBallon, which increases damage, health, and sometimes the 
animation of the objects (such as the KiteBalloon, its bombs, and its
explosions.)

Which ever side gets his enemy castle's health below or equals to 0,
wins the match, the player gets informed of who won the match, and the 
player goes back to the menu of the game, where he can either exit 
or play again.

//----------------------------------------------------------------------
The program files are included below:
 1. AI.h/.cpp, controls Enemy Castle tactic descisions.

 2. AirUnites.h/.cpp, father of classes AirBomb and Bullet, which are
    objects that deal damage to enemy Units if it touches any.

 3. WorldObject.h/.cpp, contains a class which is the base for any 
    visible Object within the game.

 4. AnimatedObject.cpp/.h - contains a base class for any Object that
    framable animations, such as Fighter, AirUnits, KiteBalloon, Turrets.
 
 5. LiveObject.h/.cpp, contains a base class for any Object that has
    a health score, such as Fighter, and Castle, KiteBalloon.

 6. MeleeFighter.h/.cpp, contains base class for MeleeFighter1&2,
    where are classes for fighters with melee attacking strategy.

 7. RangeFighter.h/.cpp, contains base class for RangeFighter1&2&3&4,
    where are classes for fighters with range attacking strategy.

 8. GunFire.h/.cpp, contains class that animates the firing of range
    fighters attacks.
 
 9. BuyWorldObject.h/.cpp, contains the base class for classes that
    support buying game units. Derived classes are: BuyFighter,
    BuyTurret.
    used in the UserInterface and Menu, such as 

 10.Button.h/.cpp contains a base class for BuyButton which is used
    for the user interface, or in other words UI.

 11.CastleHealthBar.h/.cpp, CastleHealthBarBackground.h/.cpp, 
    CastleHealthBarFilled.h/.cpp - contains classes that make the 
    health bar of the castle of each Empire.

 12.Empire.h/.cpp constains a class which contains all objects that
    belong to the Empire, such as Castle, Fighters, AirUnites,
    KiteBalloon, and money.

 13.Textures.h/.cpp contains a singerlton class of all textures of 
    the game..

 14.Levels.h/.cpp contains a singleton class of all Levels of types
    of scalable objects of the game.

 15.Floor.h/.cpp contains a class of a static object, derived from 
    WorldObject.

 16.Animation.h/.cpp contains a base class for all Animation classes
    such as FireAnimation of the GunFire object, 
    FighterAnimation class for Fighters animations,
    TurretAnimation class for Turret animations,
    KiteBalloonAnimation class for KiteBalloon animations,
    AirBombAnimation class for AirBomb animations.

 17.Turret.h/.cpp - contains base class for turrets1&2&3.

 18.UIObject.h/.cpp & InGameUI.h/.cpp - classes responsible for UI.

 
 CMakeLists for each folder.

 and other folders which are the concern of the compiler: 
	- .vs
	- out 
//----------------------------------------------------------------------

the main data structures, and their roles:

a list for spauned fighters, saved as a private member of class Empire
a list of spauned AirUnits, saved in class Empire

//----------------------------------------------------------------------

Algorithms worth menssioning:

- the moving algorithm of AirBombs: as each bomb is falling from the sky,
you can notice the effect of the law of gravity algorithm by Newton, on
the vertical movement (y),
as well as air resistance on horisontal movement (x).

- a visible rotation of the turrets towards the target is done by an
algorithm that uses sin and cos functions to calculate corner 
measurements necessary for the rotation, and then apply is using Sprite
rotation functions.

- the class AI contains an algorithm than runs The enemy disicions, and
thus controls the course of the game.

//----------------------------------------------------------------------

known bugs:
 
//----------------------------------------------------------------------

Other Notes:
We have prepared leveling up functions for each and every Fighter type
, which levels up their health, damage and attack range, we have applied
the leveling up options on the AI Empire, but did not have time to add 
this feature to the UserInterface, so that the human player can use it
too.
 
//----------------------------------------------------------------------
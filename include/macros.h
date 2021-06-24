#pragma once

const float PI = 3.14159265;

const int INIT_MONEY = 4000;

// Castle Indexes:
const int CASTLE_X_INDEX = 0;
const int CASTLE_Y_INDEX = 1015;

// dead or alive function check resturns:
const bool DEAD = false;
const bool ALIVE = true;

// object speeds:
const float MAX_MOVEMENT_SPEED = 50;  // move one pixel every 50 millisec = (1000/50 = 20) pixels each 1 sec
const float MIN_MOVEMENT_SPEED = 500;
const float MAX_ATTACK_SPEED = 333;   // attack one time every 333 millisec = (1000/333 = 3) hits each 1 sec
const float MIN_ATTACK_SPEED = 3000;
const float FIGHTER_MOVEMENT_SPEED = 5;

// teams:
const bool LEFT_TEAM = true;
const bool RIGHT_TEAM = false;

// melee char macors:
const int DAMAGING_FRAME = 9;
const int RANGE_DAMAGING_FRAME = 3;
const int MELEE_DIE_FRAME = 25;

// objects default health
const int CASTLE_MAX_HEALTH = 10000,
CASTLE_HEALTH = 10000;

const float ANIMATION_SWITCH_TIME = 0.065f,
SPEED = 0.1f;

const int NUM_OF_FIRE_ANIMATION_FRAMES = 10;

// bomb consts
const int BOMB_DAMAGE = 250;

// tower range
const int TOWER_RANGE = 400;

// fighters health
const int MELEE_1_HEALTH = 100;
const int MELEE_2_HEALTH = 200;
const int RANGE_1_HEALTH = 80;
const int RANGE_2_HEALTH = 160;
const int RANGE_3_HEALTH = 240;
const int RANGE_4_HEALTH = 500;

// fighters damage
const int MELEE_1_DAMAGE = 20;
const int MELEE_2_DAMAGE = 30;
const int RANGE_1_DAMAGE = 30;
const int RANGE_2_DAMAGE = 40;
const int RANGE_3_DAMAGE = 50;
const int RANGE_4_DAMAGE = 80;

// fighters gold Worth
const int MELEE_1_WORTH = 100;
const int MELEE_2_WORTH = 200;
const int RANGE_1_WORTH = 125;
const int RANGE_2_WORTH = 200;
const int RANGE_3_WORTH = 300;
const int RANGE_4_WORTH = 600;

//time
const int WAVE = 100;

const int BALLOON_TIME = 4;

const int NUM_OF_SOUNDS = 4;
enum class SoundType {

	MenuMusic,
	InGameMusic,
	ShootSoundEffect,
	ExplosionSoundEffect,

};

const int NUM_OF_WORLD_OBJECT_TYPES = 3;
enum class WorldObjectType {

	MatchBackground,
	Floor,
	Castle,

};

const int NUM_OF_FIGHTER_TYPES = 6;
enum class FighterType {

	Tank1,
	Tank2,

	Shooter1,
	Shooter2,
	Shooter3,

	Tank3,

	Nothing
};

const int TURETT1_PRICE = 1200,
TURETT2_PRICE = 2200,
TURETT3_PRICE = 3500;

const int NUM_OF_TURETTS_STANDS = 2;
const int NUM_OF_TURETT_TYPES = 3;
enum class TurettType {

	Turett1,
	Turett2,
	Turett3,

};

const int NUM_OF_ANIMATION_TYPES = 4;
enum class AnimationType {

	Idle,
	Walk,
	Die,
	Attack,		// just Tank1 and Tank2 have this animation

};

const int NUM_OF_UI_TEXTURES = 8;
enum class UITexture {

	MenuBackground,
	StartButton,
	ExitGameButton,
	ActiveButton,
	UnactiveButton,
	BuyWorldObjectBackground,
	CastleHealthbar,
	CastleHealthbarBackground,

};
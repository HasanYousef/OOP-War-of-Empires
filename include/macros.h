#pragma once

const float ANIMATION_SWITCH_TIME = 0.2,
SPEED = 0.1f;

const int NUM_OF_SOUNDS = 2;
enum class SoundType {
	MenuMusic,
	InGameMusic,
};

const int NUM_OF_WORLD_OBJECT_TYPES = 0;
enum class WorldObjectType {

};

const int NUM_OF_FIGHTER_TYPES = 0;
enum class FighterType {

};

const int NUM_OF_ANIMATION_TYPES = 4;
enum class AnimationType {
	Idle,
	Walk,
	Attack,
	Die,
};

const int NUM_OF_UI_TEXTURES = 4;
enum class UITexture {

	MenuBackground,
	MatchBackground,

	StartButton,
	ExitGameButton,

};
#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <SDL.h>

const unsigned int WINDOW_WIDTH{ 800 };
const unsigned int WINDOW_HEIGHT{ 600 };

// set fps for monitor refresh rate
// consider making this variable
const unsigned int FPS{ 144 };
const unsigned int FRAME_TARGET_TIME{ 1000 / FPS };

enum CollisionMask
{
	PLAYER = 1,
	ENEMY = 2,
	PROJECTILE = 4,
	VEGITATION = 8
};

enum CollisionType
{
	NO_COLLISION = 0,
	PLAYER_ENEMY_COLLISION = PLAYER | ENEMY, // 0001 | 0010 =  0011 (3)
	PLAYER_PROJECTILE_COLLISION = PLAYER | PROJECTILE, // 0001 | 0100 =  0101 (5)
	ENEMY_PROJECTILE_COLLISION = ENEMY | PROJECTILE, //0010 | 0100 = 0110 (6)
	PLAYER_VEGITATION_COLLISION = PLAYER | VEGITATION, // 1000 | 0001 = 1001 (9)
	// ... continue adding as many as you need (prob use unsinged longs though)
};

enum LayerType
{
	TILEMAP_LAYER = 0,
	VEGETATION_LAYER = 1,
	ENEMY_LAYER = 2,
	OBSTACLE_LAYER = 3,
	PLAYER_LAYER = 4,
	PROJECTILE_LAYER = 5,
	UI_LAYER = 6
};

const unsigned int NUM_LAYERS = 6;

const SDL_Color WHITE_COLOR = { 255, 255, 255, 255 };
const SDL_Color GREEN_COLOR = { 0, 255, 0, 255 };

#endif // !CONSTANTS_H
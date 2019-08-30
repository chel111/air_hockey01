#pragma once
#include "Defines.h"
#include "Object.h"
#include "Game_Manager.h"

class PhysicEngine
{
public:
	static int checkBorderCollision(Object* puck);
	static Object* checkMalletCollision(Game_Manager& game_Manager);
	static void handleBorderCollision(Game_Manager& gm, int _BORDER);
	static void handleMalletCollision(Object* puck, Object* mallet);
	static void onLoop(Object* puck);
};


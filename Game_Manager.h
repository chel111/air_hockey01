#pragma once

#include <memory>
#include "Object.h"



class Game_Manager
{
private:
	std::unique_ptr<Object> player_mallet, AI_mallet, puck;
	int player_score, AI_score;

public:
	Game_Manager(Object* _puck, Object* _player_mallet, Object* AI_mallet);
	void initObjects(SDL_Renderer* renderer);
	void renderObjects(SDL_Renderer* renderer);

	void setPlayerMalletCoordinates(const int& x, const int& y);
	void setPlayerMalletVelocity(const int& xPrev, const int& yPrev);

	void onLoop();

	void incPlayerScore();
	void incAIScore();

	int getPlayerScore();
	int getAIScore();


	Object* getPuck();
	Object* getPlayerMallet();
	Object* getAIMallet();

};


#include "Game_Manager.h"
#include "Defines.h"



Game_Manager::Game_Manager(Object* _puck, Object* _player_mallet, Object* _AI_mallet):
	puck(_puck), player_mallet(_player_mallet), AI_mallet(_AI_mallet)
{
	player_score = AI_score = 0;
}


void Game_Manager::initObjects(SDL_Renderer* renderer)
{
	player_mallet->getTexture().loadFromFile("images/mallet.png", renderer);
	AI_mallet->getTexture().loadFromFile("images/mallet.png", renderer);
	puck->getTexture().loadFromFile("images/puck.png", renderer);

	player_mallet->changeX(MIDDLE_OF_FIELD_OX);
	player_mallet->changeY(MIDDLE_OF_FIELD_OY / 5 * 8);


	AI_mallet->changeX(MIDDLE_OF_FIELD_OX);
	AI_mallet->changeY(MIDDLE_OF_FIELD_OY / 5);

	puck->changeX(MIDDLE_OF_FIELD_OX);
	
	//set y near to user
	puck->changeY(MIDDLE_OF_FIELD_OY + 200);

}


void Game_Manager::renderObjects(SDL_Renderer* renderer)
{
	int malletRadius = player_mallet->getTexture().getWidth() / 2;
	player_mallet->getTexture().render(renderer, player_mallet->getX() - malletRadius, player_mallet->getY() - malletRadius);
	AI_mallet->getTexture().render(renderer, AI_mallet->getX() - malletRadius, AI_mallet->getY() - malletRadius);
	puck->getTexture().render(renderer, puck->getX() - puck->getTexture().getWidth() / 2, puck->getY() - puck->getTexture().getWidth() / 2);
}


void Game_Manager::setPlayerMalletCoordinates(const int &x,const int &y)
{
	int radius = player_mallet->getTexture().getWidth();
	if (x > LEFT_BORDER + radius / 2 && x < RIGHT_BORDER - radius / 2)
	{
		player_mallet->setX(x);
	}

	if (y > MIDDLE_OF_FIELD_OY && y < BOTTOM_BORDER - radius / 2)
	{
		player_mallet->setY(y);
	}
}

void Game_Manager::setPlayerMalletVelocity(const int& xPrev, const int& yPrev)
{
	player_mallet->setVx(player_mallet->getX() - xPrev);
	player_mallet->setVy(player_mallet->getY() - yPrev);
}


void Game_Manager::onLoop()
{
	puck->changeX(puck->getVx());
	puck->changeY(puck->getVy());



	AI_mallet->changeX(AI_mallet->getVx());
	AI_mallet->changeY(AI_mallet->getVy());
}





void Game_Manager::incPlayerScore()
{
	++player_score;
}

void Game_Manager::incAIScore()
{
	++AI_score;
}





///geters

int Game_Manager::getPlayerScore()
{
	return player_score;
}

int Game_Manager::getAIScore()
{
	return AI_score;
}

Object* Game_Manager::getPuck()
{
	return puck.get();
}

Object* Game_Manager::getPlayerMallet()
{
	return player_mallet.get();
}

Object* Game_Manager::getAIMallet()
{
	return AI_mallet.get();
}
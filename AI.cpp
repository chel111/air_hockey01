#include "AI.h"


void AI::setAIVelocity(Object* mallet, Object* puck, int BOT_LEVEL)		//set velocity to stupid bot
{
	mallet->setVx(puck->getX() >= mallet->getX() ? BOT_LEVEL : -BOT_LEVEL);
	if (mallet->getY() > puck->getY())
	{
		mallet->setVy(mallet->getVy() - 0.2);
		return;
	}
	if (puck->getY() < MIDDLE_OF_FIELD_OY && abs(puck->getVy()) <= 5)
	{
		mallet->setVy(mallet->getVy() + 0.2);
	}
	PhysicEngine::checkBorderCollision(mallet);
}
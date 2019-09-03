#include "AI.h"

void AI::setAIVelocity(Object* AI_mallet, Object* puck, int BOT_LEVEL)		//set velocity to stupid bot
{
	//mallet->setVx(puck->getX() >= mallet->getX() ? BOT_LEVEL : -BOT_LEVEL);
	//if (mallet->getY() > puck->getY())
	//{
	//	mallet->setVy(mallet->getVy() - 0.2);
	//	return;
	//}
	//if (puck->getY() < MIDDLE_OF_FIELD_OY && abs(puck->getVy()) <= 5)
	//{
	//	mallet->setVy(mallet->getVy() + 0.2);
	//}
	//PhysicEngine::checkBorderCollision(mallet);


	//movement on Ox
	if (puck->getX() + BOT_LEVEL > AI_mallet->getX())
	{
		AI_mallet->setVx(BOT_LEVEL);
		AI_mallet->changeX(AI_mallet->getVx());
	}
	else if (puck->getX() - BOT_LEVEL < AI_mallet->getX())
	{
		AI_mallet->setVx(-BOT_LEVEL);
	}
	AI_mallet->setVx(puck->getX() >= AI_mallet->getX() ? BOT_LEVEL : -BOT_LEVEL);
	

	//try2
	if (puck->getY() < MIDDLE_OF_FIELD_OY)
	{
		if (sqrt(pow(puck->getVx(), 2) + pow(puck->getVy(), 2)))
		{
			if (puck->getY() < AI_mallet->getY())
			{
				AI_mallet->setVy(-BOT_LEVEL);
			}
	 		else
			{
				AI_mallet->setVy(BOT_LEVEL);
			}
		}
	}
	else
	{
		if (AI_mallet->getY() <= DEFEND_ZONE)
		{
			AI_mallet->setY(DEFEND_ZONE);
			AI_mallet->setVy(0);
		}
		else
		{
			AI_mallet->setVy(-BOT_LEVEL);
		}
	}

	if (AI_mallet->getY() >= MIDDLE_OF_FIELD_OY)
	{
		AI_mallet->setY(MIDDLE_OF_FIELD_OY);
		//AI_mallet->setVy(0);
	}

	////movement on Oy
	//if (puck->getY() < MIDDLE_OF_FIELD_OY && sqrt(pow(puck->getVx(), 2) + pow(puck->getVy(), 2)) <= 4)
	//{
	//	if (puck->getY() > AI_mallet->getY())
	//	{
	//		AI_mallet->setVy(BOT_LEVEL);
	//	}
	//	else
	//	{
	//		AI_mallet->setVy(-BOT_LEVEL);
	//	}
	//	
	//	
	//	//AI_mallet->setVx(1);
	//}
	//else
	//{
	//	AI_mallet->setVy(-2);
	//}


	//
	//if (abs(AI_mallet->getY() - puck->getY()) <= 5)
	//{
	//	AI_mallet->setVy(0);
	//}
	//else if (AI_mallet->getY() > puck->getY())
	//{
	//	AI_mallet->setVy(-5);
	//	//AI_mallet->setVx(1);
	//}

}
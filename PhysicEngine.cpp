#include "PhysicEngine.h"
#include "Sound_Manager.h"
#include <cmath>


double getProjection(double V1x, double V1y, double V2x, double V2y);	//returns proection of vector V1 on vector V2


int  PhysicEngine::checkBorderCollision(Object *puck)			//check if the puck has collided with border
{
	if (puck->getX() <= LEFT_BORDER + puck->getTexture().getWidth() / 2)
	{
		puck->setX(LEFT_BORDER + puck->getTexture().getWidth() / 2);
		return LEFT_BORDER;
	}
	if (puck->getX() >= RIGHT_BORDER - puck->getTexture().getWidth() / 2)
	{
		puck->setX(RIGHT_BORDER - puck->getTexture().getWidth() / 2);
		return RIGHT_BORDER;
	}
	if (puck->getY() <= TOP_BORDER + puck->getTexture().getHeight() / 2)
	{
		if (puck->getX() >= LEFT_CROSSBAR && puck->getX() <= RIGHT_CROSSBAR) return PLAYER_GOAL;
		puck->setY(TOP_BORDER + puck->getTexture().getHeight() / 2);
		return TOP_BORDER;
	}
	if (puck->getY() >= BOTTOM_BORDER - puck->getTexture().getHeight() / 2)
	{
		if (puck->getX() >= LEFT_CROSSBAR && puck->getX() <= RIGHT_CROSSBAR) return AI_GOAL;
		puck->setY(BOTTOM_BORDER - puck->getTexture().getHeight() / 2);
		return BOTTOM_BORDER;
	}
	return 0;
}

void PhysicEngine::handleBorderCollision(Game_Manager &gm, int _BORDER)		//handling collision the puck with _BORDER
{
	Object* puck = gm.getPuck();
	switch (_BORDER)
	{
		case LEFT_BORDER: case RIGHT_BORDER:
		{
			puck->setVx(-puck->getVx() * 0.95);
			puck->changeX(puck->getVx());
			break;
		}
		case TOP_BORDER: case BOTTOM_BORDER:
		{
			puck->setVy(-puck->getVy() * 0.95);
			puck->changeY(puck->getVy());
			break;
		}
		case PLAYER_GOAL:
		{
			gm.incPlayerScore();
			puck->setX(MIDDLE_OF_FIELD_OX - puck->getTexture().getWidth() / 2);
			puck->setY(MIDDLE_OF_FIELD_OY - puck->getTexture().getHeight() / 2);
			puck->setVx(0);
			puck->setVy(0);
			gm.getAIMallet()->setY(80);
			break;
		}
		case AI_GOAL:
		{
			gm.incAIScore();
			puck->setX(MIDDLE_OF_FIELD_OX - puck->getTexture().getWidth() / 2);
			puck->setY(MIDDLE_OF_FIELD_OY - puck->getTexture().getHeight() / 2);
			puck->setVx(0);
			puck->setVy(0);
			gm.getAIMallet()->setY(80);
			break;
		}
	}
}

Object* PhysicEngine::checkMalletCollision(Game_Manager& game_Manager)		//Check if the puck has collided with one of mallets
{
	Object* puck = game_Manager.getPuck(), *playerMallet = game_Manager.getPlayerMallet(), *AIMallet = game_Manager.getAIMallet();
	double malletRadius = playerMallet->getTexture().getWidth() / 2.0, puckRadius = puck->getTexture().getWidth() / 2.0;

	//playerMallet & puck
	double puckPlayerDistance = sqrt(pow((puck->getX() - playerMallet->getX()), 2) + pow((puck->getY() - playerMallet->getY()), 2));
	if (puckPlayerDistance <= puckRadius + malletRadius)
	{
		//puck->correctionToMallet(playerMallet);
		return playerMallet;
	}

	//AIMallet & puck
	double puckAIDistance = sqrt(pow((puck->getX() - AIMallet->getX()), 2) + pow((puck->getY() - AIMallet->getY()), 2));
	if (puckAIDistance <= puckRadius + malletRadius)
	{
		//puck->correctionToMallet(AIMallet);
		return AIMallet;
	}

	return nullptr;
}


void PhysicEngine::onLoop(Object* puck)				//Slowing the puck down
{
	double Vx = puck->getVx(), Vy = puck->getVy();
	if (Vx == 0 && Vy == 0)
	{
		puck->setVx(Vx);
		puck->setVy(Vy);
		return;
	}
	double temp = (sqrt(pow(Vx, 2) + pow(Vy, 2)) + ACCELERATION) / sqrt(pow(Vx, 2) + pow(Vy, 2));
	puck->setVx((temp * Vx));
	puck->setVy((temp * Vy));
}

void PhysicEngine::handleMalletCollision(Object* puck, Object* mallet)			//handling collision puck and mallet
{

	//
	////vector between centers (new Ox)
	//double OOx = puck->getX() - mallet->getX(),
	//	OOy = puck->getY() - mallet->getY();

	////normal (new Oy)
	//double OONormalX = -OOy, OONormalY = -OOx;


	////projections of vectors V to new axises
	//double puckVx = getProjection(puck->getVx(), puck->getVy(), OOx, OOy), puckVy = getProjection(puck->getVx(), puck->getVy(), OONormalX, OONormalY),
	//	malletVx = getProjection(mallet->getVx(), mallet->getVy(), OOx, OOy);
	//
	//
	////projection on new Oy will be constant

	////calculating new Ox projections for puck
	////double newPuckVx = ((puck->getWeight() - mallet->getWeight())* puckVx + 2*mallet->getWeight() * malletVx)/(mallet->getWeight() + puck->getWeight());

	//double newPuckVx = malletVx;


	///*getting projections at old axises
	//1.Finding angle between newPuckV and newOx
	//2.Finding angle between newOx and Ox
	//3.Sum this angles
	//4.Find projection of newPuckVx on Ox with cos
	//*/

	////1
	//double angleNewPuckV = atan(puckVy / newPuckVx);

	////2
	//double angleBetweenOx = atan(OOy / OOx);

	////3
	//angleNewPuckV += angleBetweenOx;

	////4
	//double newPuckVRange = sqrt(pow(newPuckVx, 2) + pow(puckVy, 2));
	//puck->setVx(newPuckVRange * cos(angleNewPuckV));
	//puck->setVy(newPuckVRange * sin(angleNewPuckV));
	//puck->changeX(puck->getVx());
	//puck->changeY(puck->getVy());


	////////////////////////////////////////////////////////

	double OOx = puck->getX() - mallet->getX(),
		OOy = puck->getY() - mallet->getY();
	
	//puck V = prejection mallet V on OO
	double puckVx = getProjection(mallet->getVx(), mallet->getVy(), OOx, OOy);
	double OOLength = sqrt(pow(OOx, 2) + pow(OOy, 2));


	puck->setVx(OOx / OOLength * puckVx);
	puck->setVy(OOy / OOLength * puckVx);

	puck->changeX(puck->getVx());
	puck->changeY(puck->getVy());
}


double getProjection(double V1x, double V1y, double V2x, double V2y)		//returns proection of vector V1 on vector V2
{
	return (V1x * V2x + V1y * V2y) / sqrt(pow(V2x, 2) + pow(V2y, 2));	
}




#include "Puck.h"


void Puck::correctionToMallet(Mallet* mallet)
{
	double OOx = x - mallet->getX(), OOy = y - mallet->getY(), OOLenght = sqrt(pow(OOx, 2) + pow(OOy, 2));
	x = mallet->getX() + OOx * (mallet->getTexture().getWidth() / 2 + texture.getWidth() /2) / OOLenght;
	y = mallet->getY() + OOy * (mallet->getTexture().getWidth() / 2 + texture.getWidth() / 2) / OOLenght;
}
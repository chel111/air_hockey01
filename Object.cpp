#include "Object.h"



Object::Object()
{
	x = y = Vx = Vy = 0;
}


Texture& Object::getTexture()
{
	return texture;
}

void Object::changeX(int delta)
{
	x += delta;
}

void Object::changeY(int delta)
{
	y += delta;
}

int Object::getX() const
{
	return x;
}

int Object::getY() const 
{
	return y;
}

double Object::getVx() const
{
	return Vx;
}

double Object::getVy() const
{
	return Vy;
}

void Object::setX(int newX)
{
	x = newX;
}

void Object::setY(int newY)
{
	y = newY;
}

void Object::setVx(double newVx)
{
	Vx = newVx;
}

void Object::setVy(double newVy)
{
	Vy = newVy;
}

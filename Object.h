#pragma once

#include "Texture.h"

class Object
{
private:
	Texture texture;
	int x, y;
	double Vx, Vy;

public:
	Object();
	void changeX(int delta);
	void changeY(int delta);

	int getX() const;
	int getY() const;
	Texture& getTexture();
	double getVx() const;
	double getVy() const;
	

	void setX(int newX);
	void setY(int newY);
	void setVx(double newVx);
	void setVy(double newVy);
};


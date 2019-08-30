#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

class Texture
{
public:
	//Initializes variables
	Texture();

	//Deallocates memory
	~Texture();

	//Loads image at specified path
	bool loadFromFile(std::string path, SDL_Renderer* renderer);

	//Deallocates texture
	void free();

	//Renders texture at given point
	void render(SDL_Renderer* renderer, int x, int y, SDL_Rect* clip = nullptr);

	//Gets image dimensions
	int getWidth();
	int getHeight();

private:
	//The actual hardware texture
	SDL_Texture* texture;

	//Image dimensions
	int tWidth;
	int tHeight;
};


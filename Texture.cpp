#include "Texture.h"


Texture::Texture()
{
	texture = nullptr;
	tWidth = tHeight = 0;
}

Texture::~Texture()
{
	free();
}

void Texture::free()
{
	if (this == nullptr) return;
	if (texture != nullptr)
	{
		SDL_DestroyTexture(texture);
		texture = nullptr;
		tWidth = 0;
		tHeight = 0;
	}
}

bool Texture::loadFromFile(std::string path, SDL_Renderer* renderer)
{
	free();

	//The final texture
	SDL_Texture* newTexture = nullptr;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == nullptr)
	{
		return false;
	}
	else
	{
		//Color key image
		SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0x00, 0xFF, 0xFF));		

		//Create texture from surface pixels
		newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
		if (newTexture == nullptr)
		{
			return false;
		}
		else
		{
			//Get image dimensions
			tWidth = loadedSurface->w;
			tHeight = loadedSurface->h;
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	//Return success
	texture = newTexture;
	return true;
}

void Texture::render(SDL_Renderer* renderer, int x, int y, SDL_Rect* clip)
{
	//Set rendering space and render to screen
	SDL_Rect renderQuad = { x, y, tWidth, tHeight };

	//Set clip rendering dimensions
	if (clip != NULL)
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}

	//Render to screen
	SDL_RenderCopyEx(renderer, texture, clip, &renderQuad, 0.0, nullptr, SDL_FLIP_NONE);
}

int Texture::getHeight()
{
	return tHeight;
}

int Texture::getWidth()
{
	return tWidth;
}




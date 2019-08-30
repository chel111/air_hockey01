#include "Sound_Manager.h"

Sound_Manager::Sound_Manager()
{
	music = nullptr;
	puckBorderCollision = puckMalletCollision = nullptr;
}

bool Sound_Manager::onInit()			//Initialize SDL_mixer and load sounds
{

	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
	{
		return false;
	}

	//Load music
	music = Mix_LoadMUS("sounds/music.wav");	
	if (music == nullptr)
	{
		return false;
	}
	

	//Load sound effects
	puckBorderCollision = Mix_LoadWAV("sounds/puckBorderCollision.wav");	///
	if (puckBorderCollision == nullptr)
	{
		return false;
	}
	
	puckMalletCollision = Mix_LoadWAV("sounds/puckMalletCollision.wav");
	if (puckMalletCollision == nullptr)
	{
		return false;
	}
	
	return true;
}


void Sound_Manager::playPuckBorderCollisionSound() const
{
	Mix_PlayChannel(-1, puckBorderCollision, 0);
}


void Sound_Manager::playPuckMalletCollisionSound() const
{
	Mix_PlayChannel(-1, puckMalletCollision, 0);
}

void Sound_Manager::playMusic() const
{
	//Mix_PlayMusic(music, -1);
}

Sound_Manager::~Sound_Manager()
{
	Mix_FreeChunk(puckBorderCollision);
	Mix_FreeChunk(puckMalletCollision);
	puckBorderCollision = nullptr;
	puckMalletCollision = nullptr;

	Mix_FreeMusic(music);
	music = nullptr;

	Mix_Quit();
}



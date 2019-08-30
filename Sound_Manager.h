#pragma once

#include <SDL_mixer.h>

class Sound_Manager
{

	Mix_Music* music;

	Mix_Chunk* puckBorderCollision;
	Mix_Chunk* puckMalletCollision;
public:
	Sound_Manager();
	bool onInit();


	void playPuckBorderCollisionSound() const;
	void playPuckMalletCollisionSound() const;
	void playMusic() const;

	~Sound_Manager();
};

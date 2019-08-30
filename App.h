#pragma once

#include "Texture.h"
#include "Game_Manager.h"
#include "PhysicEngine.h"
#include "AI.h"
#include "Sound_Manager.h"


class App
{
public:
	App();
	~App();

	int onExecute();
private:
	bool running;

	SDL_Window* window;
	SDL_Renderer* renderer;
	Texture background;
	Game_Manager game_manager;
	Sound_Manager sound_manager;


	const int WINDOW_WIDTH = 640;
	const int WINDOW_HEIGHT = 750;
	const char* WINDOW_CAPTION = "Air Hockey";


	bool onInit();
	void onEvent(SDL_Event* e);
	void onLoop();
	void onRender();
	void onQuit();

};


#include "App.h"

App::App() : game_manager(new Puck, new Mallet, new Mallet)
{
	running = true;
	window = nullptr;
	renderer = nullptr;
}

App::~App()
{
	onQuit();
}

int App::onExecute()
{
	onInit();
	onLoop();
	onQuit();
	return 0;
}




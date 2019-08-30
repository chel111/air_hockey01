#include "App.h"

App::App() : game_manager(new Object, new Object, new Object)
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




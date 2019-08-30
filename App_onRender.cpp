#include "App.h"

void App::onRender()
{
	SDL_RenderClear(renderer);

	background.render(renderer, 100, 0);

	//Render objects
	game_manager.renderObjects(renderer);


	//Update screen
	SDL_RenderPresent(renderer);
}
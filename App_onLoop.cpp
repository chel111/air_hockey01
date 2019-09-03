#include "App.h"

void App::onLoop()
{
	SDL_Event e;
	int borderCollision = 0, xPrev = 0, yPrev = 0, skipIteration = 0, botLevet = 2;
	Object* malletCollision = nullptr;

	sound_manager.playMusic();

	//Previous coordinates of player mallet
	//Handle events on queue
	while (running)
	{
		if (skipIteration)
		{
			game_manager.onLoop();
			skipIteration--;
			continue;
		}
		while (SDL_PollEvent(&e) != 0)
		{
			onEvent(&e);
		}



		
		//border collision
		borderCollision = PhysicEngine::checkBorderCollision(game_manager.getPuck());
		if (borderCollision && !PhysicEngine::checkMalletCollision(game_manager))
		{
			PhysicEngine::handleBorderCollision(game_manager, borderCollision);
			sound_manager.playPuckBorderCollisionSound();
			std::cout << "COLLISION" << std::endl;

		}

		AI::setAIVelocity(game_manager.getAIMallet(), game_manager.getPuck(), botLevet);
		malletCollision = PhysicEngine::checkMalletCollision(game_manager);
		
		game_manager.setPlayerMalletVelocity(xPrev, yPrev);
		if (malletCollision != nullptr)
		{
			PhysicEngine::handleMalletCollision(game_manager.getPuck(), malletCollision);
			sound_manager.playPuckMalletCollisionSound();
			skipIteration = 1;	/////

			std::cout << " MALLET COLLISION" << std::endl;
			if (borderCollision && malletCollision == game_manager.getPlayerMallet())
			{
				game_manager.getPlayerMallet()->setX(xPrev);
				game_manager.getPlayerMallet()->setY(yPrev);
			}
		}
		
		PhysicEngine::onLoop(game_manager.getPuck());

		game_manager.onLoop();


		onRender();
		

		xPrev = game_manager.getPlayerMallet()->getX();
		yPrev = game_manager.getPlayerMallet()->getY();
	}

}
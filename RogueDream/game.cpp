#include "game.h"
#include "sprite.h"

Game::Game()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	IMG_Init(IMG_INIT_PNG);

	onEventLoop();
}

Game::~Game()
{
	IMG_Quit();
	SDL_Quit();
}

void Game::onEventLoop()
{
	Graphics graphics;
	SDL_Event sdl_event;
	bool running = true;

	while (running)
	{
		while (SDL_PollEvent(&sdl_event))
		{
			switch (sdl_event.type)
			{
			case SDL_QUIT:
				running = false;
				break;
			default:
				break;
			}

			// Testing
			Sprite player(graphics, "Player0.png", 0, 0, 16, 16);
			player.draw(graphics, 320, 240);
			graphics.flip();
		}
	}
}
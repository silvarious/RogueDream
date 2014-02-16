#include "game.h"
#include "player.h"
#include "input.h"

Game::Game()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	IMG_Init(IMG_INIT_PNG);

	onEventLoop();
}

Game::~Game()
{
	delete player_;

	IMG_Quit();
	SDL_Quit();
}

void Game::onEventLoop()
{
	Graphics graphics;
	SDL_Event sdl_event;
	Input input;

	player_ = new Player(graphics, kPlayerStartX, kPlayerStartY);

	bool running = true;
	while (running)
	{
		while (SDL_PollEvent(&sdl_event))
		{
			switch (sdl_event.type)
			{
			case SDL_KEYDOWN:
				input.keyDownEvent(sdl_event);
				break;
			case SDL_KEYUP:
				player_->handleMovement(input);
				input.keyUpEvent(sdl_event);
				break;
			case SDL_QUIT:
				running = false;
				break;
			default:
				break;
			}

			if (input.wasKeyPressed(SDLK_ESCAPE))
				running = false;

			draw(graphics);
		}
	}
}

void Game::draw(Graphics& graphics) const
{
	graphics.clear();

	player_->draw(graphics);

	graphics.flip();
}
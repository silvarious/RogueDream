#include <stdlib.h>

#include "game.h"
#include "player.h"
#include "input.h"
#include "map.h"

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
	float last_update_time = SDL_GetTicks();
	while (running)
	{
		const float start_time = SDL_GetTicks();
		input.beginNewFrame();
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
		}

		const float current_time = SDL_GetTicks();
		const float elapsed_time = current_time - last_update_time;
		update(std::min(elapsed_time, kMaxFrameTime));
		last_update_time = current_time;
		
		draw(graphics);
	}
}

void Game::update(float elapsed_time)
{
	Timer::updateAll(elapsed_time);

	player_->update();
}

void Game::draw(Graphics& graphics) const
{
	graphics.clear();

	player_->draw(graphics);

	graphics.flip();
}
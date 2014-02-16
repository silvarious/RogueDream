#ifndef GAME_H_
#define GAME_H_

#include <SDL.h>
#include <SDL_image.h>

#include "graphics.h"

struct Player;

namespace
{
	const float kPlayerStartX = 320;
	const float kPlayerStartY = 240;
}

struct Game
{
	Game();
	~Game();

private:
	void onEventLoop();
	void update(float elapsed_time);
	void draw(Graphics& graphics) const;

	Player* player_;
};

#endif
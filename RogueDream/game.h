#ifndef GAME_H_
#define GAME_H_

#include <SDL.h>
#include <SDL_image.h>

#include "graphics.h"

struct Game
{
	Game();
	~Game();

private:
	void onEventLoop();
	void update(float elapsed_time);
	void draw(Graphics& graphics) const;
};

#endif
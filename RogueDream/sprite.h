#ifndef SPRITE_H_
#define SPRITE_H_

#include <SDL.h>
#include <string>

struct Graphics;

struct Sprite
{
	Sprite(Graphics& graphics, const std::string file_path,
		   int source_x, int source_y, int width, int height);
	virtual ~Sprite();

	virtual void update(float elapsed_time) {}
	void draw(Graphics& graphics, float x, float y) const;

protected:
	SDL_Rect source_;

private:
	SDL_Texture* texture_;
};

#endif
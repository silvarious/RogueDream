#include <SDL.h>

#include "sprite.h"
#include "graphics.h"

Sprite::Sprite(Graphics& graphics, const std::string file_path,
		       int source_x, int source_y, int width, int height)
{
	texture_ = graphics.loadImage(file_path.c_str());
	source_.x = source_x;
	source_.y = source_y;
	source_.w = width;
	source_.h = height;
}

Sprite::~Sprite()
{

}

void Sprite::draw(Graphics& graphics, float x, float y) const
{
	const int destination_x = (int)x;
	const int destination_y = (int)y;

	graphics.renderTexture(texture_, destination_x, destination_y, &source_);
}
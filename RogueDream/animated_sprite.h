#ifndef ANIMATED_SPRITE_H_
#define ANIMATED_SPRITE_H_

#include "sprite.h"
#include "timer.h"

struct AnimatedSprite : public Sprite
{
	AnimatedSprite(Graphics& graphics, const std::string& file_path, int source_x, int source_y, int width, int height,
		unsigned int fps, unsigned int num_frames, const int frame_offset);

	void update();

private:
	Timer frame_timer_;
	const unsigned int num_frames_;
	unsigned int current_frame_;
	const int frame_offset_;
};

#endif
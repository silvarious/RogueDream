#include "animated_sprite.h"
#include "game.h"

AnimatedSprite::AnimatedSprite(Graphics& graphics, const std::string& file_path, int source_x, int source_y, int width, int height,
		unsigned int fps, unsigned int num_frames, const int frame_offset) :
Sprite(graphics, file_path, source_x, source_y, width, height),
	frame_timer_(1000.0f / fps), num_frames_(num_frames), current_frame_(0), frame_offset_(frame_offset)
{

}

void AnimatedSprite::update()
{
	if (frame_timer_.expired())
	{
		++current_frame_;
		frame_timer_.reset();
		if (current_frame_ < num_frames_)
		{
			source_.x += frame_offset_;
		}
		else
		{
			source_.x -= frame_offset_ * (num_frames_ - 1);
			current_frame_ = 0;
		}
	}
}
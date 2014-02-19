#include "player.h"
#include "sprite.h"
#include "game.h"
#include "graphics.h"
#include "input.h"
#include "aabb.h"

namespace
{
	const std::string kPlayerSpriteFilePath = "../Content/Characters/Player.png";
	const int kPlayerSpriteSize = 16;
	const unsigned int kAnimationFPS = 5;
	const unsigned int kPlayerNumFrames = 2;
	const int kPlayerFrameOffset = 8 * kPlayerSpriteSize;
	const int kPlayerSpriteTopX = 0;
	const int kPlayerSpriteTopY = 0;
	const int kPlayerMoveAmount = 16;
	const AABB kPlayerAABB(kPlayerSpriteTopX, kPlayerSpriteTopY, kPlayerSpriteSize, kPlayerSpriteSize);
};

Player::Player(Graphics& graphics, float x, float y) : x_(x), y_(y), health_(graphics), interacting_(false), facing_(LEFT),
	player_(graphics, kPlayerSpriteFilePath, kPlayerSpriteTopX, kPlayerSpriteTopY, kPlayerSpriteSize, kPlayerSpriteSize,
	kAnimationFPS, kPlayerNumFrames, kPlayerFrameOffset)
{

}

void Player::update()
{
	player_.update();
	health_.update();
}

void Player::draw(Graphics& graphics) const
{
	if (facing_ == LEFT)
		player_.draw(graphics, x_, y_);
	if (facing_ == RIGHT)
		player_.drawFlipped(graphics, x_, y_);
}

void Player::handleMovement(Input input)
{
	if (input.isKeyHeld(SDLK_LEFT))
		moveLeft();
	if (input.isKeyHeld(SDLK_RIGHT))
		moveRight();
	if (input.isKeyHeld(SDLK_UP))
		moveUp();
	if (input.isKeyHeld(SDLK_DOWN))
		moveDown();
}

void Player::moveLeft()
{
	facing_ = LEFT;
	x_ = this->x_;
	x_ -= kPlayerMoveAmount;
}

void Player::moveRight()
{
	facing_ = RIGHT;
	x_ = this->x_;
	x_ += kPlayerMoveAmount;
}

void Player::moveUp()
{
	y_ = this->y_;
	y_ -= kPlayerMoveAmount;
}

void Player::moveDown()
{
	y_ = this->y_;
	y_ += kPlayerMoveAmount;
}
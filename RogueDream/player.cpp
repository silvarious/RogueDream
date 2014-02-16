#include "player.h"
#include "sprite.h"
#include "game.h"
#include "graphics.h"

namespace
{
	const std::string kPlayerSpriteFilePath = "../Content/Characters/Player0.png";
	const int kPlayerSpriteSize = 16;
	const int kPlayerSpriteTopX = 0;
	const int kPlayerSpriteTopY = 0;
	const int kPlayerMoveAmount = 16;
};

Player::Player(Graphics& graphics, float x, float y) : x_(x), y_(y), health_(graphics), interacting_(false),
	player_(graphics, kPlayerSpriteFilePath, kPlayerSpriteTopX, kPlayerSpriteTopY, kPlayerSpriteSize, kPlayerSpriteSize)
{

}

void Player::update(float elapsed_time)
{
	health_.update();
}

void Player::draw(Graphics& graphics) const
{
	player_.draw(graphics, x_, y_);
}

void Player::moveLeft()
{
	x_ = this->x_;
	x_ -= kPlayerMoveAmount;
}

void Player::moveRight()
{
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
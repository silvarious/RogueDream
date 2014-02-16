#include "player.h"

namespace
{
	const std::string kPlayerHealthSpriteFilePath = "../Content/GUI/GUI0.png";
	const int kPlayerHealthSpriteSize = 16;
	const int kPlayerHealthSpriteTopX = 0;
	const int kPlayerHealthSpriteTopY = 0;
	const int kPlayerMaxHealth = 9999;
}

Player::Health::Health(Graphics& graphics) : damage_(0), max_health_(kPlayerMaxHealth), current_health_(kPlayerMaxHealth),
	health_bar_sprite_(graphics, kPlayerHealthSpriteFilePath, kPlayerHealthSpriteTopX, kPlayerHealthSpriteTopY, kPlayerHealthSpriteSize, kPlayerHealthSpriteSize)
{
	
}

void Player::Health::update()
{
	if (damage_ > 0)
	{
		current_health_ -= damage_;
		damage_ = 0;
	}
}

void Player::Health::draw(Graphics& graphics) const
{
	// TODO
}

bool Player::Health::takeDamage(int damage)
{
	damage_ = damage;
	// TODO: fill health sprite
	return false;
}
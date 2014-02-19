#ifndef PLAYER_H_
#define PLAYER_H_

#include "sprite.h"
#include "animated_sprite.h"

struct Graphics;
struct Input;
struct AABB;

struct Player
{
	Player(Graphics& graphics, float x, float y);

	void update();
	void draw(Graphics& graphics) const;

	void handleMovement(Input input);

	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();

	void takeDamage(int damage);

private:
	enum Facing
	{
		FIRST_FACING,
		LEFT = FIRST_FACING,
		RIGHT,
		LAST_FACING,
	};

	enum MotionType
	{
		FIRST_MOTION_TYPE,
		STANDING = FIRST_MOTION_TYPE,
		WALKING,
		LAST_MOTION_TYPE,
	};

	struct Health
	{
		Health(Graphics& graphics);

		void update();
		void draw(Graphics& graphics) const;

		bool takeDamage(int damage);

	private:
		int damage_;

		int max_health_;
		int current_health_;
		Sprite health_bar_sprite_;
	};

	MotionType motionType() const;

	float x_, y_;
	bool interacting_;

	Health health_;

	Facing facing_;
	AnimatedSprite player_;
};

#endif
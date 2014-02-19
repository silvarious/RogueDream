#ifndef AABB_H_
#define AABB_H_

struct AABB
{
	AABB(float x, float y, float width, float height) : x_(x), y_(y), width_(width), height_(height)
	{

	}

	float left() const { return x_; }
	float right() const { return x_ + width_; }
	float top() const { return y_; }
	float bottom() const { return y_ + height_; }

	float width() const { return width_; }
	float height() const { return height_; }

	bool isCollidingWith(const AABB& aabb) const
	{
		return right() >= aabb.left() &&
			   left() <= aabb.right() &&
			   top() <= aabb.bottom() &&
			   bottom() >= aabb.top();
	}

private:
	const float x_, y_, width_, height_;
};

#endif
#ifndef MAP_H_
#define MAP_H_

#include <vector>

#include "sprite.h"

struct Graphics;
struct AABB;

struct Map
{
	enum TileType
	{
		FIRST_TILE_TYPE,
		FLOOR,
		WALL,
		LAST_TILE_TYPE,
	};

	void draw(Graphics& graphics) const;
};

#endif
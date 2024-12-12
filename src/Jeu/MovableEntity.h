#pragma once
#include "Entity.h"

class MovableEntity : public Entity
{
public:
	MovableEntity();

	void moveEntity(float x, float y);
};


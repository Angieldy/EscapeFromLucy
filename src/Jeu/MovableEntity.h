#pragma once
#include "Entity.h"

class MovableEntity : Entity
{
public:
	MovableEntity();

	void moveEntity(float x, float y);
};


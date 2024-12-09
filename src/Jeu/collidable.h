#pragma once
#include"Entity.h"

class collidable : Entity
{
public:

	collidable();

	bool collide(const sf::Sprite& other, const sf::Sprite& other2) const;
};


#pragma once
#include"MovableEntity.h"

class collidable : public MovableEntity
{
public:

	collidable();

	bool collideSprite(const sf::Sprite& other, const sf::Sprite& other2) const;
	bool WallCollision(const sf::RectangleShape& rect1, const sf::Sprite& player) const;
	bool DoorsCollision(const sf::RectangleShape& rect1, const sf::Sprite& player) const;
};


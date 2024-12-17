#pragma once
#include"MovableEntity.h"

class collidable : public MovableEntity
{
public:

	sf::FloatRect GlobalBounds;

	collidable();

	sf::FloatRect Bounds(sf::Sprite object);
	bool collideSprite(const sf::FloatRect& other, const sf::FloatRect& other2) const;
	bool WallCollision(const sf::RectangleShape& rect1, const sf::FloatRect& playerBounds) const;
	bool DoorsCollision(const sf::RectangleShape& rect1, const sf::FloatRect& playerBounds) const;
	bool OtherCollision(const sf::RectangleShape& rect1, const sf::FloatRect& playerBounds) const;
	bool ProjectilCollision(const sf::RectangleShape& rect1, const sf::FloatRect& projectilBounds) const;
	//bool TextCollision(const sf::Text& rect1, const sf::Event& clickLeft) const;

};


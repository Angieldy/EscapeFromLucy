#pragma once
#include "collidable.h"

class projectil : public collidable
{
public:
	sf::Texture txtLarmeBase;
	sf::Texture BlackLarme;

	sf::Sprite spriteLarmeBase;

	sf::Vector2f direction;

	projectil();

	void move(float deltaTime, float speed);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};


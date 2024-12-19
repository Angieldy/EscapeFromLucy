#pragma once
#include "collidable.h"

class ProjectileEnemy : public collidable
{
public:
	sf::Texture txtLarve;

	sf::Sprite spriteLarve;

	sf::Vector2f directionLarve;

	ProjectileEnemy();

	void move(float deltaTime, float speed);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};


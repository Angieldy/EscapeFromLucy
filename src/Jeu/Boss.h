#pragma once
#include "Enemy.h"
class Boss : public Enemy
{

public:

	sf::Texture BossLeg;

	sf::Sprite spriteLeg;

	std::vector<sf::Texture*> sheetsLeg;

	sf::Vector2f position;

	Boss();

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};


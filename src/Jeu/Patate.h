#pragma once
#include "Enemy.h"

class Patate : public Enemy
{

public:

	sf::Texture PatateBase;

	sf::Sprite spritePatate;

	std::vector<sf::Texture*> sheetsPatate;

	Patate();

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};


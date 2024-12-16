#pragma once
#include "Enemy.h"
class Poop : public Enemy
{

public:

	sf::Texture PoopBase;
	sf::Texture PoopMid;
	sf::Texture PoopLittle;
	sf::Texture PoopCrushed;

	sf::Sprite spritePoopBase;

	std::vector<sf::Texture*> sheetsPoop;

	Poop();

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};


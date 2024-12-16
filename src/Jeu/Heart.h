#pragma once
#include "Entity.h"

class Heart : public Entity
{

public:

	sf::Texture bigHeart;
	sf::Texture middleHeart;
	sf::Texture quartHeart;
	sf::Texture unQuartHeart;
	sf::Texture emptyHeart;

	sf::Sprite Heart1;
	sf::Sprite Heart2;
	sf::Sprite Heart3;

	std::vector<sf::Texture*> heart;

	Heart();

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#pragma once
#include "collidable.h"

class Objet : public collidable
{
public:

	sf::Texture satanicCoin;
	sf::Texture goldKey;
	sf::Texture heart;

	sf::Sprite item;
	std::vector<sf::Texture*> items;
	std::vector<sf::Texture*> sac;

	Objet();

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};
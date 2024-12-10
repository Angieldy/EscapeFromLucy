#pragma once
#include "Entity.h"

class Scene : public Entity
{
public:

	sf::Texture spone;
	sf::Texture rightroom;

	sf::Sprite room;

	std::vector<sf::Texture*> sheetsRoom;

	Scene();

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

};

#pragma once
#include "Entity.h"

class Scene : public Entity
{
public:

	sf::Texture spone; //0
	sf::Texture rightroom; //1
	sf::Texture shop; //2
	sf::Texture basic; //3
	sf::Texture bossroom; //4
	sf::Texture logo; //5
	sf::Texture launcher; //6
	sf::Texture aide; //7
	sf::Texture menu;//8
	sf::Texture options;//9
	sf::Texture credits;//10
	sf::Texture optionsMenu; //11
	sf::Texture gameOver; //12
	sf::Texture letter; //13

	sf::Sprite room;

	std::vector<sf::Texture*> sheetsRoom;

	Scene();

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

};
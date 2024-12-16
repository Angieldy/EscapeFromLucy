#pragma once
#include "collidable.h"
#include "MovableEntity.h"
#include "Attaque.h"

class projectil : public collidable, public Attaque
{
public:
	sf::Texture txtLarmeBase;
	//sf::Texture txtLarmeBase1;
	//sf::Texture txtLarmeBase2;
	//sf::Texture txtLarmeBase3;
	//sf::Texture txtLarmeBase4;
	//sf::Texture txtLarmeBase5;
	//sf::Texture txtLarmeBase6;
	//sf::Texture txtLarmeBase7;
	//sf::Texture txtLarmeBase8;
	//sf::Texture txtLarmeBase9;
	//sf::Texture txtLarmeBase10;
	//sf::Texture txtLarmeBase11;
	//sf::Texture txtLarmeBase12;
	//sf::Texture txtLarmeBase13;


	sf::Sprite spriteLarmeBase;
	std::vector<sf::Texture*> sheetsLarmeBase;
	sf::Vector2f direction;

	projectil();

	void move(float deltaTime, float speed);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};


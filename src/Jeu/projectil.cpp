#include "pch.h"
#include "projectil.h"
#include <iostream>

projectil::projectil()
{
	if (!txtLarmeBase.loadFromFile("../../../src/Jeu/png/metallic_tears.png", sf::IntRect(0, 0, 48, 48)))
	{
		std::cerr << "Impossible de charger la textur  LarmeBase1!" << std::endl;
	}

	if (!BlackLarme.loadFromFile("../../../src/Jeu/png/darkTear.png", sf::IntRect(0, 0, 48, 48)))
	{
		std::cerr << "Impossible de charger la textur  LarmeBase1!" << std::endl;
	}

	spriteLarmeBase.setTexture(txtLarmeBase);
	setPosition(700, 400);
	spriteLarmeBase.setOrigin(32 / 2, 32 / 2);
	spriteLarmeBase.setScale(sf::Vector2f(1.f, 1.f));

	direction = {0.f, 0.f};
}

void projectil::move(float deltaTime, float speed)
{
	Entity::move(direction.x * speed * deltaTime, direction.y * speed * deltaTime);
}

void projectil::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform.combine(this->getTransform());

	target.draw(spriteLarmeBase, states);
}
#include "pch.h"
#include "projectil.h"
#include <iostream>

projectil::projectil()
{
	if (!txtLarmeBase1.loadFromFile("../../../src/Jeu/png/metallic_tears.png", sf::IntRect(10, 10, 28, 26))) //256x64
	{
		std::cerr << "Impossible de charger la textur  LarmeBase1!" << std::endl;
	}

	spriteLarmeBase.setTexture(txtLarmeBase1);
	spriteLarmeBase.setPosition(100, 100);
	spriteLarmeBase.setOrigin((1.5f * 31) / 2, (1.5f * 38) / 2);
	spriteLarmeBase.setScale(sf::Vector2f(2.f, 2.f));

	sheetsLarmeBase.push_back(&txtLarmeBase1);
}

void projectil::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform.combine(this->getTransform());

	target.draw(spriteLarmeBase, states);
}
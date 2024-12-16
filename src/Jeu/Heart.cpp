#include "pch.h"
#include "Heart.h"
#include <iostream>

Heart::Heart()
{

	if (!bigHeart.loadFromFile("../../../src/Jeu/png/BigHeart.png", sf::IntRect(0, 0, 32, 25))) //777x513
	{
		std::cerr << "Impossible de charger la texture BigHeart!" << std::endl;
	}

	if (!middleHeart.loadFromFile("../../../src/Jeu/png/MiddleHeart.png", sf::IntRect(0, 0, 32, 25))) //777x513
	{
		std::cerr << "Impossible de charger la texture MiddleHeart!" << std::endl;
	}

	if (!quartHeart.loadFromFile("../../../src/Jeu/png/QuartHeart.png", sf::IntRect(0, 0, 32, 25))) //777x513
	{
		std::cerr << "Impossible de charger la texture QuartHeart!" << std::endl;
	}

	if (!unQuartHeart.loadFromFile("../../../src/Jeu/png/1karHeart.png", sf::IntRect(0, 0, 32, 25))) //777x513
	{
		std::cerr << "Impossible de charger la texture 1karHeart!" << std::endl;
	}

	if (!emptyHeart.loadFromFile("../../../src/Jeu/png/EmptyHeart.png", sf::IntRect(0, 0, 32, 25))) //777x513
	{
		std::cerr << "Impossible de charger la texture EmptyHeart!" << std::endl;
	}

	Heart1.setTexture(bigHeart);
	Heart2.setTexture(bigHeart);
	Heart3.setTexture(bigHeart);

	Heart1.setPosition(5, 5);
	Heart2.setPosition(100, 5);
	Heart3.setPosition(200, 5);

	Heart1.setScale(3, 3);
	Heart2.setScale(3, 3);
	Heart3.setScale(3, 3);
}

void Heart::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform.combine(this->getTransform());

	target.draw(Heart1, states);
	target.draw(Heart2, states);
	target.draw(Heart3, states);

}

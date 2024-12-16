#include "pch.h"
#include "projectil.h"
#include <iostream>

projectil::projectil()
{
	if (!txtLarmeBase.loadFromFile("../../../src/Jeu/png/metallic_tears.png"))
	{
		std::cerr << "Impossible de charger la textur  LarmeBase1!" << std::endl;
	}
	//if (!txtLarmeBase1.loadFromFile("../../../src/Jeu/png/metallic_tears.png", sf::IntRect(2, 3, 28, 26))) //256x64
	//{
	//	std::cerr << "Impossible de charger la textur  LarmeBase1!" << std::endl;
	//}
	//if (!txtLarmeBase2.loadFromFile("../../../src/Jeu/png/metallic_tears.png", sf::IntRect(34, 3, 28, 26))) //256x64
	//{
	//	std::cerr << "Impossible de charger la textur  LarmeBase2!" << std::endl;
	//}
	//if (!txtLarmeBase3.loadFromFile("../../../src/Jeu/png/metallic_tears.png", sf::IntRect(66, 3, 28, 26))) //256x64
	//{
	//	std::cerr << "Impossible de charger la textur  LarmeBase3!" << std::endl;
	//}
	//if (!txtLarmeBase4.loadFromFile("../../../src/Jeu/png/metallic_tears.png", sf::IntRect(98, 3, 28, 26))) //256x64
	//{
	//	std::cerr << "Impossible de charger la textur  LarmeBase4!" << std::endl;
	//}
	//if (!txtLarmeBase5.loadFromFile("../../../src/Jeu/png/metallic_tears.png", sf::IntRect(131, 3, 28, 26))) //256x64
	//{
	//	std::cerr << "Impossible de charger la textur  LarmeBase5!" << std::endl;
	//}
	//if (!txtLarmeBase6.loadFromFile("../../../src/Jeu/png/metallic_tears.png", sf::IntRect(162, 3, 28, 26))) //256x64
	//{
	//	std::cerr << "Impossible de charger la textur  LarmeBase1!" << std::endl;
	//}
	//if (!txtLarmeBase7.loadFromFile("../../../src/Jeu/png/metallic_tears.png", sf::IntRect(195, 3, 28, 26))) //256x64
	//{
	//	std::cerr << "Impossible de charger la textur  LarmeBase1!" << std::endl;
	//}
	//if (!txtLarmeBase8.loadFromFile("../../../src/Jeu/png/metallic_tears.png", sf::IntRect(226, 3, 28, 26))) //256x64
	//{
	//	std::cerr << "Impossible de charger la textur  LarmeBase1!" << std::endl;
	//}
	//if (!txtLarmeBase9.loadFromFile("../../../src/Jeu/png/metallic_tears.png", sf::IntRect(2, 34, 28, 26))) //256x64
	//{
	//	std::cerr << "Impossible de charger la textur  LarmeBase1!" << std::endl;
	//}
	//if (!txtLarmeBase10.loadFromFile("../../../src/Jeu/png/metallic_tears.png", sf::IntRect(34, 34, 28, 26))) //256x64
	//{
	//	std::cerr << "Impossible de charger la textur  LarmeBase1!" << std::endl;
	//}
	//if (!txtLarmeBase11.loadFromFile("../../../src/Jeu/png/metallic_tears.png", sf::IntRect(64, 34, 28, 26))) //256x64
	//{
	//	std::cerr << "Impossible de charger la textur  LarmeBase1!" << std::endl;
	//}
	//if (!txtLarmeBase12.loadFromFile("../../../src/Jeu/png/metallic_tears.png", sf::IntRect(97, 34, 28, 26))) //256x64
	//{
	//	std::cerr << "Impossible de charger la textur  LarmeBase1!" << std::endl;
	//}
	//if (!txtLarmeBase13.loadFromFile("../../../src/Jeu/png/metallic_tears.png", sf::IntRect(130, 34, 28, 26))) //256x64
	//{
	//	std::cerr << "Impossible de charger la textur  LarmeBase1!" << std::endl;
	//}

	spriteLarmeBase.setTexture(txtLarmeBase);
	spriteLarmeBase.setTextureRect(sf::IntRect(32, 32, 32, 32));
	setPosition(700, 400);
	spriteLarmeBase.setOrigin(28 / 2, 26 / 2);
	spriteLarmeBase.setScale(sf::Vector2f(1.3f, 1.3f));

	//sheetsLarmeBase.push_back(&txtLarmeBase1);
	//sheetsLarmeBase.push_back(&txtLarmeBase2);
	//sheetsLarmeBase.push_back(&txtLarmeBase3);
	//sheetsLarmeBase.push_back(&txtLarmeBase4);
	//sheetsLarmeBase.push_back(&txtLarmeBase5);
	//sheetsLarmeBase.push_back(&txtLarmeBase6);
	//sheetsLarmeBase.push_back(&txtLarmeBase7);
	//sheetsLarmeBase.push_back(&txtLarmeBase8);
	//sheetsLarmeBase.push_back(&txtLarmeBase9);
	//sheetsLarmeBase.push_back(&txtLarmeBase10);
	//sheetsLarmeBase.push_back(&txtLarmeBase11);
	//sheetsLarmeBase.push_back(&txtLarmeBase12);
	//sheetsLarmeBase.push_back(&txtLarmeBase13);

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
#include "pch.h"
#include "ProjectileEnemy.h"
#include <iostream>

ProjectileEnemy::ProjectileEnemy()
{
	if (!txtLarve.loadFromFile("../../../src/Jeu/png/patate.png"))
	{
		std::cerr << "Impossible de charger la textur  LarmeBase1!" << std::endl;
	}

	spriteLarve.setTexture(txtLarve);
	spriteLarve.setTextureRect(sf::IntRect(425, 5, 25, 28));
	setPosition(700, 400);
	spriteLarve.setOrigin(25 / 2, 28 / 2);
	spriteLarve.setScale(sf::Vector2f(2.3f, 2.3f));

	directionLarve = { 0.f, 0.f };
}

void ProjectileEnemy::move(float deltaTime, float speed)
{
	Entity::move(directionLarve.x * speed * deltaTime, directionLarve.y * speed * deltaTime);
}

void ProjectileEnemy::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform.combine(this->getTransform());

	target.draw(spriteLarve, states);
}
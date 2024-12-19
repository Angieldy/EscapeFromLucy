#include "pch.h"
#include "Patate.h"
#include <iostream>

Patate::Patate()
{
    mMaxHealth = 10;
    mCurrentHealth = 10;
    mAttack = 2;
    speedEnemy = 100.f;

    if (!PatateBase.loadFromFile("../../../src/Jeu/png/patate.png", sf::IntRect(594, 4, 33, 31))) //1415 x 230
    {
        std::cerr << "Impossible de charger la texture PatateBase!" << std::endl;
    }

    spritePatate.setTexture(PatateBase);
    setPosition(700, 400);
    spritePatate.setOrigin(15, 15);
    spritePatate.setScale(sf::Vector2f(3.5f, 3.5f));

    sheetsPatate.push_back(&PatateBase);

}

void Patate::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform.combine(this->getTransform());

    target.draw(spritePatate, states);
}
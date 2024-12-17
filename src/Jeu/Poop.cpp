#include "pch.h"
#include "Poop.h"
#include <iostream>

Poop::Poop()
{
    mMaxHealth = 10;
    mCurrentHealth = 10;
    mAttack = 2;
    speedEnemy  = 200.f;

    if (!PoopBase.loadFromFile("../../../src/Jeu/png/caca mob.png", sf::IntRect(31, 38, 60, 60))) //512 x 128
    {
        std::cerr << "Impossible de charger la texture PoopBase!" << std::endl;
    }

    if (!PoopMid.loadFromFile("../../../src/Jeu/png/caca mob.png", sf::IntRect(131, 38, 60, 60))) //512 x 128
    {
        std::cerr << "Impossible de charger la texture PoopMid!" << std::endl;
    }

    if (!PoopLittle.loadFromFile("../../../src/Jeu/png/caca mob.png", sf::IntRect(251, 38, 60, 60))) //512 x 128
    {
        std::cerr << "Impossible de charger la texture PoopLittle!" << std::endl;
    }

    if (!PoopCrushed.loadFromFile("../../../src/Jeu/png/caca mob.png", sf::IntRect(401, 38, 60, 60))) //512 x 128
    {
        std::cerr << "Impossible de charger la texture PoopCrushed!" << std::endl;
    }

    spritePoop.setTexture(PoopBase);
    setPosition(700, 400);
    spritePoop.setOrigin(30, 30);
    spritePoop.setScale(sf::Vector2f(2.5f, 2.5f));

    sheetsPoop.push_back(&PoopBase);
    sheetsPoop.push_back(&PoopMid);
    sheetsPoop.push_back(&PoopLittle);
    sheetsPoop.push_back(&PoopCrushed);

}

void Poop::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform.combine(this->getTransform());

    target.draw(spritePoop, states);
}
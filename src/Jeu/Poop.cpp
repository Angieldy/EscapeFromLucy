#include "pch.h"
#include "Poop.h"
#include <iostream>

Poop::Poop()
{
    if (!PoopBase.loadFromFile("../../../src/Jeu/png/caca mob.png", sf::IntRect(31, 38, 100, 60))) //512 x 128
    {
        std::cerr << "Impossible de charger la texture PoopBase!" << std::endl;
    }

    if (!PoopMid.loadFromFile("../../../src/Jeu/png/caca mob.png", sf::IntRect(131, 38, 100, 60))) //512 x 128
    {
        std::cerr << "Impossible de charger la texture PoopMid!" << std::endl;
    }

    if (!PoopLittle.loadFromFile("../../../src/Jeu/png/caca mob.png", sf::IntRect(251, 38, 100, 60))) //512 x 128
    {
        std::cerr << "Impossible de charger la texture PoopLittle!" << std::endl;
    }

    if (!PoopCrushed.loadFromFile("../../../src/Jeu/png/caca mob.png", sf::IntRect(401, 38, 100, 60))) //512 x 128
    {
        std::cerr << "Impossible de charger la texture PoopCrushed!" << std::endl;
    }

    spritePoopBase.setTexture(PoopBase);
    spritePoopBase.setPosition(200, 100);

    sheetsPoop.push_back(&PoopBase);
    sheetsPoop.push_back(&PoopMid);
    sheetsPoop.push_back(&PoopLittle);
    sheetsPoop.push_back(&PoopCrushed);
}

void Poop::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform.combine(this->getTransform());

    target.draw(spritePoopBase, states);
}
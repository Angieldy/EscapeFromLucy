#include "pch.h"
#include "objet.h"
#include <iostream>

Objet::Objet()
{
    if (!satanicCoin.loadFromFile("../../../src/Jeu/png/satanic coin.png"))
    {
        std::cerr << "Impossible de charger la texture satanic coin!" << std::endl;
    }

    if (!goldKey.loadFromFile("../../../src/Jeu/png/clé.png"))
    {
        std::cerr << "Impossible de charger la texture clé!" << std::endl;
    }

    if (!heart.loadFromFile("../../../src/Jeu/png/life.png"))
    {
        std::cerr << "Impossible de charger la texture life!" << std::endl;
    }

    item.setTexture(satanicCoin);
    item.setPosition(100, 25);//400 50
    item.setTextureRect(sf::IntRect(0, 0, 26, 23));
    item.setScale(3, 3);
    item.setColor(sf::Color(255, 255, 255, 255));

    items.push_back(&satanicCoin);
    items.push_back(&goldKey);
    items.push_back(&heart);

}

void Objet::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform.combine(this->getTransform());

    target.draw(item, states);
}
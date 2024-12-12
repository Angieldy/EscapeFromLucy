#include "pch.h"
#include "Scene.h"
#include <iostream>

Scene::Scene()
{
    if (!spone.loadFromFile("../../../src/Jeu/png/spone.png"))
    {
        std::cerr << "Impossible de charger la textur  spone!" << std::endl;
    }

    if (!rightroom.loadFromFile("../../../src/Jeu/png/womb.png"))
    {
        std::cerr << "Impossible de charger la textur  rightroom!" << std::endl;
    }

    if (!shop.loadFromFile("../../../src/Jeu/png/room.png"))
    {
        std::cerr << "Impossible de charger la textur  rightroom!" << std::endl;
    }

    if (!basic.loadFromFile("../../../src/Jeu/png/pieceennemy.png"))
    {
        std::cerr << "Impossible de charger la textur  rightroom!" << std::endl;
    }

    if (!bossroom.loadFromFile("../../../src/Jeu/png/satanbossfinal.png"))
    {
        std::cerr << "Impossible de charger la textur  rightroom!" << std::endl;
    }

    room.setTexture(spone);
    room.setPosition(100, 25);
    room.setTextureRect(sf::IntRect(0, 0, 460, 305));
    room.setScale(3, 3);

    sheetsRoom.push_back(&spone); //0
    sheetsRoom.push_back(&rightroom); //1
    sheetsRoom.push_back(&shop); //2
    sheetsRoom.push_back(&basic); //3
    sheetsRoom.push_back(&bossroom); //4

}

void Scene::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform.combine(this->getTransform());

    target.draw(room, states);
}

#include "pch.h"
#include "Scene.h"
#include <iostream>

Scene::Scene()
{
    if (!spone.loadFromFile("../../../src/Jeu/png/spone.png"))
    {
        std::cerr << "Impossible de charger la texture spone!" << std::endl;
    }

    if (!rightroom.loadFromFile("../../../src/Jeu/png/womb.png"))
    {
        std::cerr << "Impossible de charger la texture rightroom!" << std::endl;
    }

    if (!shop.loadFromFile("../../../src/Jeu/png/room.png"))
    {
        std::cerr << "Impossible de charger la texture shop!" << std::endl;
    }

    if (!basic.loadFromFile("../../../src/Jeu/png/pieceennemy.png"))
    {
        std::cerr << "Impossible de charger la texture pieceennemy!" << std::endl;
    }

    if (!bossroom.loadFromFile("../../../src/Jeu/png/satanbossfinal.png"))
    {
        std::cerr << "Impossible de charger la texture satanbossfianl!" << std::endl;
    }

    if (!logo.loadFromFile("../../../src/Jeu/png/logo.png"))
    {
        std::cerr << "Impossible de charger la texture logo!" << std::endl;
    }

    if (!launcher.loadFromFile("../../../src/Jeu/png/launcher.png"))
    {
        std::cerr << "Impossible de charger la texture launcher!" << std::endl;
    }

    room.setTexture(logo);
    room.setPosition(100, 25);//400 50
    room.setTextureRect(sf::IntRect(0, 0, 460, 305));
    room.setScale(3, 3);

    sheetsRoom.push_back(&spone); //0
    sheetsRoom.push_back(&rightroom); //1
    sheetsRoom.push_back(&shop); //2
    sheetsRoom.push_back(&basic); //3
    sheetsRoom.push_back(&bossroom); //4
    sheetsRoom.push_back(&logo); //5
    sheetsRoom.push_back(&launcher); //6
}

void Scene::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform.combine(this->getTransform());

    target.draw(room, states);
}

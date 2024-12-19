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

    if (!aide.loadFromFile("../../../src/Jeu/png/aide.png"))
    {
        std::cerr << "Impossible de charger la texture launcher!" << std::endl;
    }

    if (!menu.loadFromFile("../../../src/Jeu/png/Menu.png"))
    {
        std::cerr << "Impossible de charger la texture launcher!" << std::endl;
    }

    if (!options.loadFromFile("../../../src/Jeu/png/options.png"))
    {
        std::cerr << "Impossible de charger la texture launcher!" << std::endl;
    }

    if (!credits.loadFromFile("../../../src/Jeu/png/credits.png"))
    {
        std::cerr << "Impossible de charger la texture launcher!" << std::endl;
    }

    if (!optionsMenu.loadFromFile("../../../src/Jeu/png/optionsMenu.png"))
    {
        std::cerr << "Impossible de charger la texture launcher!" << std::endl;
    }

    if (!gameOver.loadFromFile("../../../src/Jeu/png/gameover.png"))
    {
        std::cerr << "Impossible de charger la texture launcher!" << std::endl;
    }

    if (!letter.loadFromFile("../../../src/Jeu/png/letter.png"))
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
    sheetsRoom.push_back(&aide); //7
    sheetsRoom.push_back(&menu); //8
    sheetsRoom.push_back(&options); //9
    sheetsRoom.push_back(&credits); //10
    sheetsRoom.push_back(&optionsMenu); //11
    sheetsRoom.push_back(&gameOver); //12
    sheetsRoom.push_back(&letter); //13
}

void Scene::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform.combine(this->getTransform());

    target.draw(room, states);
}
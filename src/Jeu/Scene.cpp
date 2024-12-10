#include "pch.h"
#include "Scene.h"
#include <iostream>

Scene::Scene()
{
    if (!spone.loadFromFile("C:/Users/aledey/source/repos/SolutionGenerator/x64/Debug/Jeu/src/Jeu/png/spone.png"))
    {
        std::cerr << "Impossible de charger la textur  Left5!" << std::endl;
    }

    if (!rightroom.loadFromFile("C:/Users/aledey/source/repos/SolutionGenerator/x64/Debug/Jeu/src/Jeu/png/womb.png"))
    {
        std::cerr << "Impossible de charger la textur  Left5!" << std::endl;
    }

    room.setTexture(spone);
    room.setPosition(100, 25);
    room.setTextureRect(sf::IntRect(0, 0, 460, 305));
    room.setScale(3, 3);


    sheetsRoom.push_back(&spone);
    sheetsRoom.push_back(&rightroom);
}

void Scene::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform.combine(this->getTransform());

    target.draw(room, states);
}

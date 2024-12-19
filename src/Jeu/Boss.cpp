#include "pch.h"
#include "Boss.h"
#include <iostream>

Boss::Boss()
{
    mMaxHealth = 20;
    mCurrentHealth = 20;
    mAttack = 2;
    speedEnemy = 100.f;

    if (!BossLeg.loadFromFile("../../../src/Jeu/png/Boss satan.png", sf::IntRect(794, 0, 136, 243))) //1415 x 230
    {
        std::cerr << "Impossible de charger la texture PatateBase!" << std::endl;
    }

    spriteLeg.setTexture(BossLeg);
    setPosition(700, 400);
    spriteLeg.setOrigin(136/2, 243/3);
    spriteLeg.setScale(sf::Vector2f(3.f, 3.f));

    sheetsLeg.push_back(&BossLeg);

    position = { 236,80 };

}

void Boss::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform.combine(this->getTransform());

    target.draw(spriteLeg, states);
}
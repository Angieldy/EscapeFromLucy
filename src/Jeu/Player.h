#pragma once
#include "LivingEntity.h"

class Player : public LivingEntity
{
public:
	sf::Texture texturePause1;

	sf::Texture textureUp1;
	sf::Texture textureUp2;
	sf::Texture textureUp3;
	sf::Texture textureUp4;
	sf::Texture textureUp5;
	sf::Texture textureUp6;
	sf::Texture textureUp7;
	sf::Texture textureUp8;
	sf::Texture textureUp9;
	sf::Texture textureUp10;

	sf::Texture textureDown1;
	sf::Texture textureDown2;
	sf::Texture textureDown3;
	sf::Texture textureDown4;
	sf::Texture textureDown5;
	sf::Texture textureDown6;
	sf::Texture textureDown7;
	sf::Texture textureDown8;
	sf::Texture textureDown9;
	sf::Texture textureDown10;

	sf::Texture textureLeft1;
	sf::Texture textureLeft2;
	sf::Texture textureLeft3;
	sf::Texture textureLeft4;
	sf::Texture textureLeft5;
	sf::Texture textureLeft6;
	sf::Texture textureLeft7;
	sf::Texture textureLeft8;
	sf::Texture textureLeft9;
	sf::Texture textureLeft10;

	sf::Texture textureRigth1;
	sf::Texture textureRigth2;
	sf::Texture textureRigth3;
	sf::Texture textureRigth4;
	sf::Texture textureRigth5;
	sf::Texture textureRigth6;
	sf::Texture textureRigth7;
	sf::Texture textureRigth8;
	sf::Texture textureRigth9;
	sf::Texture textureRigth10;


	sf::Sprite spritePlayer;
	std::vector<sf::Texture*> sheetsPause;
	std::vector<sf::Texture*> sheetsUP;
	std::vector<sf::Texture*> sheetsDown;
	std::vector<sf::Texture*> sheetsLeft;
	std::vector<sf::Texture*> sheetsRight;

	Player();

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

};


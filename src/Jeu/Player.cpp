#include "pch.h"
#include "Player.h"
#include <iostream>


Player::Player()
{
	if (!texturePause1.loadFromFile("../../../src/Jeu/png/persoSkin.png", sf::IntRect(17, 13, 31, 38))) //777x513
	{
		std::cerr << "Impossible de charger la textur  pause1!" << std::endl;
	}

	// testure vers le bas
	if (!textureDown1.loadFromFile("../../../src/Jeu/png/persoSkin.png", sf::IntRect(17, 13, 31, 38))) //777x513
	{
		std::cerr << "Impossible de charger la textur  down1!" << std::endl;
	}
	if (!textureDown2.loadFromFile("../../../src/Jeu/png/persoSkin.png", sf::IntRect(48, 13, 31, 38))) //777x513
	{
		std::cerr << "Impossible de charger la textur  down2!" << std::endl;
	}
	if (!textureDown3.loadFromFile("../../../src/Jeu/png/persoSkin.png", sf::IntRect(83, 13, 31, 38))) //777x513
	{
		std::cerr << "Impossible de charger la textur  down3!" << std::endl;
	}
	if (!textureDown4.loadFromFile("../../../src/Jeu/png/persoSkin.png", sf::IntRect(114, 13, 31, 38))) //777x513
	{
		std::cerr << "Impossible de charger la textur  down4!" << std::endl;
	}
	if (!textureDown5.loadFromFile("../../../src/Jeu/png/persoSkin.png", sf::IntRect(145, 13, 31, 38))) //777x513
	{
		std::cerr << "Impossible de charger la textur  down5!" << std::endl;
	}
	if (!textureDown6.loadFromFile("../../../src/Jeu/png/persoSkin.png", sf::IntRect(177, 13, 31, 38))) //777x513
	{
		std::cerr << "Impossible de charger la textur  down6!" << std::endl;
	}
	if (!textureDown7.loadFromFile("../../../src/Jeu/png/persoSkin.png", sf::IntRect(208, 13, 31, 38))) //777x513
	{
		std::cerr << "Impossible de charger la textur  down7!" << std::endl;
	}
	if (!textureDown8.loadFromFile("../../../src/Jeu/png/persoSkin.png", sf::IntRect(243, 13, 31, 38))) //777x513
	{
		std::cerr << "Impossible de charger la textur  down8!" << std::endl;
	}
	if (!textureDown9.loadFromFile("../../../src/Jeu/png/persoSkin.png", sf::IntRect(17, 63, 31, 38))) //777x513
	{
		std::cerr << "Impossible de charger la textur  down9!" << std::endl;
	}
	if (!textureDown10.loadFromFile("../../../src/Jeu/png/persoSkin.png", sf::IntRect(48, 63, 31, 38))) //777x513
	{
		std::cerr << "Impossible de charger la textur  down10!" << std::endl;
	}

	//texture vers le hauts
	if (!textureUp1.loadFromFile("../../../src/Jeu/png/persoSkin.png", sf::IntRect(17, 345, 31, 38))) //777x513
	{
		std::cerr << "Impossible de charger la textur  up1!" << std::endl;
	}
	if (!textureUp2.loadFromFile("../../../src/Jeu/png/persoSkin.png", sf::IntRect(50, 345, 31, 38))) //777x513
	{
		std::cerr << "Impossible de charger la textur  up2!" << std::endl;
	}
	if (!textureUp3.loadFromFile("../../../src/Jeu/png/persoSkin.png", sf::IntRect(84, 345, 31, 38))) //777x513
	{
		std::cerr << "Impossible de charger la textur  up3!" << std::endl;
	}
	if (!textureUp4.loadFromFile("../../../src/Jeu/png/persoSkin.png", sf::IntRect(114, 345, 31, 38))) //777x513
	{
		std::cerr << "Impossible de charger la textur  up4!" << std::endl;
	}
	if (!textureUp5.loadFromFile("../../../src/Jeu/png/persoSkin.png", sf::IntRect(147, 345, 31, 38))) //777x513
	{
		std::cerr << "Impossible de charger la textur  up5!" << std::endl;
	}
	if (!textureUp6.loadFromFile("../../../src/Jeu/png/persoSkin.png", sf::IntRect(179, 345, 31, 38))) //777x513
	{
		std::cerr << "Impossible de charger la textur  up6!" << std::endl;
	}
	if (!textureUp7.loadFromFile("../../../src/Jeu/png/persoSkin.png", sf::IntRect(210, 345, 31, 38))) //777x513
	{
		std::cerr << "Impossible de charger la textur  up7!" << std::endl;
	}
	if (!textureUp8.loadFromFile("../../../src/Jeu/png/persoSkin.png", sf::IntRect(243, 345, 31, 38))) //777x513
	{
		std::cerr << "Impossible de charger la textur  up8!" << std::endl;
	}
	if (!textureUp9.loadFromFile("../../../src/Jeu/png/persoSkin.png", sf::IntRect(19, 387, 31, 38))) //777x513
	{
		std::cerr << "Impossible de charger la textur  up9!" << std::endl;
	}
	if (!textureUp10.loadFromFile("../../../src/Jeu/png/persoSkin.png", sf::IntRect(50, 345, 31, 38))) //777x513
	{
		std::cerr << "Impossible de charger la textur  up10!" << std::endl;
	}

	//texture vers la droite
	if (!textureRigth1.loadFromFile("../../../src/Jeu/png/persoSkin.png", sf::IntRect(19, 132, 31, 38))) //777x513
	{
		std::cerr << "Impossible de charger la textur  Right1!" << std::endl;
	}
	if (!textureRigth2.loadFromFile("../../../src/Jeu/png/persoSkin.png", sf::IntRect(52, 132, 31, 38))) //777x513
	{
		std::cerr << "Impossible de charger la textur  Right2!" << std::endl;
	}
	if (!textureRigth3.loadFromFile("../../../src/Jeu/png/persoSkin.png", sf::IntRect(84, 132, 31, 38))) //777x513
	{
		std::cerr << "Impossible de charger la textur  Right3!" << std::endl;
	}
	if (!textureRigth4.loadFromFile("../../../src/Jeu/png/persoSkin.png", sf::IntRect(116, 132, 31, 38))) //777x513
	{
		std::cerr << "Impossible de charger la textur  Right4!" << std::endl;
	}
	if (!textureRigth5.loadFromFile("../../../src/Jeu/png/persoSkin.png", sf::IntRect(149, 132, 31, 38))) //777x513
	{
		std::cerr << "Impossible de charger la textur  Right5!" << std::endl;
	}
	if (!textureRigth6.loadFromFile("../../../src/Jeu/png/persoSkin.png", sf::IntRect(180, 132, 31, 38))) //777x513
	{
		std::cerr << "Impossible de charger la textur  Right6!" << std::endl;
	}
	if (!textureRigth7.loadFromFile("../../../src/Jeu/png/persoSkin.png", sf::IntRect(213, 132, 31, 38))) //777x513
	{
		std::cerr << "Impossible de charger la textur  Right7!" << std::endl;
	}
	if (!textureRigth8.loadFromFile("../../../src/Jeu/png/persoSkin.png", sf::IntRect(245, 132, 31, 38))) //777x513
	{
		std::cerr << "Impossible de charger la textur  Right8!" << std::endl;
	}
	if (!textureRigth9.loadFromFile("../../../src/Jeu/png/persoSkin.png", sf::IntRect(19, 175, 31, 38))) //777x513
	{
		std::cerr << "Impossible de charger la textur  Right9!" << std::endl;
	}
	if (!textureRigth10.loadFromFile("../../../src/Jeu/png/persoSkin.png", sf::IntRect(52, 175, 31, 38))) //777x513
	{
		std::cerr << "Impossible de charger la textur  Right1!" << std::endl;
	}

	//vers la gauche
	if (!textureLeft1.loadFromFile("../../../src/Jeu/png/persoSkin.png", sf::IntRect(17, 238, 31, 38))) //777x513
	{
		std::cerr << "Impossible de charger la textur  Left1!" << std::endl;
	}
	if (!textureLeft2.loadFromFile("../../../src/Jeu/png/persoSkin.png", sf::IntRect(50, 238, 31, 38))) //777x513
	{
		std::cerr << "Impossible de charger la textur  Left2!" << std::endl;
	}
	if (!textureLeft3.loadFromFile("../../../src/Jeu/png/persoSkin.png", sf::IntRect(84, 238, 31, 38))) //777x513
	{
		std::cerr << "Impossible de charger la textur  Left3!" << std::endl;
	}
	if (!textureLeft4.loadFromFile("../../../src/Jeu/png/persoSkin.png", sf::IntRect(114, 238, 31, 38))) //777x513
	{
		std::cerr << "Impossible de charger la textur  Left4!" << std::endl;
	}
	if (!textureLeft5.loadFromFile("../../../src/Jeu/png/persoSkin.png", sf::IntRect(147, 238, 31, 38))) //777x513
	{
		std::cerr << "Impossible de charger la textur  Left5!" << std::endl;
	}
	if (!textureLeft6.loadFromFile("../../../src/Jeu/png/persoSkin.png", sf::IntRect(179, 238, 31, 38))) //777x513
	{
		std::cerr << "Impossible de charger la textur  Left6!" << std::endl;
	}
	if (!textureLeft7.loadFromFile("../../../src/Jeu/png/persoSkin.png", sf::IntRect(210, 238, 31, 38))) //777x513
	{
		std::cerr << "Impossible de charger la textur  Left7!" << std::endl;
	}
	if (!textureLeft8.loadFromFile("../../../src/Jeu/png/persoSkin.png", sf::IntRect(243, 238, 31, 38))) //777x513
	{
		std::cerr << "Impossible de charger la textur  Left1!" << std::endl;
	}
	if (!textureLeft9.loadFromFile("../../../src/Jeu/png/persoSkin.png", sf::IntRect(17, 282, 31, 38))) //777x513
	{
		std::cerr << "Impossible de charger la textur  Left9!" << std::endl;
	}
	if (!textureLeft10.loadFromFile("../../../src/Jeu/png/persoSkin.png", sf::IntRect(50, 238, 31, 38))) //777x513
	{
		std::cerr << "Impossible de charger la textur  Left10!" << std::endl;
	}

	spritePlayer.setTexture(texturePause1);
	setPosition(700, 400);
	spritePlayer.setOrigin(15.5f, 19.f);
	spritePlayer.setScale(sf::Vector2f(3.f, 3.f));

	sheetsUP.push_back(&textureUp1);
	sheetsUP.push_back(&textureUp2);
	sheetsUP.push_back(&textureUp3);
	sheetsUP.push_back(&textureUp4);
	sheetsUP.push_back(&textureUp5);
	sheetsUP.push_back(&textureUp6);
	sheetsUP.push_back(&textureUp7);
	sheetsUP.push_back(&textureUp8);
	sheetsUP.push_back(&textureUp9);
	sheetsUP.push_back(&textureUp10);

	sheetsDown.push_back(&textureDown1);
	sheetsDown.push_back(&textureDown2);
	sheetsDown.push_back(&textureDown3);
	sheetsDown.push_back(&textureDown4);
	sheetsDown.push_back(&textureDown5);
	sheetsDown.push_back(&textureDown6);
	sheetsDown.push_back(&textureDown7);
	sheetsDown.push_back(&textureDown8);
	sheetsDown.push_back(&textureDown9);
	sheetsDown.push_back(&textureDown10);

	sheetsLeft.push_back(&textureLeft1);
	sheetsLeft.push_back(&textureLeft2);
	sheetsLeft.push_back(&textureLeft3);
	sheetsLeft.push_back(&textureLeft4);
	sheetsLeft.push_back(&textureLeft5);
	sheetsLeft.push_back(&textureLeft6);
	sheetsLeft.push_back(&textureLeft7);
	sheetsLeft.push_back(&textureLeft8);
	sheetsLeft.push_back(&textureLeft9);
	sheetsLeft.push_back(&textureLeft10);

	sheetsRight.push_back(&textureRigth1);
	sheetsRight.push_back(&textureRigth2);
	sheetsRight.push_back(&textureRigth3);
	sheetsRight.push_back(&textureRigth4);
	sheetsRight.push_back(&textureRigth5);
	sheetsRight.push_back(&textureRigth6);
	sheetsRight.push_back(&textureRigth7);
	sheetsRight.push_back(&textureRigth8);
	sheetsRight.push_back(&textureRigth9);
	sheetsRight.push_back(&textureRigth10);


	const sf::Vector2f spriteSize(
		spritePlayer.getTexture()->getSize().x * spritePlayer.getScale().x,
		spritePlayer.getTexture()->getSize().y * spritePlayer.getScale().y);
	std::cerr << spriteSize.x << " " << spriteSize.y << std::endl;
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform.combine(this->getTransform());

	target.draw(spritePlayer, states);
}
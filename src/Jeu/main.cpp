#include "pch.h"
#include "main.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>
#include "Player.h"
#include "projectil.h"
#include "Scene.h"
#include "collidable.h"
#include "Poop.h"
#include "Heart.h"


int main()
{
#ifdef _DEBUG
	_CrtDumpMemoryLeaks();
#endif

    sf::RenderWindow window(sf::VideoMode(1600, 1000), "Escape From Lucy");

    std::vector<sf::RectangleShape> walls;
    std::vector<sf::RectangleShape> doors;
    std::vector<sf::RectangleShape> other;

    sf::RectangleShape wall1(sf::Vector2f(50, 200));
    wall1.setFillColor(sf::Color(255, 255, 255, 0)); // rend transparent
    wall1.setPosition(80, 190);
    wall1.setScale(3, 3);
    walls.push_back(wall1);

    sf::RectangleShape wall2(sf::Vector2f(360, 50));
    wall2.setFillColor(sf::Color(255, 255, 255, 0));
    wall2.setPosition(250, -20);
    wall2.setScale(3, 3);
    walls.push_back(wall2);

    sf::RectangleShape wall3(sf::Vector2f(50, 200));
    wall3.setFillColor(sf::Color(255, 255, 255, 0));
    wall3.setPosition(1350, 180);
    wall3.setScale(3, 3);
    walls.push_back(wall3);

    sf::RectangleShape wall4(sf::Vector2f(360, 50));
    wall4.setFillColor(sf::Color(255, 255, 255, 0));
    wall4.setPosition(250, 780);
    wall4.setScale(3, 3);
    walls.push_back(wall4);   

    sf::RectangleShape door1(sf::Vector2f(60, 20));
    door1.setFillColor(sf::Color(255, 255, 255, 0));
    door1.setPosition(80, 440);
    door1.setScale(3, 3);
    doors.push_back(door1);

    sf::RectangleShape door2(sf::Vector2f(40, 60));
    door2.setFillColor(sf::Color(255, 255, 255, 0));
    door2.setPosition(720, -40);
    door2.setScale(3, 3);
    doors.push_back(door2);

    sf::RectangleShape door3(sf::Vector2f(60, 20));
    door3.setFillColor(sf::Color(255, 255, 255, 0));
    door3.setPosition(1330, 440);
    door3.setScale(3, 3);
    doors.push_back(door3);

    sf::RectangleShape door4(sf::Vector2f(40, 60));
    door4.setFillColor(sf::Color(255, 255, 255, 0));
    door4.setPosition(720, 780);
    door4.setScale(3, 3);
    doors.push_back(door4);

    sf::RectangleShape shopik(sf::Vector2f(80, 15));
    shopik.setFillColor(sf::Color(255, 255, 255, 0));
    shopik.setPosition(670, 460);
    shopik.setScale(3, 3);
    other.push_back(shopik);

    sf::RectangleShape HangingMan(sf::Vector2f(30, 55));
    HangingMan.setFillColor(sf::Color(255, 255, 255, 0));
    HangingMan.setPosition(760, 100);
    HangingMan.setScale(3, 3);
    other.push_back(HangingMan);

    sf::Font font;

    if (!font.loadFromFile("../../../src/Jeu/png/font.ttf"))
    {
        return -1;
    }

    sf::Text start;
    sf::Text jouer;
    sf::Text options;
    sf::Text aide;
    sf::Text crédits;


    Player player;
    Scene scene;
    Poop poop;
    Heart heart;

    std::vector<projectil*> projectiles;

    sf::Clock clock;
    sf::Clock endLarme;

    float frameDuration = 0.1f;
    float speedLarme = 500.f;

    int currentFrame = 0;
    int currentFrameLarme = 0;
    int currentRoom = 5;

    int totalRoom;
    int totalFramesLarme;
    int totalFrames;

    float timeSinceLastShot = 0.0f; // Temps écoulé depuis le dernier tir
    float fireInterval = 0.5f;

    std::map<sf::Keyboard::Key, float> fireTimers = {
        {sf::Keyboard::Up, 0.f},
        {sf::Keyboard::Down, 0.f},
        {sf::Keyboard::Left, 0.f},
        {sf::Keyboard::Right, 0.f},
    };

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        float deltaTime = endLarme.restart().asSeconds();
        timeSinceLastShot += deltaTime;

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && !player.WallCollision(wall3, player.Bounds(player.spritePlayer)))//1200
        {
            const auto& currentSheets = player.sheetsRight;
            totalFrames = currentSheets.size();

            if (clock.getElapsedTime().asSeconds() > frameDuration)
            {
                currentFrame = (currentFrame + 1) % totalFrames;
                player.spritePlayer.setTexture(*currentSheets[currentFrame]);
                clock.restart();
            }
            //std::cout << player.getPosition().x << player.getPosition().y << std::endl;
            player.move(0.05f, 0.f);
        }

        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) && !player.WallCollision(wall1, player.Bounds(player.spritePlayer)))//150
        {
            const auto& currentSheets = player.sheetsLeft;
            totalFrames = currentSheets.size();

            if (clock.getElapsedTime().asSeconds() > frameDuration)
            {
                currentFrame = (currentFrame + 1) % totalFrames;
                player.spritePlayer.setTexture(*currentSheets[currentFrame]);
                clock.restart();
            }
            //std::cout << player.getPosition().x << player.getPosition().y << std::endl;

            player.move(-0.05f, 0.f);
        }

        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && !player.WallCollision(wall4, player.Bounds(player.spritePlayer)))//530
        {
            const auto& currentSheets = player.sheetsDown;
            totalFrames = currentSheets.size();

            if (clock.getElapsedTime().asSeconds() > frameDuration)
            {
                currentFrame = (currentFrame + 1) % totalFrames;
                player.spritePlayer.setTexture(*currentSheets[currentFrame]);
                clock.restart();
            }
            //std::cout << player.getPosition().x << player.getPosition().y << std::endl;

            player.move(0.f, 0.05f);
        }

        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z) && !player.WallCollision(wall2, player.Bounds(player.spritePlayer)))//60
        {
            const auto& currentSheets = player.sheetsUP;
            totalFrames = currentSheets.size();

            if (clock.getElapsedTime().asSeconds() > frameDuration)
            {
                currentFrame = (currentFrame + 1) % totalFrames;
                player.spritePlayer.setTexture(*currentSheets[currentFrame]);
                clock.restart();
            }
            //std::cout << player.getPosition().x << player.getPosition().y << std::endl;

            player.move(0.f, -0.05f);
        }

        else if (event.type == sf::Event::KeyReleased)
        {
            player.spritePlayer.setTexture(player.texturePause1);
        }
        //std::cout << player.getPosition().x << " " << player.getPosition().y << std::endl;

        

        for (auto & timer : fireTimers) 
        {
            timer.second += deltaTime;
        }

        // Gestion des tirs continus
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && fireTimers[sf::Keyboard::Up] >= fireInterval) 
        {
            projectil *newProjectile = new projectil();
            newProjectile->setPosition(player.getPosition());
            newProjectile->direction = sf::Vector2f(0.f, -1.f); // Direction haut
            projectiles.push_back(newProjectile);
            fireTimers[sf::Keyboard::Up] = 0.f;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && fireTimers[sf::Keyboard::Down] >= fireInterval) 
        {
            projectil* newProjectile = new projectil();
            newProjectile->setPosition(player.getPosition());
            newProjectile->direction = sf::Vector2f(0.f, 1.f); // Direction bas
            projectiles.push_back(newProjectile);
            fireTimers[sf::Keyboard::Down] = 0.f;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && fireTimers[sf::Keyboard::Left] >= fireInterval) 
        {
            projectil* newProjectile = new projectil();
            newProjectile->setPosition(player.getPosition());
            newProjectile->direction = sf::Vector2f(-1.f, 0.f); // Direction gauche
            projectiles.push_back(newProjectile);
            fireTimers[sf::Keyboard::Left] = 0.f;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && fireTimers[sf::Keyboard::Right] >= fireInterval) 
        {
            projectil* newProjectile = new projectil();
            newProjectile->setPosition(player.getPosition());
            newProjectile->direction = sf::Vector2f(1.f, 0.f); // Direction droite
            projectiles.push_back(newProjectile);
            fireTimers[sf::Keyboard::Right] = 0.f;
        }

        for (auto& proj : projectiles) 
        {
            if (!proj->WallCollision(wall1, proj->Bounds(proj->spriteLarmeBase)) && !proj->WallCollision(wall2, proj->Bounds(proj->spriteLarmeBase)) && !proj->WallCollision(wall3, proj->Bounds(proj->spriteLarmeBase)) && !proj->WallCollision(wall4, proj->Bounds(proj->spriteLarmeBase)))
            {
                proj->move(deltaTime, speedLarme);
            }
        }

        for (auto it = projectiles.begin(); it != projectiles.end(); ) 
        {
            bool collisionDetected = false;

            // Vérifier la collision avec chaque mur (ou autre objet)
            for (auto& wall : walls) 
            {
                if (player.WallCollision(wall, (*it)->Bounds((*it)->spriteLarmeBase)))
                {
                    collisionDetected = true;
                    break;  // On arrête dès qu'une collision est trouvée
                }
            }

            // Si une collision a été détectée, on supprime le projectile du vecteur
            if (collisionDetected) 
            {
                it = projectiles.erase(it);  // Supprimer le projectile
            }
            else 
            {
                ++it;  // Passer au projectile suivant si pas de collision
            }
        }

        if (currentRoom == 5)
        {
            player.spritePlayer.setColor(sf::Color(255, 255, 255, 1));

            scene.room.setPosition(400, 50);
            scene.room.setScale(0.8, 0.8);
            scene.room.setTextureRect(sf::IntRect(0, 0, 1024, 1024));

            start.setFont(font);
            start.setString("Cliquez sur n'importe quel bouton de la souris pour commencer.");
            start.setCharacterSize(45);
            start.setFillColor(sf::Color::Red);
            start.setPosition(0, 900);

            if (event.type == sf::Event::MouseButtonPressed)
            {
                const auto& currentSheetsRoom = scene.sheetsRoom;
                totalRoom = currentSheetsRoom.size();
                currentRoom = 6;
                scene.room.setTexture(*currentSheetsRoom[currentRoom]);
            }
        }

        if (currentRoom == 6)
        {
            scene.room.setPosition(0, 100);
            scene.room.setScale(3, 3);
            scene.room.setTextureRect(sf::IntRect(0, 0, 510, 596));

            player.spritePlayer.setColor(sf::Color(255, 255, 255, 1));

            jouer.setFont(font);
            jouer.setString("Jouer");
            jouer.setCharacterSize(60);
            jouer.setFillColor(sf::Color::White);
            jouer.setPosition(670, 650);

            options.setFont(font);
            options.setString("Options");
            options.setCharacterSize(60);
            options.setFillColor(sf::Color::White);
            options.setPosition(630, 725);

            aide.setFont(font);
            aide.setString("aide");
            aide.setCharacterSize(60);
            aide.setFillColor(sf::Color::White);
            aide.setPosition(690, 800);

            crédits.setFont(font);
            crédits.setString("Credits");
            crédits.setCharacterSize(60);
            crédits.setFillColor(sf::Color::White);
            crédits.setPosition(630, 875);

            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);

                    sf::FloatRect textBounds = jouer.getGlobalBounds();

                    if (textBounds.contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
                    {
                        const auto& currentSheetsRoom = scene.sheetsRoom;
                        totalRoom = currentSheetsRoom.size();
                        currentRoom = 0;
                        scene.room.setTexture(*currentSheetsRoom[currentRoom]);

                        scene.room.setPosition(100, 25);
                        scene.room.setTextureRect(sf::IntRect(0, 0, 460, 305));
                        scene.room.setScale(3, 3);

                        player.spritePlayer.setColor(sf::Color(255, 255, 255, 255));
                    }
                }
            }
        }

        if (currentRoom == 0)
        {
            if (player.DoorsCollision(door1, player.Bounds(player.spritePlayer)) && sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
            {
                const auto& currentSheetsRoom = scene.sheetsRoom;
                totalRoom = currentSheetsRoom.size();
                currentRoom = 1;
                player.setPosition(door3.getPosition());
                scene.room.setTexture(*currentSheetsRoom[currentRoom]);
                player.Bounds(player.spritePlayer) = player.spritePlayer.getGlobalBounds();

                player.Bounds(player.spritePlayer) = player.getTransform().transformRect(player.Bounds(player.spritePlayer));
                for (auto it = projectiles.begin(); it != projectiles.end(); )
                {
                    it = projectiles.erase(it);
                }
            }
            else if (player.DoorsCollision(door2, player.Bounds(player.spritePlayer)) && sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
            {
                const auto& currentSheetsRoom = scene.sheetsRoom;
                totalRoom = currentSheetsRoom.size();
                currentRoom = 3;

                player.setPosition(door4.getPosition().x + 70, door4.getPosition().y - 40);
                scene.room.setTexture(*currentSheetsRoom[currentRoom]);
                player.Bounds(player.spritePlayer) = player.spritePlayer.getGlobalBounds();

                player.Bounds(player.spritePlayer) = player.getTransform().transformRect(player.Bounds(player.spritePlayer));
                for (auto it = projectiles.begin(); it != projectiles.end(); )
                {
                    it = projectiles.erase(it);
                }
            }
            else if (player.DoorsCollision(door3, player.Bounds(player.spritePlayer)) && sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            {
                const auto& currentSheetsRoom = scene.sheetsRoom;
                totalRoom = currentSheetsRoom.size();

                player.setPosition(door1.getPosition().x + 180, door1.getPosition().y);
                currentRoom = 2;
                scene.room.setTexture(*currentSheetsRoom[currentRoom]);
                player.Bounds(player.spritePlayer) = player.spritePlayer.getGlobalBounds();

                player.Bounds(player.spritePlayer) = player.getTransform().transformRect(player.Bounds(player.spritePlayer));
                for (auto it = projectiles.begin(); it != projectiles.end(); )
                {
                    it = projectiles.erase(it);
                }
            }
        }

        else if (currentRoom == 1)
        {
            if (player.DoorsCollision(door3, player.Bounds(player.spritePlayer)) && sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            {
                const auto& currentSheetsRoom = scene.sheetsRoom;
                totalRoom = currentSheetsRoom.size();
                currentRoom = 0;

                player.setPosition(door1.getPosition().x + 180, door1.getPosition().y);
                scene.room.setTexture(*currentSheetsRoom[currentRoom]);
                player.Bounds(player.spritePlayer) = player.spritePlayer.getGlobalBounds();

                player.Bounds(player.spritePlayer) = player.getTransform().transformRect(player.Bounds(player.spritePlayer));
                for (auto it = projectiles.begin(); it != projectiles.end(); )
                {
                    it = projectiles.erase(it);
                }
            }
        }

        if (currentRoom == 2)
        {
            if (player.OtherCollision(shopik, player.Bounds(player.spritePlayer)))
            {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                {
                    player.move(-0.05f, 0.f);
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
                {
                    player.move(0.05f, 0.f);
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
                {
                    player.move(0.f, -0.05f);
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
                {
                    player.move(0.f, 0.05f);
                }
                
            }

            if (player.OtherCollision(HangingMan, player.Bounds(player.spritePlayer)))
            {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                {
                    player.move(-0.05f, 0.f);
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
                {
                    player.move(0.05f, 0.f);
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
                {
                    player.move(0.f, -0.05f);
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
                {
                    player.move(0.f, 0.05f);
                }

            }

            if (player.DoorsCollision(door1, player.Bounds(player.spritePlayer)) && sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
            {
                const auto& currentSheetsRoom = scene.sheetsRoom;
                totalRoom = currentSheetsRoom.size();
                currentRoom = 0;
                player.setPosition(door3.getPosition());
                scene.room.setTexture(*currentSheetsRoom[currentRoom]);
                player.Bounds(player.spritePlayer) = player.spritePlayer.getGlobalBounds();

                player.Bounds(player.spritePlayer) = player.getTransform().transformRect(player.Bounds(player.spritePlayer));
                for (auto it = projectiles.begin(); it != projectiles.end(); )
                {
                    it = projectiles.erase(it);
                }
            }
        }

        if (currentRoom == 3)
        {
            if (player.DoorsCollision(door2, player.Bounds(player.spritePlayer)) && sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
            {
                const auto& currentSheetsRoom = scene.sheetsRoom;
                totalRoom = currentSheetsRoom.size();
                currentRoom = 4;

                player.setPosition(door4.getPosition().x + 70, door4.getPosition().y - 40);
                scene.room.setTexture(*currentSheetsRoom[currentRoom]);
                player.Bounds(player.spritePlayer) = player.spritePlayer.getGlobalBounds();

                player.Bounds(player.spritePlayer) = player.getTransform().transformRect(player.Bounds(player.spritePlayer));
            }
            else if (player.DoorsCollision(door4, player.Bounds(player.spritePlayer)) && sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            {
                const auto& currentSheetsRoom = scene.sheetsRoom;
                totalRoom = currentSheetsRoom.size();
                currentRoom = 0;

                player.setPosition(door2.getPosition().x + 70, door2.getPosition().y + 180);
                scene.room.setTexture(*currentSheetsRoom[currentRoom]);
                player.Bounds(player.spritePlayer) = player.spritePlayer.getGlobalBounds();

                player.Bounds(player.spritePlayer) = player.getTransform().transformRect(player.Bounds(player.spritePlayer));
                for (auto it = projectiles.begin(); it != projectiles.end(); )
                {
                    it = projectiles.erase(it);
                }
            }
        }

        if (currentRoom == 4)
        {
            if (player.DoorsCollision(door4, player.Bounds(player.spritePlayer)) && sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            {
                const auto& currentSheetsRoom = scene.sheetsRoom;
                totalRoom = currentSheetsRoom.size();
                currentRoom = 3;
                scene.room.setTexture(*currentSheetsRoom[currentRoom]);
                player.Bounds(player.spritePlayer) = player.spritePlayer.getGlobalBounds();

                player.Bounds(player.spritePlayer) = player.getTransform().transformRect(player.Bounds(player.spritePlayer));
                for (auto it = projectiles.begin(); it != projectiles.end(); )
                {
                    it = projectiles.erase(it);
                }
            }
        }
        
        if (player.mCurrentHealth == 11)
        {
            heart.Heart3.setTexture(heart.quartHeart);
        }
        else if (player.mCurrentHealth == 10)
        {
            heart.Heart3.setTexture(heart.middleHeart);
        }
        else if (player.mCurrentHealth == 9)
        {
            heart.Heart3.setTexture(heart.unQuartHeart);
        }
        else if (player.mCurrentHealth == 8)
        {
            heart.Heart3.setTexture(heart.emptyHeart);
        }
        else if (player.mCurrentHealth == 7)
        {
            heart.Heart2.setTexture(heart.quartHeart);
            heart.Heart3.setTexture(heart.emptyHeart);
        }
        else if (player.mCurrentHealth == 6)
        {
            heart.Heart2.setTexture(heart.middleHeart);
            heart.Heart3.setTexture(heart.emptyHeart);
        }
        else if (player.mCurrentHealth == 5)
        {
            heart.Heart2.setTexture(heart.unQuartHeart);
            heart.Heart3.setTexture(heart.emptyHeart);
        }
        else if (player.mCurrentHealth == 4)
        {
            heart.Heart2.setTexture(heart.emptyHeart);
            heart.Heart3.setTexture(heart.emptyHeart);
        }
        else if (player.mCurrentHealth == 3)
        {
            heart.Heart1.setTexture(heart.quartHeart);
            heart.Heart2.setTexture(heart.emptyHeart);
            heart.Heart3.setTexture(heart.emptyHeart);
        }
        else if (player.mCurrentHealth == 2)
        {
            heart.Heart1.setTexture(heart.middleHeart);
            heart.Heart2.setTexture(heart.emptyHeart);
            heart.Heart3.setTexture(heart.emptyHeart);
        }
        else if (player.mCurrentHealth == 1)
        {
            heart.Heart1.setTexture(heart.unQuartHeart);
            heart.Heart2.setTexture(heart.emptyHeart);
            heart.Heart3.setTexture(heart.emptyHeart);
        }
        else if (player.mCurrentHealth == 0)
        {
            heart.Heart1.setTexture(heart.emptyHeart);
            heart.Heart2.setTexture(heart.emptyHeart);
            heart.Heart3.setTexture(heart.emptyHeart);
        }
       
        window.draw(scene);
        if (currentRoom == 5)
        {
            window.draw(start);
        }
        else if (currentRoom == 6)
        {
            window.draw(jouer);
            window.draw(options);
            window.draw(aide);
            window.draw(crédits);
        }

        else
        {
            window.draw(door1);
            window.draw(door2);
            window.draw(door3);
            window.draw(door4);
            window.draw(wall1);
            window.draw(wall2);
            window.draw(wall3);
            window.draw(wall4);
            window.draw(shopik);
            window.draw(HangingMan);
            window.draw(poop);

            window.draw(heart);

            window.draw(player);
        }

        for (projectil* proj : projectiles) 
        {
            window.draw(*proj);
        }

        window.display();
    }
	return 0;
}

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


int main()
{
#ifdef _DEBUG
	_CrtDumpMemoryLeaks();
#endif

    sf::RenderWindow window(sf::VideoMode(1600, 1000), "Escape From Luccy");

    std::vector<sf::RectangleShape> walls;
    std::vector<sf::RectangleShape> doors;

    sf::RectangleShape wall1(sf::Vector2f(50, 200));
    wall1.setFillColor(sf::Color(255, 255, 255, 1)); // rend transparent
    wall1.setPosition(100, 190);
    wall1.setScale(3, 3);
    walls.push_back(wall1);

    sf::RectangleShape wall2(sf::Vector2f(360, 50));
    wall2.setFillColor(sf::Color(255, 255, 255, 1));
    wall2.setPosition(250, 30);
    wall2.setScale(3, 3);
    walls.push_back(wall2);

    sf::RectangleShape wall3(sf::Vector2f(50, 200));
    wall3.setFillColor(sf::Color(255, 255, 255, 1));
    wall3.setPosition(1330, 180);
    wall3.setScale(3, 3);
    walls.push_back(wall3);

    sf::RectangleShape wall4(sf::Vector2f(360, 50));
    wall4.setFillColor(sf::Color(255, 255, 255, 1));
    wall4.setPosition(250, 780);
    wall4.setScale(3, 3);
    walls.push_back(wall4);

    sf::RectangleShape door2(sf::Vector2f(40, 60));
    door2.setFillColor(sf::Color::Red);
    door2.setPosition(720, -50);
    door2.setScale(3, 3);
    doors.push_back(door2);

    sf::RectangleShape door1(sf::Vector2f(60, 20));
    door1.setFillColor(sf::Color::Red);
    door1.setPosition(80, 440);
    door1.setScale(3, 3);
    doors.push_back(door1);

    sf::RectangleShape door3(sf::Vector2f(60, 20));
    door3.setFillColor(sf::Color::Red);
    door3.setPosition(1330, 440);
    door3.setScale(3, 3);
    doors.push_back(door3);

    Player player;
    projectil Projectil;
    Scene scene;

    sf::Clock clock;
    float frameDuration = 0.1f;
    int currentFrame = 0;
    int totalFrames;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        bool collision = false;
        for (const auto& wall : walls)
        {
            if (player.WallCollision(wall1, player.spritePlayer))
            {
                collision = true;
            }
            else if (player.WallCollision(wall2, player.spritePlayer))
            {
                collision = true;
            }
            else if (player.WallCollision(wall3, player.spritePlayer))
            {
                collision = true;
            }
            else if (player.WallCollision(wall4, player.spritePlayer))
            {
                collision = true;
            }
        }
        for (const auto& door : doors)
        {
            if (player.DoorsCollision(door1, player.spritePlayer))
            {
                collision = true;
                const auto& currentSheets = scene.sheetsRoom;
                scene.room.setTexture(*currentSheets[1]); //Right Room
            }
            else if (player.DoorsCollision(door2, player.spritePlayer))
            {
                collision = true;
            }
            else if (player.DoorsCollision(door3, player.spritePlayer))
            {
                collision = true;
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && !player.WallCollision(wall3, player.spritePlayer))//1200
        {
            const auto& currentSheets = player.sheetsRight;
            totalFrames = currentSheets.size();

            if (clock.getElapsedTime().asSeconds() > frameDuration)
            {
                currentFrame = (currentFrame + 1) % totalFrames;
                player.spritePlayer.setTexture(*currentSheets[currentFrame]);
                clock.restart();
            }

            player.move(0.05f, 0.f);
        }

        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) && !player.WallCollision(wall1, player.spritePlayer))//150
        {
            const auto& currentSheets = player.sheetsLeft;
            totalFrames = currentSheets.size();

            if (clock.getElapsedTime().asSeconds() > frameDuration)
            {
                currentFrame = (currentFrame + 1) % totalFrames;
                player.spritePlayer.setTexture(*currentSheets[currentFrame]);
                clock.restart();
            }

            player.move(-0.05f, 0.f);
        }

        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && !player.WallCollision(wall4, player.spritePlayer))//530
        {
            const auto& currentSheets = player.sheetsDown;
            totalFrames = currentSheets.size();

            if (clock.getElapsedTime().asSeconds() > frameDuration)
            {
                currentFrame = (currentFrame + 1) % totalFrames;
                player.spritePlayer.setTexture(*currentSheets[currentFrame]);
                clock.restart();
            }

            player.move(0.f, 0.05f);
        }

        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z) && !player.WallCollision(wall2, player.spritePlayer))//60
        {
            const auto& currentSheets = player.sheetsUP;
            totalFrames = currentSheets.size();

            if (clock.getElapsedTime().asSeconds() > frameDuration)
            {
                currentFrame = (currentFrame + 1) % totalFrames;
                player.spritePlayer.setTexture(*currentSheets[currentFrame]);
                clock.restart();
            }

            player.move(0.f, -0.05f);
        }

        else if (event.type == sf::Event::KeyReleased)
        {
            player.spritePlayer.setTexture(player.texturePause1);
        }

        window.clear(sf::Color::Black);

        
        window.draw(scene);
        window.draw(wall1);
        window.draw(wall2);
        window.draw(wall3);
        window.draw(wall4);
        window.draw(door1);
        window.draw(door2);
        window.draw(door3);

        window.draw(player);
        window.draw(Projectil);

        window.display();
    }
	return 0;
}

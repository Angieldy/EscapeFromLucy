#include "pch.h"
#include "main.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>


int main()
{
#ifdef _DEBUG
	_CrtDumpMemoryLeaks();
#endif
		sf::RenderWindow window(sf::VideoMode(1600, 1000), "Escape From Luccy");

		sf::Texture texture;

		if (!texture.loadFromFile("../../../src/Jeu/Cellar.png"))
		{
			return -1;
		}

		sf::Sprite spone(texture);
        spone.setPosition(50, 25);
        //spone.setOrigin(800, 145);
        spone.setTextureRect(sf::IntRect(0, 0, 379, 298));
        spone.setScale(4,3);

        sf::Texture txtplayer;

        if (!txtplayer.loadFromFile("C:/Users/aledey/source/repos/SolutionGenerator/x64/Debug/Jeu/src/Jeu/isaac.png"))
        {
            return -1;
        }

        sf::Sprite player(txtplayer);

        player.setTextureRect(sf::IntRect(0, 0, 148, 125));
        int x = 700;
        int y = 400;
        player.setPosition(x, y);
        player.setScale(1.5, 1.5);

		//sf::View view(sf::FloatRect(0, 0, 1400, 800));
		//view.setCenter(player.getPosition());

		sf::Keyboard::Key last;

        sf::Clock clock;
        while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();

                if (event.type == sf::Event::KeyPressed)
                {
                    last = event.key.code;

                    if (last == sf::Keyboard::D)
                    {
                        x += 10;
                    }

                    else if (last == sf::Keyboard::Q)
                    {
                        x -= 10;
                    }

                    else if (last == sf::Keyboard::Z)
                    {
                        y -= 10;
                    }

                    else if (last == sf::Keyboard::S)
                    {
                        y += 10;
                    }
                }
            }

            float deltaTime = clock.restart().asSeconds();

           /* view.setCenter(player.getPosition());

            window.setView(view);*/

            player.setPosition(x, y);

            window.clear();

            window.draw(spone);

            window.draw(player);

            window.display();
        }
	return 0;
}

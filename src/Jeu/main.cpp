#include "pch.h"
#include "main.h"
#include <SFML/Graphics.hpp>

int main()
{
#ifdef _DEBUG
	_CrtDumpMemoryLeaks();
#endif
		sf::RenderWindow window(sf::VideoMode(1400, 800), "Escape From Luccy");

		sf::Texture texture;

		if (!texture.loadFromFile("../../../src/Jeu/Cellar.png"))
		{
			return -1;
		}

		sf::Sprite spone(texture);
		spone.setOrigin(700, 400);
        spone.setScale(sf::Vector2f(10, 10));
		spone.setTextureRect(sf::IntRect(0, 0, 250, 200));

        sf::Texture txtplayer;

        if (!txtplayer.loadFromFile("../../../src/Jeu/perso.png"))
        {
            return -1;
        }

        sf::Sprite player(txtplayer);

        player.setTextureRect(sf::IntRect(10, 250, 100, 100));
        int x = 1;
        int y = 1;
        player.setPosition(x, y);
        player.setScale(1, 1);

		sf::View view(sf::FloatRect(0, 0, 1400, 800));
		view.setCenter(player.getPosition());

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

                    if (last == 72)
                    {
                        x += 10;
                    }

                    else if (last == 71)
                    {
                        x -= 10;
                    }

                    else if (last == 73)
                    {
                        y -= 10;
                    }

                    else if (last == 74)
                    {
                        y += 10;
                    }
                }
            }

            float deltaTime = clock.restart().asSeconds();

            view.setCenter(player.getPosition());

            window.setView(view);

            player.setPosition(x, y);

            window.clear();

            window.draw(spone);
            window.draw(player);

            window.display();
        }
	return 0;
}

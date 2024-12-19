#pragma once
#include <SFML/Graphics.hpp>

class Entity : public sf::Transformable, public sf::Drawable
{

public:

	sf::Vector2f normalize(const sf::Vector2f& vector);
};


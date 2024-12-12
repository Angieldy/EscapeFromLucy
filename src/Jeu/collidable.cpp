#include "pch.h"
#include "collidable.h"

collidable::collidable()
{

}

bool collidable::collideSprite(const sf::Sprite& other1, const sf::Sprite& other2) const
{
	if (other1.getGlobalBounds().intersects(other2.getGlobalBounds()))
	{
		return true;
	}
	return false;
}

bool collidable::WallCollision(const sf::RectangleShape& rect1, const sf::FloatRect& playerBounds) const
{
	if (rect1.getGlobalBounds().intersects(playerBounds))
	{
		return true;
	}
	return false;
}

bool collidable::DoorsCollision(const sf::RectangleShape& rect1, const sf::FloatRect& playerBounds) const
{
	if (rect1.getGlobalBounds().intersects(playerBounds))
	{
		return true;
	}
	return false;
}

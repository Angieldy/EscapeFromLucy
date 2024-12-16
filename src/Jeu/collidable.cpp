#include "pch.h"
#include "collidable.h"

collidable::collidable()
{

}

sf::FloatRect collidable::Bounds(sf::Sprite object)
{
	GlobalBounds = object.getGlobalBounds();

	GlobalBounds = getTransform().transformRect(GlobalBounds);

	return GlobalBounds;
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

bool collidable::OtherCollision(const sf::RectangleShape& rect1, const sf::FloatRect& playerBounds) const
{
	if (rect1.getGlobalBounds().intersects(playerBounds))
	{
		return true;
	}
	return false;
}

bool collidable::ProjectilCollision(const sf::RectangleShape& rect1, const sf::FloatRect& projectilBounds) const
{
	if (rect1.getGlobalBounds().intersects(projectilBounds))
	{
		return true;
	}
	return false;
}

//bool collidable::TextCollision(const sf::Text& rect1, const sf::Event& clickLeft) const
//{
//	if (rect1.getGlobalBounds().intersects(clickLeft))
//	{
//		return true;
//	}
//	return false;
//}


#include "pch.h"
#include "collidable.h"

collidable::collidable()
{

}

bool collidable::collide(const sf::Sprite& other1, const sf::Sprite& other2) const
{
	if (other1.getGlobalBounds().intersects(other2.getGlobalBounds()))
	{
		return true;
	}
	return false;
}
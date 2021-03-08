#include "Laser3.h"

const float SPEED = 1.2f;

Laser3::Laser3(sf::Vector2f pos)
{
	sprite_.setTexture(GAME.getTexture("Resources/laser.png"));
	sprite_.setPosition(pos);
	assignTag("laser3");
}
void Laser3::draw()
{
	GAME.getRenderWindow().draw(sprite_);
}
void Laser3::update(sf::Time& elapsed)
{
	int msElapsed = elapsed.asMilliseconds();
	sf::Vector2f pos = sprite_.getPosition();
	if (pos.x > GAME.getRenderWindow().getSize().x)
	{
		makeDead();
	}
	else
	{
		sprite_.setPosition(sf::Vector2f(pos.x + SPEED * msElapsed, pos.y));
	}
}

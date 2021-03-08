#include "Laser2.h"

const float SPEED = 1.2f;

Laser2::Laser2(sf::Vector2f pos)
{
	sprite_.setTexture(GAME.getTexture("Resources/laser.png"));
	sprite_.setPosition(pos);
	assignTag("laser2");
}
void Laser2::draw()
{
	GAME.getRenderWindow().draw(sprite_);
}
void Laser2::update(sf::Time& elapsed)
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

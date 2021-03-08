#include "Ship.h"
#include "Laser.h"
#include <memory>
#include "Laser2.h"
#include "Laser3.h"

const float SPEED = 0.5f;
const int FIRE_DELAY = 200;
Ship::Ship()
{
	sprite_.setTexture(GAME.getTexture("Resources/ship.png"));
	sprite_.setPosition(sf::Vector2f(100, 100));
}
void Ship::draw()
{
	GAME.getRenderWindow().draw(sprite_);
}

void Ship::update(sf::Time& elapsed)
{
	sf::Vector2f pos = sprite_.getPosition();
	float x = pos.x;
	float y = pos.y;
	int msElapsed = elapsed.asMilliseconds();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) y -= SPEED * msElapsed;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) y += SPEED * msElapsed;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) x -= SPEED * msElapsed;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) x += SPEED * msElapsed;
	sprite_.setPosition(sf::Vector2f(x, y));

	if (fireTimer_ > 0)
	{
		fireTimer_ -= msElapsed;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && fireTimer_ <= 0)
	{
		fireTimer_ = FIRE_DELAY;
		sf::FloatRect bounds = sprite_.getGlobalBounds();
		float laserX = x + bounds.width;
		float laserY = y + (bounds.height / 2.0f);
		float laserX2 = x + bounds.width;
		float laserY2= y + bounds.height;
		float laserX3 = x + bounds.width;
		float laserY3 = y + (2.0f / bounds.height);
		LaserPtr laser = std::make_shared<Laser>(sf::Vector2f(laserX, laserY));
		LaserPtr2 laser2 = std::make_shared<Laser2>(sf::Vector2f(laserX2, laserY2));
		LaserPtr3 laser3 = std::make_shared<Laser3>(sf::Vector2f(laserX3, laserY3));
		GAME.getCurrentScene().addGameObject(laser);
		GAME.getCurrentScene().addGameObject(laser2);
		GAME.getCurrentScene().addGameObject(laser3);

	}
}
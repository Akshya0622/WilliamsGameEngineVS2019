#include "background.h"
#include "GameScene.h"

const float SPEED = 0.25f;

background::background()
{

	sprite_.setTexture(GAME.getTexture("Resources/background.png"));
	sprite_.setScale(2,2);
	sprite2_.setTexture(GAME.getTexture("Resources/background.png"));
	sprite2_.setScale(4,4);
	
}
void background::draw()
{
	GAME.getRenderWindow().draw(sprite_);
	GAME.getRenderWindow().draw(sprite2_);
}
void background::update(sf::Time& elapsed)
{
	int msElapsed = elapsed.asMilliseconds();

	sf::Vector2f pos = sprite_.getPosition();
	sf::Vector2f pos2 = sprite2_.getPosition();
	sprite_.setPosition(sf::Vector2f(pos.x - SPEED * msElapsed, pos.y));
	sprite2_.setPosition(sf::Vector2f(pos2.x - SPEED * msElapsed, pos2.y));
	if (pos.x < sprite_.getGlobalBounds().width * -1)
	{
		sprite2_.setPosition(sf::Vector2f((sprite_.getGlobalBounds().width - SPEED * msElapsed) + pos.x, pos.y));
		sprite_.setPosition(sf::Vector2f ((sprite_.getGlobalBounds().width - SPEED * msElapsed)+pos.x, pos.y));
	}

	
	
	

		

	
	
	
}

#include "background.h"
#include "GameScene.h"

const float SPEED = 0.25f;
const int SPAWN_DELAY = 1000;
background::background()
{

	sprite_.setTexture(GAME.getTexture("Resources/space-game-background_7814-427.jpg"));
	sprite_.setScale(2,2);

}
void background::draw()
{
	GAME.getRenderWindow().draw(sprite_);
}
void background::update(sf::Time& elapsed)
{

	
		int msElapsed = elapsed.asMilliseconds();
		
		sf::Vector2f pos = sprite_.getPosition();

		sprite_.setPosition(sf::Vector2f(pos.x - SPEED * msElapsed, pos.y));
		

	
	
	
}

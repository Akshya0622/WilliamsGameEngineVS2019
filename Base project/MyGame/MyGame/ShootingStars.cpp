#include "ShootingStars.h"
#include "GameScene.h"
#include "Explosion.h"


const float SPEED = 0.25f;

ShootingStars::ShootingStars(sf::Vector2f pos)
{
	sprite_.setTexture(GAME.getTexture("Resources/shootingstar.png"));
	sprite_.setPosition(pos);
	sprite_.setScale(.5, .5);
	assignTag("star");
}
void ShootingStars::draw()
{
	GAME.getRenderWindow().draw(sprite_);
}
void ShootingStars::update(sf::Time& elapsed)
{
	int msElapsed = elapsed.asMilliseconds();
	sf::Vector2f pos = sprite_.getPosition();
	if (pos.x < sprite_.getGlobalBounds().width * -1)
	{
		GameScene& scene = (GameScene&)GAME.getCurrentScene();
		makeDead();
	}
	else
	{
		sprite_.setPosition(sf::Vector2f(pos.x - SPEED * msElapsed, pos.y));
	}
}
sf::FloatRect ShootingStars::getCollisionRect()
{
	return sprite_.getGlobalBounds();
}
void ShootingStars::handleCollision(GameObject& otherGameObject)
{
	if (otherGameObject.hasTag("ship"))
	{
		sf::Vector2f pos = sprite_.getPosition();
		ExplosionPtr ex = std::make_shared<Explosion>(pos);
		GAME.getCurrentScene().addGameObject(ex);
		GameScene& scene = (GameScene&)GAME.getCurrentScene();
		scene.increaseLives();
		makeDead();
	}
	

}
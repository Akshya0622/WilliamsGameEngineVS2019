#include "Meteor.h"
#include "GameScene.h"
#include "Explosion.h"
#include "Explosion2.h"



const float SPEED = 0.25f;

Meteor::Meteor(sf::Vector2f pos)
{
	sprite_.setTexture(GAME.getTexture("Resources/meteors.png"));
	sprite_.setPosition(pos);
	sprite_.setScale(.3, .3);
	assignTag("meteor");
}
void Meteor::draw()
{
	GAME.getRenderWindow().draw(sprite_);
}
void Meteor::update(sf::Time& elapsed) 
{
	int msElapsed = elapsed.asMilliseconds();
	sf::Vector2f pos = sprite_.getPosition();
	if (pos.x < sprite_.getGlobalBounds().width * -1)
	{
		GameScene& scene = (GameScene&)GAME.getCurrentScene();
		scene.decreaseLives();
		makeDead();
	}
	else
	{
		sprite_.setPosition(sf::Vector2f(pos.x - SPEED * msElapsed, pos.y));
	}
}

sf::FloatRect Meteor::getCollisionRect()
{
	return sprite_.getGlobalBounds(); 
}
void Meteor::handleCollision(GameObject& otherGameObject)
{
	if (otherGameObject.hasTag("laser"))
	{
		sf::Vector2f pos = sprite_.getPosition();
		ExplosionPtr ex = std::make_shared<Explosion>(pos);
		GAME.getCurrentScene().addGameObject(ex);
		otherGameObject.makeDead();
		GameScene& scene = (GameScene&)GAME.getCurrentScene();
		scene.increaseScore();
		makeDead();
	}
	if (otherGameObject.hasTag("ship"))
	{
		sf::Vector2f pos = sprite_.getPosition();
		Explosion2Ptr ex2 = std::make_shared<Explosion2>(pos);
		GAME.getCurrentScene().addGameObject(ex2);
		GameScene& scene = (GameScene&)GAME.getCurrentScene();
		scene.decreaseLives();
		makeDead();
	}
	
}
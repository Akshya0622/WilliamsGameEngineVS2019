#include "SpawnBackground.h"

const int SPAWN_DELAY = 1000;


void SpawnBackground::update(sf::Time& elapsed)
{
	int msElapsed = elapsed.asMilliseconds();
	timer_ -= msElapsed;
	if (timer_ <= 0)
	{
		timer_ = SPAWN_DELAY;
		sf::Vector2u size = GAME.getRenderWindow().getSize();

		
		float backX = (float)(size.x);
		float backY = (float)(size.y);

		//backgroundPtr scene = std::make_shared<background>(sf::Vector2f(backX, backY));
		//GAME.getCurrentScene().addGameObject(scene);
		
	}
}
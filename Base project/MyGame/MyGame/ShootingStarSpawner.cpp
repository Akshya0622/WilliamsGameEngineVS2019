#include "ShootingStarSpawner.h"

const int SPAWN_DELAY = 1000;

void ShootingStarSpawner::update(sf::Time& elapsed)
{
	// Determine how much time has passed and adjust our timer.
	int msElapsed = elapsed.asMilliseconds();
	timer_ -= msElapsed;

	// If our timer has elapsed, reset it and spawn a star.
	if (timer_ <= 0)
	{
		timer_ = SPAWN_DELAY;
		sf::Vector2u size = GAME.getRenderWindow().getSize();

		// Spawn the star off the right side of the screen.
		// We're assuming the star isn't more than 100 pixels wide.
		float starX = (float)(size.x + 100);

		// Spawn the star somewhere along the height of window, randomly.
		float starY = (float)(rand() % size.y);

		// Create a star and add it to the scene
		ShootingStarsPtr star = std::make_shared<ShootingStars>(sf::Vector2f(starX, starY));
		GAME.getCurrentScene().addGameObject(star);
	}
}

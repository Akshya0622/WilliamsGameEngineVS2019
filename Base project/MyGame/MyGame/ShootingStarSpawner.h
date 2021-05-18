#pragma once
#include "Engine/GameEngine.h"
#include "ShootingStars.h"

class ShootingStarSpawner : public GameObject
{
public:
	void update(sf::Time& elapsed);

private:
	int timer_ = 0;
};

typedef std::shared_ptr<ShootingStarSpawner> ShootingStarSpawnerPtr;

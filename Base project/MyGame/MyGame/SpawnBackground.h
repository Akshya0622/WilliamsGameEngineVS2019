#pragma once
#include "Engine/GameEngine.h"
#include "background.h"

class SpawnBackground : public GameObject
{
public:

	void update(sf::Time& elapsed);



private:
	int timer_ = 0;
	sf::Sprite sprite_;
};

typedef std::shared_ptr<SpawnBackground> SpawnBackgroundPtr;


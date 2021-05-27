#pragma once
#include "Engine/GameEngine.h"
class Explosion2 : public AnimatedSprite
{
public:
	// Creates our Explosion.
	Explosion2(sf::Vector2f pos);


	void update(sf::Time& elapsed);

private:
	void SetUpExplosionAnimation();
	sf::Sound boom_;
};
typedef std::shared_ptr<Explosion2> Explosion2Ptr;
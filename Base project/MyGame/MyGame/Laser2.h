#pragma once
#include "Engine/GameEngine.h"

class Laser2 : public GameObject
{
public:
	Laser2(sf::Vector2f pos); //creates laser

	void draw();
	void update(sf::Time& elapsed);

private:
	sf::Sprite sprite_;

};

typedef std::shared_ptr<Laser2> LaserPtr2;

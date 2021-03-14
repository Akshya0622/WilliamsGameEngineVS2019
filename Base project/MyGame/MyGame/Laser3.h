#pragma once
#include "Engine/GameEngine.h"

class Laser3 : public GameObject
{
public:
	Laser3(sf::Vector2f pos); //creates laser

	void draw();
	void update(sf::Time& elapsed);
	sf::FloatRect getCollisionRect();


private:
	sf::Sprite sprite_;

};

typedef std::shared_ptr<Laser3> LaserPtr3;


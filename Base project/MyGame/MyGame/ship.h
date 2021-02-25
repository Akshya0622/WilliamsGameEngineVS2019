#pragma once
#include "Engine/GameEngine.h"

class Ship : public GameObject
{
public:
	Ship(); //creates ship

	void draw(); //functions oveerridden from game object

private:
	sf::Sprite sprite_;
};

typedef std::shared_ptr<Ship> ShipPtr;
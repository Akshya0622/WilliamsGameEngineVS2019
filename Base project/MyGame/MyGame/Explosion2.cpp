#include "Explosion2.h"

Explosion2::Explosion2(sf::Vector2f pos)
	: AnimatedSprite(pos)
{
	AnimatedSprite::setTexture(GAME.getTexture("Resources/ex2.png"));
	SetUpExplosionAnimation();
	playAnimation("explosion2", AnimationMode::OnceForwards);
	boom_.setBuffer(GAME.getSoundBuffer("Resources/boom.wav"));
	boom_.play();
}
void Explosion2::SetUpExplosionAnimation()
{
	std::vector<sf::IntRect> frames;
	frames.push_back(sf::IntRect(0, 0, 50, 100)); // frame 1
	frames.push_back(sf::IntRect(80, 0, 50, 100)); // frame 2
	frames.push_back(sf::IntRect(150, 0, 50, 100)); // frame 3
	frames.push_back(sf::IntRect(227, 0, 50, 100)); // frame 4
	frames.push_back(sf::IntRect(286, 0, 50, 100)); // frame 5
	frames.push_back(sf::IntRect(355, 0, 50, 100)); // frame 6
	frames.push_back(sf::IntRect(420, 0, 50, 100)); // frame 7
	frames.push_back(sf::IntRect(498, 0, 50, 100)); // frame 8
	frames.push_back(sf::IntRect(553, 0, 50, 100)); // frame 9

	addAnimation("explosion2", frames);
}

void Explosion2::update(sf::Time& elapsed)
{
	AnimatedSprite::update(elapsed);
	if (!isPlaying())
	{
		makeDead();
	}
}

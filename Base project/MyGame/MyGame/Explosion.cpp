#include "Explosion.h"

Explosion::Explosion(sf::Vector2f pos)
: AnimatedSprite(pos)
{
	AnimatedSprite::setTexture(GAME.getTexture("Resources/bigExplosion.png"));
	SetUpExplosionAnimation();
	playAnimation("explosion", AnimationMode::OnceForwards);
	boom_.setBuffer(GAME.getSoundBuffer("Resources/boom.wav"));
	boom_.play();
}
void Explosion::SetUpExplosionAnimation()
{
	std::vector<sf::IntRect> frames;
	frames.push_back(sf::IntRect(0, 0, 100, 150)); // frame 1
	frames.push_back(sf::IntRect(70, 0, 100, 150)); // frame 2
	frames.push_back(sf::IntRect(140, 0, 100, 150)); // frame 3
	frames.push_back(sf::IntRect(207, 0, 100, 150)); // frame 4
	frames.push_back(sf::IntRect(266, 0, 100, 150)); // frame 5
	frames.push_back(sf::IntRect(335, 0, 100, 150)); // frame 6
	frames.push_back(sf::IntRect(400, 0, 100, 150)); // frame 7
	frames.push_back(sf::IntRect(478, 0, 100, 150)); // frame 8
	frames.push_back(sf::IntRect(533, 0, 100, 150)); // frame 9
	addAnimation("explosion", frames);
}

void Explosion::update(sf::Time& elapsed)
{
	AnimatedSprite::update(elapsed);
	if (!isPlaying())
	{
		makeDead();
	}
}

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
	
	frames.push_back(sf::IntRect(50, 0, 100, 150)); // frame 2
	frames.push_back(sf::IntRect(150, 0, 100, 150)); // frame 3
	frames.push_back(sf::IntRect(250, 0, 100, 150)); // frame 4
	frames.push_back(sf::IntRect(350, 0, 100, 150)); // frame 5
	frames.push_back(sf::IntRect(450, 0, 100, 150)); // frame 6
	frames.push_back(sf::IntRect(550, 0, 100, 150)); // frame 7
	frames.push_back(sf::IntRect(650, 0, 100, 150)); // frame 8
	frames.push_back(sf::IntRect(800, 0, 100, 150)); // frame 9
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

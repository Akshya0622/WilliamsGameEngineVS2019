#include "GameOverMessage.h"
#include "GameScene.h"
#include <sstream>
GameOverMessage::GameOverMessage(int score)
{
	text_.setFont(GAME.getFont("Resources/AgentOrange.ttf"));
	text_.setPosition(sf::Vector2f(50.0f, 50.0f));
	text_.setCharacterSize(30);
	text_.setFillColor(sf::Color::Red);
	std::stringstream stream;
	stream << "\n\n\n             GAME OVER\n\n           YOUR SCORE: " << score << "\n\n     PRESS ENTER TO CONTINUE"; 
	text_.setString(stream.str());
}
void GameOverMessage::draw()
{
	GAME.getRenderWindow().draw(text_);
}
void GameOverMessage::update(sf::Time& time)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
	{
		GameScenePtr scene = std::make_shared<GameScene>();
		GAME.setScene(scene);
		return;
	}
}
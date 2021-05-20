#include "GameScene.h"
#include "Ship.h"
#include "MeteorSpawner.h"
#include "Explosion.h"
#include "Score.h"
#include "GameOverScene.h"
#include "background.h"
#include "ShootingStarSpawner.h"
#include "Lives.h"


GameScene::GameScene()
{
	
	
	backgroundPtr scenes = std::make_shared<background>();
	addGameObject(scenes);
	MeteorSpawnerPtr meteorSpawner = std::make_shared<MeteorSpawner>();
	addGameObject(meteorSpawner);
	ScorePtr score = std::make_shared<Score>(sf::Vector2f(10.0f, 10.0f));
	addGameObject(score);
	LivesPtr lives = std::make_shared<Lives>(sf::Vector2f(10.0f, 10.0f));
	addGameObject(lives);
	ShipPtr ship = std::make_shared<Ship>();
	addGameObject(ship);
	ShootingStarSpawnerPtr starSpawner = std::make_shared<ShootingStarSpawner>();
	addGameObject(starSpawner);
}

int GameScene::getScore()
{
	return score_;
}
void GameScene::increaseScore()
{
	++score_;
}
int GameScene::getLives()
{
	
		return lives_;
}
void GameScene::decreaseLives()
{
	--lives_;
	if (lives_ == 0)
	{
		GameOverScenePtr gameOverScene = std::make_shared<GameOverScene>(score_);
		GAME.setScene(gameOverScene);
	}
}

void GameScene::increaseLives()
{
	++lives_;

}

#include "GameScene.h"
#include "Ship.h"
#include "MeteorSpawner.h"
#include "Explosion.h"
#include "Score.h"
#include "GameOverScene.h"
#include "background.h"
#include "ShootingStarSpawner.h"


GameScene::GameScene()
{
	
	
	
	MeteorSpawnerPtr meteorSpawner = std::make_shared<MeteorSpawner>();
	addGameObject(meteorSpawner);
	ScorePtr score = std::make_shared<Score>(sf::Vector2f(10.0f, 10.0f));
	addGameObject(score);
	backgroundPtr scenes = std::make_shared<background>();
	addGameObject(scenes);
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
	lives_ += 1;

}

#pragma once

#include "Engine/GameEngine.h"

class GameScene : public Scene {
 public:
  // Creates our Scene.
  GameScene();
  // Gets the current score
  int getScore();
  // Increases the score
  void increaseScore();
  // Get the number of lives
  int getLives();
  // Decrease the number of lives
  void decreaseLives();
  void increaseLives();
 
 
private:
	int score_ = 0;
	int lives_ = 3;

};

typedef std::shared_ptr<GameScene> GameScenePtr;


#pragma once
#include "Player.h"
#include "Enemy.h"
#include "Treasure.h"
#include "Terrain.h"
#include <list>

class GameScene
{
public:
	GameScene();

	void Update();

	void Draw();

private:
	Player* player = nullptr;

};
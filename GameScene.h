#pragma once
#include "Player.h"
#include "Enemy.h"
#include "Enemy1.h"
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

	std::list<Enemy*> enemylist;

	std::list<Treasure*> treasurelist;

	std::list<Terrain*> terrainlist;

};


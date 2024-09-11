#pragma once
#include "Player.h"
#include "Enemy.h"
#include "Enemy1.h"
#include "Treasure.h"
#include "Terrain.h"
#include "Soil.h"
#include <list>
#include "Collision.h"

class GameScene
{
public:
	GameScene();

	void Update();

	void Draw();

	void Delete();

	void Collision();

	void PlayerSoilCollision();

	void DigSoilCollision();

	void PlayerEnemyCollision();

	void PlayerAttackEnemyCollision();

private:
	Player* player = nullptr;

	std::list<Enemy*> enemylist;

	std::list<Treasure*> treasurelist;

	std::list<Terrain*> terrainlist;

};


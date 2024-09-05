#include "GameScene.h"

GameScene::GameScene()
{
	player = new Player(300, 300);
	enemylist.push_back(new Enemy1(400, 400));
}

void GameScene::Update()
{
	player->Update();

	for (auto enemyitr = enemylist.begin(); enemyitr != enemylist.end(); ++enemyitr) {
		(*enemyitr)->Update();
	}
	for (auto treasureitr = treasurelist.begin(); treasureitr != treasurelist.end(); ++treasureitr) {
		(*treasureitr)->Update();
	}
	for (auto terrainitr = terrainlist.begin(); terrainitr != terrainlist.end(); ++terrainitr) {
		(*terrainitr)->Update();
	}
}


void GameScene::Draw()
{
	player->Draw();

	for (auto enemyitr = enemylist.begin(); enemyitr != enemylist.end(); ++enemyitr) {
		(*enemyitr)->Draw();
	}
	for (auto treasureitr = treasurelist.begin(); treasureitr != treasurelist.end(); ++treasureitr) {
		(*treasureitr)->Draw();
	}
	for (auto terrainitr = terrainlist.begin(); terrainitr != terrainlist.end(); ++terrainitr) {
		(*terrainitr)->Draw();
	}
}

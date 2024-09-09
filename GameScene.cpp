#include "GameScene.h"

GameScene::GameScene()
{
	player = new Player(300, 300);
	//enemylist.push_back(new Enemy1(400, 400));


	//l‹÷—\’è
	terrainlist.push_back(new Soil(10, 210, true));
	terrainlist.push_back(new Soil(790, 210, true));
	terrainlist.push_back(new Soil(10, 970, true));
	terrainlist.push_back(new Soil(790, 970, true));
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

	Collision();
	Delete();
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

void GameScene::Delete()
{
	for (auto terrainitr = terrainlist.begin(); terrainitr != terrainlist.end();) {
		if ((*terrainitr)->GetIsDig() == true) {
			terrainitr = terrainlist.erase(terrainitr);
		}
		else
		{
			++terrainitr;
		}
	}
}

void GameScene::Collision()
{
	for (auto terrainitr = terrainlist.begin(); terrainitr != terrainlist.end(); ++terrainitr) {
		if (Collision::SquareToSquare(player->GetDigPointLeftX(), player->GetDigPointUpY(),
			player->GetDigPointRightX(), player->GetDigPointDownY(),
			(*terrainitr)->GetLeftX(), (*terrainitr)->GetUpY(),
			(*terrainitr)->GetRightX(), (*terrainitr)->GetDownY())) {
			//Œ@‚ç‚ê‚é
			(*terrainitr)->Diged();
		}
	}
}

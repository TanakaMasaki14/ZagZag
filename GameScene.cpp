#include "GameScene.h"

GameScene::GameScene()
{
	player = new Player(300, 100);
	//enemylist.push_back(new Enemy1(400, 400));

	for (int i = 0; i < 39; i++) {
		for (int j = 0; j < 41; j++) {
			terrainlist.push_back(new Soil(10 + j * 20, 210 + i * 20, true));
		}
	}

	//Žl‹÷—\’è c39 ‰¡41
	/*terrainlist.push_back(new Soil(10, 210, true));
	terrainlist.push_back(new Soil(790, 210, true));

	terrainlist.push_back(new Soil(10, 970, true));
	terrainlist.push_back(new Soil(790, 970, true));*/
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

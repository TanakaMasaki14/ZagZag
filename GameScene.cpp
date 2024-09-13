#include "GameScene.h"

GameScene::GameScene()
{
	player = new Player(300, 100);
	//enemylist.push_back(new Enemy1(500, 100));

	for (int i = 0; i < 39; i++) {
		for (int j = 0; j < 41; j++) {
			terrainlist.push_back(new Soil((float)10 + (float)j * 20, (float)210 + (float)i * 20, true));
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

	for (auto enemyitr = enemylist.begin(); enemyitr != enemylist.end();) {
		if ((*enemyitr)->GetIsHit() == true) {
			enemyitr = enemylist.erase(enemyitr);
		}
		else {
			++enemyitr;
		}
	}
}

void GameScene::Collision()
{
	PlayerSoilCollision();
	DigSoilCollision();
	PlayerEnemyCollision();
	PlayerAttackEnemyCollision();
}

void GameScene::PlayerSoilCollision()
{
	for (auto terrainitr = terrainlist.begin(); terrainitr != terrainlist.end(); ++terrainitr) {
		if (Collision::SquareToSquare(player->GetPlayerLeftX(), player->GetPlayerUpY(),
			player->GetPlayerRightX(), player->GetPlayerDownY(),
			(*terrainitr)->GetLeftX(), (*terrainitr)->GetUpY(),
			(*terrainitr)->GetRightX(), (*terrainitr)->GetDownY())) {

			if (Collision::LineToSquare((*terrainitr)->GetLeftX(), (*terrainitr)->GetUpY(), (*terrainitr)->GetLeftX(), (*terrainitr)->GetDownY(),
				(*terrainitr)->GetRightX(), (*terrainitr)->GetUpY(), (*terrainitr)->GetRightX(), (*terrainitr)->GetDownY(),
				player->GetPlayerLeftX(), player->GetPlayerDownY(), player->GetPlayerRightX(), player->GetPlayerDownY())) {
				player->SetTrueHitDown();
			}
			if (Collision::LineToSquare((*terrainitr)->GetLeftX(), (*terrainitr)->GetUpY(), (*terrainitr)->GetLeftX(), (*terrainitr)->GetDownY(),
				(*terrainitr)->GetRightX(), (*terrainitr)->GetUpY(), (*terrainitr)->GetRightX(), (*terrainitr)->GetDownY(),
				player->GetPlayerLeftX(), player->GetPlayerDownY(), player->GetPlayerLeftX(), player->GetPlayerUpY())) {
				player->SetTrueHitLeft();
			}
			if (Collision::LineToSquare((*terrainitr)->GetLeftX(), (*terrainitr)->GetUpY(), (*terrainitr)->GetLeftX(), (*terrainitr)->GetDownY(),
				(*terrainitr)->GetRightX(), (*terrainitr)->GetUpY(), (*terrainitr)->GetRightX(), (*terrainitr)->GetDownY(),
				player->GetPlayerRightX(), player->GetPlayerDownY(), player->GetPlayerRightX(), player->GetPlayerUpY())) {
				player->SetTrueHitRight();
			}
			if (Collision::LineToSquare((*terrainitr)->GetLeftX(), (*terrainitr)->GetUpY(), (*terrainitr)->GetLeftX(), (*terrainitr)->GetDownY(),
				(*terrainitr)->GetRightX(), (*terrainitr)->GetUpY(), (*terrainitr)->GetRightX(), (*terrainitr)->GetDownY(),
				player->GetPlayerRightX(), player->GetPlayerUpY(), player->GetPlayerLeftX(), player->GetPlayerUpY())) {
				player->SetTrueHitUp();
			}


			break;
		}
		if (Collision::SquareToSquare(player->GetPlayerLeftX(), player->GetPlayerUpY(),
			player->GetPlayerRightX(), player->GetPlayerDownY(),
			(*terrainitr)->GetLeftX(), (*terrainitr)->GetUpY(),
			(*terrainitr)->GetRightX(), (*terrainitr)->GetDownY()) == false) {

			player->SetFailHitLeft();
			player->SetFailHitRight();
			player->SetFailHitUp();
			player->SetFailHitDown();
		}
	}
}

void GameScene::DigSoilCollision()
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

void GameScene::PlayerEnemyCollision()
{
	for (auto enemyitr = enemylist.begin(); enemyitr != enemylist.end(); ++enemyitr) {
		if (Collision::SquareToSquare(player->GetPlayerLeftX(), player->GetPlayerUpY(), player->GetPlayerRightX(), player->GetPlayerDownY(),
			(*enemyitr)->GetLeftX(), (*enemyitr)->GetUpY(), (*enemyitr)->GetRightX(), (*enemyitr)->GetDownY())) {
			player->Hit();
		}
	}
}

void GameScene::PlayerAttackEnemyCollision()
{
	for (auto enemyitr = enemylist.begin(); enemyitr != enemylist.end(); ++enemyitr) {
		if (Collision::SquareToSquare(player->GetAttackPointLeftX(), player->GetAttackPointUpY(), player->GetAttackPointRightX(), player->GetAttackPointDownY(),
			(*enemyitr)->GetLeftX(), (*enemyitr)->GetUpY(), (*enemyitr)->GetRightX(), (*enemyitr)->GetDownY())) {
			if (player->GetAttackTime() >= 8 && player->GetAttackTime() <= 19) {
				(*enemyitr)->Hit();
			}
		}
	}
}

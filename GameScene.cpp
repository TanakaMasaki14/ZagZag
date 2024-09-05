#include "GameScene.h"

GameScene::GameScene()
{
	player = new Player(300, 300);
}

void GameScene::Update()
{


}


void GameScene::Draw()
{
	player->Draw();
}
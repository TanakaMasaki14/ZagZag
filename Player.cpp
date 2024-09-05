#include "Player.h"
#include <iostream>



Player::Player(float x, float y)
{
	this->x = x;
	this->y = y;

	int* sizeX = 0;
	int* sizeY = 0;
	texture = LoadGraph("Resources/test.png");
	GetGraphSize(texture, sizeX, sizeY);

	if (sizeX != nullptr) {
		this->sizeX = static_cast<float>(*sizeX);
	}
	else
	{
		// エラーハンドリングコードをここに追加
		std::cerr << "Error: sizeX is a NULL pointer." << std::endl;
	}

	if (sizeY != nullptr) {
		this->sizeY = static_cast<float>(*sizeY);
	}
	else
	{
		// エラーハンドリングコードをここに追加
		std::cerr << "Error: sizeY is a NULL pointer." << std::endl;
	}
	this->sizeX = this->sizeX / 2;
	this->sizeY = this->sizeY / 2;
}

void Player::Update()
{
}

void Player::Draw()
{
	DrawGraph(x - sizeX, y - sizeY, texture, true);
}
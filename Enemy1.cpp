#include "Enemy1.h"
#include <iostream>



Enemy1::Enemy1(float x, float y)
{
	this->x = x;
	this->y = y;

	int* sizeX = 0;
	int* sizeY = 0;
	texture = LoadGraph("");
	GetGraphSize(texture, sizeX, sizeY);

	if (sizeX != nullptr) {
		this->sizeX = static_cast<float>(*sizeX);
	}
	else {
		// エラーハンドリングコードをここに追加
		std::cerr << "Error: sizeX is a NULL pointer." << std::endl;
	}
	if (sizeY != nullptr) {
		this->sizeY = static_cast<float>(*sizeY);
	}
	else {
		// エラーハンドリングコードをここに追加
		std::cerr << "Error: sizeY is a NULL pointer." << std::endl;
	}
	this->sizeX = this->sizeX / 2;
	this->sizeY = this->sizeY / 2;
}

void Enemy1::Update()
{
}

void Enemy1::Draw()
{
	//DrawBox(x - sizeX, y - sizeY, x + sizeX, y + sizeY, GetColor(255, 255, 255), true);
	DrawGraph((int)x - (int)sizeX, (int)y - (int)sizeY, texture, true);
}

#include "Enemy1.h"



Enemy1::Enemy1(float x, float y)
{
	x = this->x;
	x = this->y;

	int* sizeX;
	int* sizeY;
	texture = LoadGraph("");
	GetGraphSize(texture, sizeX, sizeY);

	this->sizeX = static_cast<float>(*sizeX);
	this->sizeY = static_cast<float>(*sizeY);
}

void Enemy1::Update()
{
}

void Enemy1::Draw()
{
	DrawBox(x - sizeX, y - sizeY, x + sizeX, y + sizeY, GetColor(255, 255, 255), true);
}

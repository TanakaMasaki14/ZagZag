#include "Treasure1.h"

Treasure1::Treasure1(float x, float y)
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

void Treasure1::Update()
{
}

void Treasure1::Draw()
{
	DrawBox(x - sizeX, y - sizeY, x + sizeX, y + sizeY, GetColor(255, 255, 0), true);
}
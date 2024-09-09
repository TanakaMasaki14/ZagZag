#include "Treasure.h"

Treasure::Treasure(float x, float y)
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

void Treasure::Update()
{
}

void Treasure::Draw()
{
	DrawBox(x - sizeX, y - sizeY, x + sizeX, y + sizeY, GetColor(255, 255, 0), true);
}

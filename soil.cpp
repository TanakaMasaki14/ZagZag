#include "Soil.h"
#include <iostream>




Soil::Soil(float x, float y, bool canDig)
{
	this->x = x;
	this->y = y;
	this->canDig = canDig;
	//this->intressure = intressure;

	int* sizeX = new int(0);
	int* sizeY = new int(0);

	digtexture = LoadGraph("Resource/soil.png");
	nodigtexture = LoadGraph("Resource/testsoil.png");

	GetGraphSize(digtexture, sizeX, sizeY);
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

void Soil::Update()
{
}

void Soil::Draw()
{
	if (canDig == true) {
		DrawGraph((int)x - (int)sizeX, (int)y - (int)sizeY, digtexture, true);
	}
	if (canDig == false) {
		DrawGraph((int)x - (int)sizeX, (int)y - (int)sizeY, nodigtexture, true);
	}
}

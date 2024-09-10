#pragma once
#include <DxLib.h>

class Enemy
{
public:
	Enemy();

	virtual void Update();

	virtual void Draw();

protected:
	float x = 0;
	float y = 0;

	float sizeX = 0;
	float sizeY = 0;
};


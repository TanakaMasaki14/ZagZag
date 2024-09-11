#pragma once
#include <DxLib.h>

class Enemy
{
public:
	Enemy();

	virtual void Update();

	virtual void Draw();

	//À•Wæ“¾
	float GetLeftX() {
		return x - sizeX;
	}
	float GetRightX() {
		return x + sizeX;
	}

	float GetUpY() {
		return y - sizeY;
	}
	float GetDownY() {
		return y + sizeY;
	}

protected:
	float x = 0;
	float y = 0;

	float sizeX = 0;
	float sizeY = 0;
};


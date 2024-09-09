#pragma once
#include <DxLib.h>

class Rope
{
public:
	Rope();

	void Update();

	void Draw();

private:
	float x;
	float y;

	float sizeX;
	float sizeY;

	int texture;
};


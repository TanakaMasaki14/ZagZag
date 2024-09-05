#pragma once
#include "Treasure.h"

class Treasure1 : public Treasure
{
public:
	Treasure1(float x, float y);

	void Update() override;

	void Draw() override;

private:
	int texture;

	int score;

	float sizeX;
	float sizeY;
};
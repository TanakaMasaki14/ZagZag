#pragma once
#include "Enemy.h"

class Enemy1 : public Enemy
{
public:
	Enemy1(float x, float y);

	void Update() override;

	void Draw() override;

private:
	int texture;

	int hp;

	float sizeX;
	float sizeY;
};


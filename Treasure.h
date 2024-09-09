#pragma once

class Treasure
{
public:
	Treasure(float x, float y);

	void Update();

	void Draw();

protected:
	float x;
	float y;

	int texture;

	int score;

	float sizeX;
	float sizeY;

};
#pragma once

class Player
{
public:
	Player(float x, float y);

	void Update();

	void Draw();

private:
	float x;
	float y;

	float sizeX;
	float sizeY;

};


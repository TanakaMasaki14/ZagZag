#pragma once
#include <DxLib.h>

class Player
{
public:
	Player(float x, float y);

	void Update();

	void Draw();

	void Move();

	void Dig();

	///座標取得
	//x左
	float GetDigPointLeftX() {
		return digpointX - digSizeX;
	}
	//x右
	float GetDigPointRightX() {
		return digpointX + digSizeX;
	}

	float GetDigPointUpY() {
		return digpointY - digSizeY;
	}
	float GetDigPointDownY() {
		return digpointY + digSizeY;
	}

private:
	float x = 0;
	float y = 0;

	float sizeX = 0;
	float sizeY = 0;

	float movespeedX = 0;
	float movespeedY = 0;

	int texture;

	int viewpoint = 0; //0:右 1:下 2:左 3:上

	bool dig = false;

	float digpointX = 0;
	float digpointY = 0;

	float digSizeX = 0;
	float digSizeY = 0;

	int digtime = 10;

	bool attack = false;

	char key[256];
	char oldkey[256];

};


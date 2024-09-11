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

	void HitSoil();

	void Attack();

	//当たり判定のセット
	void SetFailHitLeft() {
		hitLeft = false;
	}
	void SetTrueHitLeft() {
		hitLeft = true;
	}
	void SetFailHitRight() {
		hitRight = false;
	}
	void SetTrueHitRight() {
		hitRight = true;
	}
	void SetFailHitUp() {
		hitUp = false;
	}
	void SetTrueHitUp() {
		hitUp = true;
	}
	void SetFailHitDown() {
		hitDown = false;
	}
	void SetTrueHitDown() {
		hitDown = true;
	}





	///座標取得
	//プレイヤー
	//左
	float GetPlayerLeftX() {
		return x - sizeX;
	}
	//右
	float GetPlayerRightX() {
		return x + sizeX;
	}
	//上
	float GetPlayerUpY() {
		return y - sizeY;
	}
	//下
	float GetPlayerDownY() {
		return y + sizeY;
	}

	//掘るエリア
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

	float sx = 0;
	float sy = 0;

	float sizeX = 0;
	float sizeY = 0;

	bool hitLeft = false;
	bool hitRight = false;
	bool hitUp = false;
	bool hitDown = false;

	bool moveLeft = false;
	bool moveRight = false;
	bool moveUp = false;
	bool moveDown = false;

	int righttexture;
	int lefttexture;
	int uptexture;
	int downtexture;
	int lefttexturepickaxe[10];
	int righttexturepickaxe[10];
	int uptexturepickaxe[10];
	int downtexturepickaxe[10];


	int viewpoint = 0; //0:右 1:下 2:左 3:上

	bool dig = false;

	float digpointX = 0;
	float digpointY = 0;

	float digSizeX = 0; //これの2倍が横の大きさ
	float digSizeY = 0; //これの2倍が縦の大きさ

	int digtime = 0;

	bool attack = false;

	float attackPointX;
	float attackPointY;

	float attackSizeX = 0;
	float attackSizeY = 0;

	int attacktime = 0;

	char key[256];
	char oldkey[256];

};
#include "Player.h"
#include <iostream>



Player::Player(float x, float y)
{
	this->x = x;
	this->y = y;

	int* sizeX = new int(0);
	int* sizeY = new int(0);
	righttexture = LoadGraph("Resources/rightplayer.png");
	downtexture = LoadGraph("Resources/downplayer.png");
	lefttexture = LoadGraph("Resources/leftplayer.png");
	uptexture = LoadGraph("Resources/upplayer.png");

	righttexturepickaxe[0] = LoadGraph("Resources/pickaxe/Right/pickaxe0.png");
	righttexturepickaxe[1] = LoadGraph("Resources/pickaxe/Right/pickaxe1.png");
	righttexturepickaxe[2] = LoadGraph("Resources/pickaxe/Right/pickaxe2.png");
	righttexturepickaxe[3] = LoadGraph("Resources/pickaxe/Right/pickaxe3.png");
	righttexturepickaxe[4] = LoadGraph("Resources/pickaxe/Right/pickaxe4.png");
	righttexturepickaxe[5] = LoadGraph("Resources/pickaxe/Right/pickaxe5.png");

	lefttexturepickaxe[0] = LoadGraph("Resources/pickaxe/Left/pickaxe0.png");
	lefttexturepickaxe[1] = LoadGraph("Resources/pickaxe/Left/pickaxe1.png");
	lefttexturepickaxe[2] = LoadGraph("Resources/pickaxe/Left/pickaxe2.png");
	lefttexturepickaxe[3] = LoadGraph("Resources/pickaxe/Left/pickaxe3.png");
	lefttexturepickaxe[4] = LoadGraph("Resources/pickaxe/Left/pickaxe4.png");
	lefttexturepickaxe[5] = LoadGraph("Resources/pickaxe/Left/pickaxe5.png");

	uptexturepickaxe[0] = LoadGraph("Resources/pickaxe/Up/pickaxe0.png");
	uptexturepickaxe[1] = LoadGraph("Resources/pickaxe/Up/pickaxe1.png");
	uptexturepickaxe[2] = LoadGraph("Resources/pickaxe/Up/pickaxe2.png");
	uptexturepickaxe[3] = LoadGraph("Resources/pickaxe/Up/pickaxe3.png");
	uptexturepickaxe[4] = LoadGraph("Resources/pickaxe/Up/pickaxe4.png");
	uptexturepickaxe[5] = LoadGraph("Resources/pickaxe/Up/pickaxe5.png");

	downtexturepickaxe[0] = LoadGraph("Resources/pickaxe/Down/pickaxe0.png");
	downtexturepickaxe[1] = LoadGraph("Resources/pickaxe/Down/pickaxe1.png");
	downtexturepickaxe[2] = LoadGraph("Resources/pickaxe/Down/pickaxe2.png");
	downtexturepickaxe[3] = LoadGraph("Resources/pickaxe/Down/pickaxe3.png");
	downtexturepickaxe[4] = LoadGraph("Resources/pickaxe/Down/pickaxe4.png");
	downtexturepickaxe[5] = LoadGraph("Resources/pickaxe/Down/pickaxe5.png");


	GetGraphSize(righttexture, sizeX, sizeY);

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

void Player::Update()
{
	GetHitKeyStateAll(key);


	Move();
	Dig();
	HitSoil();

	for (int i = 0; i < 256; i++) {
		oldkey[i] = key[i];
	}
	sx = x;
	sy = y;
}

void Player::Draw()
{
	DrawFormatString(0, 0, GetColor(255, 255, 255), "L%d", hitLeft);
	DrawFormatString(0, 20, GetColor(255, 255, 255), "R%d", hitRight);
	DrawFormatString(0, 40, GetColor(255, 255, 255), "U%d", hitUp);
	DrawFormatString(0, 60, GetColor(255, 255, 255), "D%d", hitDown);
	DrawFormatString(0, 80, GetColor(255, 255, 255), "L%d", moveLeft);
	DrawFormatString(0, 100, GetColor(255, 255, 255), "R%d", moveRight);
	DrawFormatString(0, 120, GetColor(255, 255, 255), "U%d", moveUp);
	DrawFormatString(0, 140, GetColor(255, 255, 255), "D%d", moveDown);
	DrawFormatString(0, 160, GetColor(255, 255, 255), "P%f", this->y);
	DrawFormatString(0, 180, GetColor(255, 255, 255), "A%d", viewpoint);

	if (viewpoint == 0) {
		DrawGraph((int)x - (int)sizeX, (int)y - (int)sizeY, righttexture, true);
	}
	if (viewpoint == 1) {
		DrawGraph((int)x - (int)sizeX, (int)y - (int)sizeY, downtexture, true);
	}
	if (viewpoint == 2) {
		DrawGraph((int)x - (int)sizeX, (int)y - (int)sizeY, lefttexture, true);
	}
	if (viewpoint == 3) {
		DrawGraph((int)x - (int)sizeX, (int)y - (int)sizeY, uptexture, true);
	}


	if (dig == true) {
		//DrawBox((int)digpointX - digSizeX, (int)digpointY - digSizeY, (int)digpointX + digSizeX, (int)digpointY + digSizeY, GetColor(255, 255, 255), true);
		if (viewpoint == 0) {
			DrawGraph(digpointX - digSizeX, digpointY - digSizeY, righttexturepickaxe[digtime], true);
		}
		if (viewpoint == 1) {
			DrawGraph(digpointX - digSizeX, digpointY - digSizeY, downtexturepickaxe[digtime], true);
		}
		if (viewpoint == 2) {
			DrawGraph(digpointX - digSizeX, digpointY - digSizeY, lefttexturepickaxe[digtime], true);
		}
		if (viewpoint == 3) {
			DrawGraph(digpointX - digSizeX, digpointY - digSizeY, uptexturepickaxe[digtime], true);
		}
	}
}

void Player::Move()
{
	if (dig == false && attack == false) {
		//上
		if (key[KEY_INPUT_W] == 1) {
			if (hitUp == false) {
				y -= 4.0f;
				viewpoint = 3;
			}
			moveUp = true;
		}
		else {
			moveUp = false;
		}
		//下
		if (key[KEY_INPUT_S] == 1) {
			if (hitDown == false) {
				y += 4.0f;
				viewpoint = 1;
			}
			moveDown = true;
		}
		else {
			moveDown = false;
		}
		//左
		if (key[KEY_INPUT_A] == 1) {
			if (hitLeft == false) {
				x -= 4.0f;
				viewpoint = 2;
			}
			moveLeft = true;
		}
		else {
			moveLeft = false;
		}
		//右
		if (key[KEY_INPUT_D] == 1) {
			if (hitRight == false) {
				x += 4.0f;
				viewpoint = 0;
				moveRight = true;
			}
		}
		else {
			moveRight = false;
		}
	}
}

void Player::Dig()
{
	if (key[KEY_INPUT_SPACE] == 1 && oldkey[KEY_INPUT_SPACE] == 0 && dig == false && attack == false) {
		//右
		if (viewpoint == 0) {
			digpointX = x + 25;
			digpointY = y;
			digSizeX = 10;
			digSizeY = 20;
		}
		//下
		if (viewpoint == 1) {
			digpointX = x;
			digpointY = y + 25;
			digSizeX = 20;
			digSizeY = 10;
		}
		//左
		if (viewpoint == 2) {
			digpointX = x - 25;
			digpointY = y;
			digSizeX = 10;
			digSizeY = 20;
		}
		//上
		if (viewpoint == 3) {
			digpointX = x;
			digpointY = y - 25;
			digSizeX = 20;
			digSizeY = 10;
		}
		dig = true;
	}
	if (dig == true) {
		digtime++;
		if (digtime >= 12) {
			digtime = 0;
			digpointX = 3000;
			digpointY = 3000;
			dig = false;
		}
	}
}

void Player::HitSoil()
{
	if (hitLeft) {
		if (moveLeft) {
			x = sx;
		}
	}
	if (hitRight) {
		if (moveRight) {
			x = sx;
		}
	}
	if (hitUp) {
		if (moveUp) {
			y = sy;
		}
	}
	if (hitDown) {
		if (moveDown) {
			y = sy;
		}
	}
}

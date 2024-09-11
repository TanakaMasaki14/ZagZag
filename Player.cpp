#include "Player.h"
#include <iostream>



Player::Player(float x, float y) : x(x), y(y), sizeX(0), sizeY(0) // 初期化リストを使用して初期化
{
	//this->x = x;
	//this->y = y;

	int* sizeX = new int(0);
	int* sizeY = new int(0);
	texture = LoadGraph("Resource/Icon.png");
	GetGraphSize(texture, sizeX, sizeY);

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

void Player::Update(Terrain& terrain)
{
	GetHitKeyStateAll(key);

	Move();
	Dig(terrain);

	for (int i = 0; i < 256; i++) {
		oldkey[i] = key[i];
	}
}

void Player::Draw()
{
	//DrawFormatString(0, 0, GetColor(255, 255, 255), "%f", sizeY);
	DrawGraph((int)x - (int)sizeX, (int)y - (int)sizeY, texture, true);
	if (dig == true) {
		DrawBox(digpointX - digSizeX, digpointY - digSizeY, digpointX + digSizeX, digpointY + digSizeY, GetColor(255, 255, 255), true);
	}
}

void Player::Move()
{
	if (dig == false && attack == false) {
		if (key[KEY_INPUT_W] == 1) {
			y -= 4.0f;
			viewpoint = 3;
		}
		if (key[KEY_INPUT_S] == 1) {
			y += 4.0f;
			viewpoint = 1;
		}
		if (key[KEY_INPUT_A] == 1) {
			x -= 4.0f;
			viewpoint = 2;
		}
		if (key[KEY_INPUT_D] == 1) {
			x += 4.0f;
			viewpoint = 0;
		}
	}
}

void Player::Dig(Terrain& terrain)
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
		// 掘った場所にあるマップチップを削除
		terrain.Remove(digpointX, digpointY);
		dig = true;
	}
	if (dig == true) {
		digtime--;
		if (digtime <= 0) {
			digtime = 10;
			digpointX = 3000;
			digpointY = 3000;
			dig = false;
		}
	}
}

int Player::GetX() const {
	return x;
}

int Player::GetY() const {
	return y;
}
#include "Player.h"
#include <iostream>



Player::Player(float x, float y)
{
	this->x = x;
	this->y = y;

	int* sizeX = new int(0);
	int* sizeY = new int(0);
	righttexture = LoadGraph("Resource/rightplayer.png");
	downtexture = LoadGraph("Resource/downplayer.png");
	lefttexture = LoadGraph("Resource/leftplayer.png");
	uptexture = LoadGraph("Resource/upplayer.png");

	{
		righttextureweapon[0] = LoadGraph("Resource/weapon/Right/weapon0.png");
		righttextureweapon[1] = LoadGraph("Resource/weapon/Right/weapon1.png");
		righttextureweapon[2] = LoadGraph("Resource/weapon/Right/weapon2.png");
		righttextureweapon[3] = LoadGraph("Resource/weapon/Right/weapon3.png");
		righttextureweapon[4] = LoadGraph("Resource/weapon/Right/weapon4.png");
		righttextureweapon[5] = LoadGraph("Resource/weapon/Right/weapon5.png");
		righttextureweapon[6] = LoadGraph("Resource/weapon/Right/weapon6.png");
		righttextureweapon[7] = LoadGraph("Resource/weapon/Right/weapon7.png");
		righttextureweapon[8] = LoadGraph("Resource/weapon/Right/weapon8.png");
		righttextureweapon[9] = LoadGraph("Resource/weapon/Right/weapon9.png");
		righttextureweapon[10] = LoadGraph("Resource/weapon/Right/weapon10.png");
		righttextureweapon[11] = LoadGraph("Resource/weapon/Right/weapon11.png");
		righttextureweapon[12] = LoadGraph("Resource/weapon/Right/weapon12.png");
		righttextureweapon[13] = LoadGraph("Resource/weapon/Right/weapon13.png");
		righttextureweapon[14] = LoadGraph("Resource/weapon/Right/weapon14.png");
		righttextureweapon[15] = LoadGraph("Resource/weapon/Right/weapon15.png");
		righttextureweapon[16] = LoadGraph("Resource/weapon/Right/weapon16.png");
		righttextureweapon[17] = LoadGraph("Resource/weapon/Right/weapon17.png");
		righttextureweapon[18] = LoadGraph("Resource/weapon/Right/weapon18.png");
		righttextureweapon[19] = LoadGraph("Resource/weapon/Right/weapon19.png");


		lefttextureweapon[0] = LoadGraph("Resource/weapon/Left/weapon0.png");
		lefttextureweapon[1] = LoadGraph("Resource/weapon/Left/weapon1.png");
		lefttextureweapon[2] = LoadGraph("Resource/weapon/Left/weapon2.png");
		lefttextureweapon[3] = LoadGraph("Resource/weapon/Left/weapon3.png");
		lefttextureweapon[4] = LoadGraph("Resource/weapon/Left/weapon4.png");
		lefttextureweapon[5] = LoadGraph("Resource/weapon/Left/weapon5.png");
		lefttextureweapon[6] = LoadGraph("Resource/weapon/Left/weapon6.png");
		lefttextureweapon[7] = LoadGraph("Resource/weapon/Left/weapon7.png");
		lefttextureweapon[8] = LoadGraph("Resource/weapon/Left/weapon8.png");
		lefttextureweapon[9] = LoadGraph("Resource/weapon/Left/weapon9.png");
		lefttextureweapon[10] = LoadGraph("Resource/weapon/Left/weapon10.png");
		lefttextureweapon[11] = LoadGraph("Resource/weapon/Left/weapon11.png");
		lefttextureweapon[12] = LoadGraph("Resource/weapon/Left/weapon12.png");
		lefttextureweapon[13] = LoadGraph("Resource/weapon/Left/weapon13.png");
		lefttextureweapon[14] = LoadGraph("Resource/weapon/Left/weapon14.png");
		lefttextureweapon[15] = LoadGraph("Resource/weapon/Left/weapon15.png");
		lefttextureweapon[16] = LoadGraph("Resource/weapon/Left/weapon16.png");
		lefttextureweapon[17] = LoadGraph("Resource/weapon/Left/weapon17.png");
		lefttextureweapon[18] = LoadGraph("Resource/weapon/Left/weapon18.png");
		lefttextureweapon[19] = LoadGraph("Resource/weapon/Left/weapon19.png");


		uptextureweapon[0] = LoadGraph("Resource/weapon/Up/weapon0.png");
		uptextureweapon[1] = LoadGraph("Resource/weapon/Up/weapon1.png");
		uptextureweapon[2] = LoadGraph("Resource/weapon/Up/weapon2.png");
		uptextureweapon[3] = LoadGraph("Resource/weapon/Up/weapon3.png");
		uptextureweapon[4] = LoadGraph("Resource/weapon/Up/weapon4.png");
		uptextureweapon[5] = LoadGraph("Resource/weapon/Up/weapon5.png");
		uptextureweapon[6] = LoadGraph("Resource/weapon/Up/weapon6.png");
		uptextureweapon[7] = LoadGraph("Resource/weapon/Up/weapon7.png");
		uptextureweapon[8] = LoadGraph("Resource/weapon/Up/weapon8.png");
		uptextureweapon[9] = LoadGraph("Resource/weapon/Up/weapon9.png");
		uptextureweapon[10] = LoadGraph("Resource/weapon/Up/weapon10.png");
		uptextureweapon[11] = LoadGraph("Resource/weapon/Up/weapon11.png");
		uptextureweapon[12] = LoadGraph("Resource/weapon/Up/weapon12.png");
		uptextureweapon[13] = LoadGraph("Resource/weapon/Up/weapon13.png");
		uptextureweapon[14] = LoadGraph("Resource/weapon/Up/weapon14.png");
		uptextureweapon[15] = LoadGraph("Resource/weapon/Up/weapon15.png");
		uptextureweapon[16] = LoadGraph("Resource/weapon/Up/weapon16.png");
		uptextureweapon[17] = LoadGraph("Resource/weapon/Up/weapon17.png");
		uptextureweapon[18] = LoadGraph("Resource/weapon/Up/weapon18.png");
		uptextureweapon[19] = LoadGraph("Resource/weapon/Up/weapon19.png");

		downtextureweapon[0] = LoadGraph("Resource/weapon/Down/weapon0.png");
		downtextureweapon[1] = LoadGraph("Resource/weapon/Down/weapon1.png");
		downtextureweapon[2] = LoadGraph("Resource/weapon/Down/weapon2.png");
		downtextureweapon[3] = LoadGraph("Resource/weapon/Down/weapon3.png");
		downtextureweapon[4] = LoadGraph("Resource/weapon/Down/weapon4.png");
		downtextureweapon[5] = LoadGraph("Resource/weapon/Down/weapon5.png");
		downtextureweapon[6] = LoadGraph("Resource/weapon/Down/weapon6.png");
		downtextureweapon[7] = LoadGraph("Resource/weapon/Down/weapon7.png");
		downtextureweapon[8] = LoadGraph("Resource/weapon/Down/weapon8.png");
		downtextureweapon[9] = LoadGraph("Resource/weapon/Down/weapon9.png");
		downtextureweapon[10] = LoadGraph("Resource/weapon/Down/weapon10.png");
		downtextureweapon[11] = LoadGraph("Resource/weapon/Down/weapon11.png");
		downtextureweapon[12] = LoadGraph("Resource/weapon/Down/weapon12.png");
		downtextureweapon[13] = LoadGraph("Resource/weapon/Down/weapon13.png");
		downtextureweapon[14] = LoadGraph("Resource/weapon/Down/weapon14.png");
		downtextureweapon[15] = LoadGraph("Resource/weapon/Down/weapon15.png");
		downtextureweapon[16] = LoadGraph("Resource/weapon/Down/weapon16.png");
		downtextureweapon[17] = LoadGraph("Resource/weapon/Down/weapon17.png");
		downtextureweapon[18] = LoadGraph("Resource/weapon/Down/weapon18.png");
		downtextureweapon[19] = LoadGraph("Resource/weapon/Down/weapon19.png");
	}

	{
		righttexturepickaxe[0] = LoadGraph("Resource/pickaxe/Right/pickaxe0.png");
		righttexturepickaxe[1] = LoadGraph("Resource/pickaxe/Right/pickaxe1.png");
		righttexturepickaxe[2] = LoadGraph("Resource/pickaxe/Right/pickaxe2.png");
		righttexturepickaxe[3] = LoadGraph("Resource/pickaxe/Right/pickaxe3.png");
		righttexturepickaxe[4] = LoadGraph("Resource/pickaxe/Right/pickaxe4.png");
		righttexturepickaxe[5] = LoadGraph("Resource/pickaxe/Right/pickaxe5.png");
		righttexturepickaxe[6] = LoadGraph("Resource/pickaxe/Right/pickaxe6.png");
		righttexturepickaxe[7] = LoadGraph("Resource/pickaxe/Right/pickaxe7.png");
		righttexturepickaxe[8] = LoadGraph("Resource/pickaxe/Right/pickaxe8.png");
		righttexturepickaxe[9] = LoadGraph("Resource/pickaxe/Right/pickaxe9.png");


		lefttexturepickaxe[0] = LoadGraph("Resource/pickaxe/Left/pickaxe0.png");
		lefttexturepickaxe[1] = LoadGraph("Resource/pickaxe/Left/pickaxe1.png");
		lefttexturepickaxe[2] = LoadGraph("Resource/pickaxe/Left/pickaxe2.png");
		lefttexturepickaxe[3] = LoadGraph("Resource/pickaxe/Left/pickaxe3.png");
		lefttexturepickaxe[4] = LoadGraph("Resource/pickaxe/Left/pickaxe4.png");
		lefttexturepickaxe[5] = LoadGraph("Resource/pickaxe/Left/pickaxe5.png");
		lefttexturepickaxe[6] = LoadGraph("Resource/pickaxe/Left/pickaxe6.png");
		lefttexturepickaxe[7] = LoadGraph("Resource/pickaxe/Left/pickaxe7.png");
		lefttexturepickaxe[8] = LoadGraph("Resource/pickaxe/Left/pickaxe8.png");
		lefttexturepickaxe[9] = LoadGraph("Resource/pickaxe/Left/pickaxe9.png");

		uptexturepickaxe[0] = LoadGraph("Resource/pickaxe/Up/pickaxe0.png");
		uptexturepickaxe[1] = LoadGraph("Resource/pickaxe/Up/pickaxe1.png");
		uptexturepickaxe[2] = LoadGraph("Resource/pickaxe/Up/pickaxe2.png");
		uptexturepickaxe[3] = LoadGraph("Resource/pickaxe/Up/pickaxe3.png");
		uptexturepickaxe[4] = LoadGraph("Resource/pickaxe/Up/pickaxe4.png");
		uptexturepickaxe[5] = LoadGraph("Resource/pickaxe/Up/pickaxe5.png");
		uptexturepickaxe[6] = LoadGraph("Resource/pickaxe/Up/pickaxe6.png");
		uptexturepickaxe[7] = LoadGraph("Resource/pickaxe/Up/pickaxe7.png");
		uptexturepickaxe[8] = LoadGraph("Resource/pickaxe/Up/pickaxe8.png");
		uptexturepickaxe[9] = LoadGraph("Resource/pickaxe/Up/pickaxe9.png");

		downtexturepickaxe[0] = LoadGraph("Resource/pickaxe/Down/pickaxe0.png");
		downtexturepickaxe[1] = LoadGraph("Resource/pickaxe/Down/pickaxe1.png");
		downtexturepickaxe[2] = LoadGraph("Resource/pickaxe/Down/pickaxe2.png");
		downtexturepickaxe[3] = LoadGraph("Resource/pickaxe/Down/pickaxe3.png");
		downtexturepickaxe[4] = LoadGraph("Resource/pickaxe/Down/pickaxe4.png");
		downtexturepickaxe[5] = LoadGraph("Resource/pickaxe/Down/pickaxe5.png");
		downtexturepickaxe[6] = LoadGraph("Resource/pickaxe/Down/pickaxe6.png");
		downtexturepickaxe[7] = LoadGraph("Resource/pickaxe/Down/pickaxe7.png");
		downtexturepickaxe[8] = LoadGraph("Resource/pickaxe/Down/pickaxe8.png");
		downtexturepickaxe[9] = LoadGraph("Resource/pickaxe/Down/pickaxe9.png");
	}

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
	Attack();
	HitSoil();
	HitProcess();

	for (int i = 0; i < 256; i++) {
		oldkey[i] = key[i];
	}
	sx = x;
	sy = y;
}

void Player::Draw()
{
	/*DrawFormatString(0, 0, GetColor(255, 255, 255), "L%d", hitLeft);
	DrawFormatString(0, 20, GetColor(255, 255, 255), "R%d", hitRight);
	DrawFormatString(0, 40, GetColor(255, 255, 255), "U%d", hitUp);
	DrawFormatString(0, 60, GetColor(255, 255, 255), "D%d", hitDown);
	DrawFormatString(0, 80, GetColor(255, 255, 255), "L%d", moveLeft);
	DrawFormatString(0, 100, GetColor(255, 255, 255), "R%d", moveRight);
	DrawFormatString(0, 120, GetColor(255, 255, 255), "U%d", moveUp);
	DrawFormatString(0, 140, GetColor(255, 255, 255), "D%d", moveDown);
	DrawFormatString(0, 160, GetColor(255, 255, 255), "P%f", this->y);
	DrawFormatString(0, 180, GetColor(255, 255, 255), "A%d", viewpoint);*/

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
	if (attack == true) {
		if (viewpoint == 0) {
			DrawGraph(attackPointX - attackSizeX, attackPointY - attackSizeY, righttextureweapon[attacktime], true);
		}
		if (viewpoint == 1) {
			DrawGraph(attackPointX - attackSizeX, attackPointY - attackSizeY, downtextureweapon[attacktime], true);
		}
		if (viewpoint == 2) {
			DrawGraph(attackPointX - attackSizeX, attackPointY - attackSizeY, lefttextureweapon[attacktime], true);
		}
		if (viewpoint == 3) {
			DrawGraph(attackPointX - attackSizeX, attackPointY - attackSizeY, uptextureweapon[attacktime], true);
		}
		//DrawBox((int)attackPointX - attackSizeX, (int)attackPointY - attackSizeY, (int)attackPointX + attackSizeX, (int)attackPointY + attackSizeY, GetColor(255, 255, 255), true);

	}
}

void Player::Move()
{
	if (dig == false && attack == false) {
		//上
		if (key[KEY_INPUT_W] == 1) {
			if (y >= 15) {
				if (hitUp == false) {
					y -= 4.0f;
					viewpoint = 3;
				}
				moveUp = true;
			}
		}
		else {
			moveUp = false;
		}
		//下
		if (key[KEY_INPUT_S] == 1) {
			if (y <= 965) {
				if (hitDown == false) {
					y += 4.0f;
					viewpoint = 1;
				}
				moveDown = true;
			}
		}
		else {
			moveDown = false;
		}
		//左
		if (key[KEY_INPUT_A] == 1) {
			if (x >= 15) {
				if (hitLeft == false) {
					x -= 4.0f;
					viewpoint = 2;
				}
				moveLeft = true;
			}
		}
		else {
			moveLeft = false;
		}
		//右
		if (key[KEY_INPUT_D] == 1) {
			if (x <= 785) {
				if (hitRight == false) {
					x += 4.0f;
					viewpoint = 0;
					moveRight = true;
				}
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
		if (digtime >= 10) {
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

void Player::Attack()
{
	if (key[KEY_INPUT_RETURN] == 1 && oldkey[KEY_INPUT_RETURN] == 0 && dig == false && attack == false) {
		attack = true;
		if (viewpoint == 0) {
			attackSizeX = 20;
			attackSizeY = 10;
			attackPointX = x + 35;
			attackPointY = y;

		}
		if (viewpoint == 1) {
			attackSizeX = 10;
			attackSizeY = 20;
			attackPointX = x;
			attackPointY = y + 35;
		}
		if (viewpoint == 2) {
			attackSizeX = 20;
			attackSizeY = 10;
			attackPointX = x - 35;
			attackPointY = y;
		}
		if (viewpoint == 3) {
			attackSizeX = 10;
			attackSizeY = 20;
			attackPointX = x;
			attackPointY = y - 35;
		}
	}
	if (attack == true) {
		attacktime++;
		if (attacktime >= 20) {
			attacktime = 0;
			attackPointX = 3000;
			attackPointY = 3000;
			attack = false;
		}
	}
}

void Player::HitProcess()
{
	if (hit == true) {
		invincibletime--;
		if (invincibletime <= 0) {
			invincibletime = 90;
			hit = false;
		}
	}
}

int Player::GetX() const {
	return x;
}

int Player::GetY() const {
	return y;
}
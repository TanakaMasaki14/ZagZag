#pragma once

class Terrain
{
public:
	Terrain();

	virtual void Update();

	virtual void Draw();

	//���W�擾
	float GetLeftX() {
		return x - sizeX;
	}
	float GetRightX() {
		return x + sizeX;
	}

	float GetUpY() {
		return y - sizeY;
	}
	float GetDownY() {
		return y + sizeY;
	}

	void Diged() {
		getdig = true;
	}

	bool GetIsDig() {
		return getdig;
	}

protected:
	float x;
	float y;

	float sizeX = 0;
	float sizeY = 0;

	//�@��ꂽ���ǂ���
	bool getdig = false;
	//�@��邩�̔�
	bool canDig;
};


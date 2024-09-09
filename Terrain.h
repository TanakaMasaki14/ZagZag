#pragma once

class Terrain
{
public:
	Terrain();

	virtual void Update();

	virtual void Draw();

	//座標取得
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

	//掘られたかどうか
	bool getdig = false;
	//掘れるかの否
	bool canDig;
};


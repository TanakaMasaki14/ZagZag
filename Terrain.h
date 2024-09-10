#pragma once

class Terrain
{
public:
	Terrain();

	virtual void Update();

	virtual void Draw();

	//ç¿ïWéÊìæ
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
	float x = 0;
	float y = 0;

	float sizeX = 0;
	float sizeY = 0;

	//å@ÇÁÇÍÇΩÇ©Ç«Ç§Ç©
	bool getdig = false;
	//å@ÇÍÇÈÇ©ÇÃî€
	bool canDig;
};


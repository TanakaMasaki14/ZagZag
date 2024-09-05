#pragma once
#include <DxLib.h>

class Treasure
{
public:
	Treasure();
	virtual void Update();

	virtual void Draw();

private:
protected:
	float x;
	float y;

};
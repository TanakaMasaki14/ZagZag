#pragma once
#include <DxLib.h>
#include "Terrain.h"

class Soil : public Terrain
{
public:
	Soil(float x, float y, bool canDig);

	void Update() override;

	void Draw() override;

private:
	//ƒeƒNƒXƒ`ƒƒ
	//Œ@‚éZ
	int digtexture;
	//Œ@‚é~
	int nodigtexture;





	//bool intressure;
};


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
	//�e�N�X�`��
	//�@��Z
	int digtexture;
	//�@��~
	int nodigtexture;





	//bool intressure;
};


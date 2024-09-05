#pragma once

class Terrain
{
public:
	Terrain();

	virtual void Update();

	virtual void Draw();

protected:
	float x;
	float y;


};


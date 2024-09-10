#pragma once

struct Vector2
{
	float x;
	float y;
};

class Collision
{
private:

	static float Cross(float vector1X, float vector1Y, float vector2X, float vector2Y);

	static Vector2 VectorCalc(float startX, float startY, float endX, float endY);

public:

	/// <summary>
	/// �l�p�`���m�̓����蔻��
	/// </summary>
	/// <param name="mx1">�l�p�`1�̍���x���W</param>
	/// <param name="my1">�l�p�`1�̍���y���W</param>
	/// <param name="mx2">�l�p�`1�̉E��x���W</param>
	/// <param name="my2">�l�p�`1�̉E��y���W</param>
	/// <param name="ex1">�l�p�`2�̍���x���W</param>
	/// <param name="ey1">�l�p�`2�̍���y���W</param>
	/// <param name="ex2">�l�p�`2�̉E��x���W</param>
	/// <param name="ey2">�l�p�`2�̉E��y���W</param>
	/// <returns>�������Ă邩�̐���</returns>
	static bool SquareToSquare(float mx1, float my1, float mx2, float my2, float ex1, float ey1, float ex2, float ey2);


	static bool PointToSquare(float px, float py, float mx1, float my1, float mx2, float my2);

};


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

	/// <summary>
	/// �_�Ǝl�p�`�̓����蔻��
	/// </summary>
	/// <param name="px">�_�̂�</param>
	/// <param name="py">�_�̂�</param>
	/// <param name="mx1">�l�p�`�̍���̂�</param>
	/// <param name="my1">�l�p�`�̍���̂�</param>
	/// <param name="mx2">�l�p�`�̉E���̂�</param>
	/// <param name="my2">�l�p�`�̉E���̂�</param>
	/// <returns></returns>
	static bool PointToSquare(float px, float py, float mx1, float my1, float mx2, float my2);

	/// <summary>
	/// �����Ǝl�p�`�̓����蔻��
	/// </summary>
	/// <param name="squareX1">����̂�</param>
	/// <param name="squareY1">����̂�</param>
	/// <param name="squareX2">�����̂�</param>
	/// <param name="squareY2">�����̂�</param>
	/// <param name="squareX3">�E��̂�</param>
	/// <param name="squareY3">�E��̂�</param>
	/// <param name="squareX4">�E���̂�</param>
	/// <param name="squareY4">�E���̂�</param>
	/// <param name="lineSX">�����̒[�̂�</param>
	/// <param name="lineSY">�����̒[�̂�</param>
	/// <param name="lineEX">���΂̒[�̂�</param>
	/// <param name="lineEY">���΂̒[�̂�</param>
	/// <returns></returns>
	static bool LineToSquare(float squareX1, float squareY1, float squareX2, float squareY2, float squareX3, float squareY3, float squareX4, float squareY4, float lineSX, float lineSY, float lineEX, float lineEY);

};


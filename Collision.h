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
	/// 四角形同士の当たり判定
	/// </summary>
	/// <param name="mx1">四角形1の左上x座標</param>
	/// <param name="my1">四角形1の左上y座標</param>
	/// <param name="mx2">四角形1の右下x座標</param>
	/// <param name="my2">四角形1の右下y座標</param>
	/// <param name="ex1">四角形2の左上x座標</param>
	/// <param name="ey1">四角形2の左上y座標</param>
	/// <param name="ex2">四角形2の右下x座標</param>
	/// <param name="ey2">四角形2の右下y座標</param>
	/// <returns>当たってるかの成否</returns>
	static bool SquareToSquare(float mx1, float my1, float mx2, float my2, float ex1, float ey1, float ex2, float ey2);


	static bool PointToSquare(float px, float py, float mx1, float my1, float mx2, float my2);

};


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

	/// <summary>
	/// 点と四角形の当たり判定
	/// </summary>
	/// <param name="px">点のｘ</param>
	/// <param name="py">点のｙ</param>
	/// <param name="mx1">四角形の左上のｘ</param>
	/// <param name="my1">四角形の左上のｙ</param>
	/// <param name="mx2">四角形の右下のｘ</param>
	/// <param name="my2">四角形の右下のｙ</param>
	/// <returns></returns>
	static bool PointToSquare(float px, float py, float mx1, float my1, float mx2, float my2);

	/// <summary>
	/// 線分と四角形の当たり判定
	/// </summary>
	/// <param name="squareX1">左上のｘ</param>
	/// <param name="squareY1">左上のｙ</param>
	/// <param name="squareX2">左下のｘ</param>
	/// <param name="squareY2">左下のｙ</param>
	/// <param name="squareX3">右上のｘ</param>
	/// <param name="squareY3">右上のｙ</param>
	/// <param name="squareX4">右下のｘ</param>
	/// <param name="squareY4">右下のｙ</param>
	/// <param name="lineSX">線分の端のｘ</param>
	/// <param name="lineSY">線分の端のｙ</param>
	/// <param name="lineEX">反対の端のｘ</param>
	/// <param name="lineEY">反対の端のｙ</param>
	/// <returns></returns>
	static bool LineToSquare(float squareX1, float squareY1, float squareX2, float squareY2, float squareX3, float squareY3, float squareX4, float squareY4, float lineSX, float lineSY, float lineEX, float lineEY);

};


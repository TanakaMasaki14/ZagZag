#pragma once

class Collision
{
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



};


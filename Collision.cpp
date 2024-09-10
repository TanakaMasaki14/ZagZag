
#include "Collision.h"

float Collision::Cross(float vector1X, float vector1Y, float vector2X, float vector2Y)
{
	float result;

	result = vector1X * vector2Y - vector1Y * vector2X;

	return result;
}

Vector2 Collision::VectorCalc(float startX, float startY, float endX, float endY)
{
	Vector2 result;

	result.x = endX - startX;
	result.y = endY - startY;

	return result;
}

bool Collision::SquareToSquare(float mx1, float my1, float mx2, float my2, float ex1, float ey1, float ex2, float ey2)
{
	if (mx1 <= ex2 && ex1 <= mx2 && my1 <= ey2 && ey1 <= my2) {
		return true;
	}

	return false;
}

bool Collision::PointToSquare(float px, float py, float mx1, float my1, float mx2, float my2)
{
	if (px >= mx1 && px <= mx2 && py >= my1 && py <= my2) {
		return true;
	}
	return false;
}

#include "Collision.h"

bool Collision::SquareToSquare(float mx1, float my1, float mx2, float my2, float ex1, float ey1, float ex2, float ey2)
{
	if (mx1 <= ex2 && ex1 <= mx2 && my1 <= ey2 && ey1 <= my2) {
		return true;
	}

	return false;
}

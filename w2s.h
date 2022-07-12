#pragma once
#include "mathn.h"

static bool w2s(matrix4x4& matrix, vec3& from, vec2& to, int ScreenCenterX, int ScreenCenterY)
{
	float ViewW = matrix._14 * from.X + matrix._24 * from.Y + matrix._34 * from.Z + matrix._44;

	if (ViewW > 0.01f)
	{
		ViewW = 1.0f / ViewW;

		to.X = ScreenCenterX + (matrix._11 * from.X + matrix._21 * from.Y + matrix._31 * from.Z + matrix._41) * ViewW * ScreenCenterX;
		to.Y = ScreenCenterY - (matrix._12 * from.X + matrix._22 * from.Y + matrix._32 * from.Z + matrix._42) * ViewW * ScreenCenterY;
		return true;
	}
	return false;
}
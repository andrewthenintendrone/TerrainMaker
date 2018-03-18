#pragma once
#include "Vector2.h"
#include "Array2D.h"

class PerlinNoise
{
public:

	PerlinNoise();

	float lerp(float a0, float a1, float w);
	float dotGridGradient(int ix, int iy, float x, float y);
	float perlin(float x, float y);

private:

	void defineGrid();

	Array2D<Vector2, 256, 256> m_vectorGrid;
};
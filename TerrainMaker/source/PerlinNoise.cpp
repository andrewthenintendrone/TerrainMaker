#include "PerlinNoise.h"
#include <random>
#include <cmath>

PerlinNoise::PerlinNoise()
{
	// define grid
	defineGrid();
}

// Function to linearly interpolate between a0 and a1
// Weight w should be in the range [0.0, 1.0]
float PerlinNoise::lerp(float a0, float a1, float w)
{
	return (1.0 - w) * a0 + w * a1;
}

// Computes the dot product of the distance and gradient vectors.
float PerlinNoise::dotGridGradient(int ix, int iy, float x, float y)
{
	// Compute the distance vector
	float dx = x - (float)ix;
	float dy = y - (float)iy;

	// Compute the dot-product
	return (dx * m_vectorGrid(iy, ix).x + dy * m_vectorGrid(iy, ix).y);
}

// Compute Perlin noise at coordinates x, y
float PerlinNoise::perlin(float x, float y)
{

	// Determine grid cell coordinates
	int x0 = std::floor(x);
	int x1 = x0 + 1;
	int y0 = std::floor(y);
	int y1 = y0 + 1;

	// Determine interpolation weights
	// Could also use higher order polynomial/s-curve here
	float sx = x - (float)x0;
	float sy = y - (float)y0;

	// Interpolate between grid point gradients
	float n0, n1, ix0, ix1, value;
	n0 = dotGridGradient(x0, y0, x, y);
	n1 = dotGridGradient(x1, y0, x, y);
	ix0 = lerp(n0, n1, sx);
	n0 = dotGridGradient(x0, y1, x, y);
	n1 = dotGridGradient(x1, y1, x, y);
	ix1 = lerp(n0, n1, sx);
	value = lerp(ix0, ix1, sy);

	return value;
}

// defines the vector grid
void PerlinNoise::defineGrid()
{
	for (int x = 0; x < 256; x++)
	{
		for (int y = 0; y < 256; y++)
		{
			Vector2 gradient;

			gradient.x = rand() % 2 == 0 ? -1 : 1;
			gradient.y = rand() % 2 == 0 ? -1 : 1;

			m_vectorGrid(x, y) = gradient;
		}
	}
}

#pragma once
#include "Vector2.h"
#include "Vector3.h"
#include <string>
#include "Array2D.h"
#include "Color.h"

class Terrain
{
public:

	Terrain(unsigned int gridSizeX = 1, unsigned int gridSizeY = 1);

	// getters
	Vector3 getGridScale() const { return m_gridScale; }

	// setters
	void setGridScale(const Vector3 gridScale) { m_gridScale = gridScale; }

	void generateRandom();
	void generatePerlin(float xScale, float yScale);
	void generateOctavePerlin(float xScale, float yScale, int octaves, float persistance);
	void generateSinWaves(float xScale, float yScale);

	void writeObjFile(const std::string& fileName);
	void writePlyFile(const std::string& fileName);

private:

	// scale of final mesh
	Vector3 m_gridScale = Vector3(1, 1, 1);

	Vector3 m_centerPoint = Vector3(0, 0, 0);

	// height values
	Array2D<float> m_heights = Array2D<float>();
};
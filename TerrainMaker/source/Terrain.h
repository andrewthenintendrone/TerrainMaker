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
	void generatePerlin();

	void writeObjFile(const std::string& fileName);
	void writePlyFile(const std::string& fileName);

private:

	unsigned int m_gridSizeX;
	unsigned int m_gridSizeY;

	// scale of final mesh
	Vector3 m_gridScale = Vector3(1, 1, 1);

	Vector3 m_centerPoint = Vector3(0, 0, 0);

	// height values
	Array2D<float> m_heights = Array2D<float>();
};
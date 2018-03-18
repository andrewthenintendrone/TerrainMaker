#pragma once
#include "Vector3.h"
#include <string>
#include "Array2D.h"

const unsigned int gridSizeX = 128;
const unsigned int gridSizeY = 128;

class Terrain
{
public:

	Terrain() {};

	// getters
	Vector3 getGridScale() const { return m_gridScale; }

	// setters
	void setGridScale(const Vector3 gridScale) { m_gridScale = gridScale; }

	void generateRandom();
	void generatePerlin();
	void generateSquared();

	void writeToFile(const std::string& fileName);

private:

	// scale of final mesh
	Vector3 m_gridScale = Vector3(1, 1, 1);

	// center point of final mesh
	Vector3 m_centerPoint = Vector3(5, 5, 5);

	// height values
	Array2D<float, gridSizeX, gridSizeY> m_heights;
};
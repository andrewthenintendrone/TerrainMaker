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
	void generateDiamondSquare(int featureSize);

	void writeObjFile(const std::string& fileName);
	void writePlyFile(const std::string& fileName);

private:

	unsigned int m_gridSizeX;
	unsigned int m_gridSizeY;

	// scale of final mesh
	Vector3 m_gridScale = Vector3(1, 1, 1);

	// center point of final mesh
	Vector3 m_centerPoint = Vector3(5, 5, 5);

	// height values
	Array2D<float> m_heights;

	void diamondSquare(int stepSize, float scale);

	void sampleSquare(int x, int y, int size, float value);
	void sampleDiamond(int x, int y, int size, float value);

	void diamondSquare2(unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2, float range, unsigned int level);

	float sample(int x, int y);
	void setSample(int x, int y, float sample);
};
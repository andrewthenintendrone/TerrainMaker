#include "Terrain.h"
#include <iostream>
#include <fstream>
#include <random>
#include "PerlinNoise.h"

// randomly set heights
void Terrain::generateRandom()
{
	// set each value to random between 1 and 10
	for (unsigned int x = 0; x < gridSizeX; x++)
	{
		for (unsigned int y = 0; y < gridSizeY; y++)
		{
			m_heights(x, y) = rand() % 10;
		}
	}
}

// randomly set heights using Perlin Noise
void Terrain::generatePerlin()
{
	PerlinNoise perlinNoise;

	// set each value to random perlin value
	for (unsigned int x = 0; x < gridSizeX; x++)
	{
		for (unsigned int y = 0; y < gridSizeY; y++)
		{
			m_heights(x, y) = perlinNoise.perlin(x * 0.5f, y * 0.5f);
		}
	}
}

// set heights using x^2 + y^2
void Terrain::generateSquared()
{
	for (unsigned int x = 0; x < gridSizeX; x++)
	{
		for (unsigned int y = 0; y < gridSizeY; y++)
		{
			m_heights(x, y) = (x * x + y * y);
		}
	}
}

// write to obj file
void Terrain::writeToFile(const std::string& fileName)
{
	std::ofstream outputFile(fileName, std::ios::binary | std::ios::trunc);

	if (!outputFile.is_open())
	{
		std::cout << "Failed to open " << fileName << " for writing." << std::endl;
		return;
	}

	// write terrain
	outputFile << "o Terrain" << std::endl;

	// calculate center point
	m_centerPoint = Vector3(gridSizeX * m_gridScale.x * 0.5f - 0.5f, 0, gridSizeY * m_gridScale.z * 0.5f - 0.5f);

	// write verts
	for (unsigned int x = 0; x < gridSizeX; x++)
	{
		for (unsigned int y = 0; y < gridSizeY; y++)
		{
			outputFile << "v " << x * m_gridScale.x - m_centerPoint.x << " ";
			outputFile << m_heights(x, y) * m_gridScale.y - m_centerPoint.y << " ";
			outputFile << y * m_gridScale.z - m_centerPoint.z << std::endl;
		}
	}

	// write tris
	for (unsigned int x = 0, offset = 0; x < gridSizeX; x++)
	{
		for (unsigned int y = 0; y < gridSizeY; y++, offset++)
		{
			if (x < gridSizeX - 1 && y < gridSizeY - 1)
			{
				unsigned int p1 = offset + 1;
				unsigned int p2 = offset + 2;
				unsigned int p3 = offset + gridSizeX + 1;
				unsigned int p4 = offset + gridSizeX + 2;


				outputFile << "f " << p1 << "//" << p2 << " ";
				outputFile << p2 << "//" << p3 << " ";
				outputFile << p3 << "//" << p1 << std::endl;

				outputFile << "f " << p2 << "//" << p4 << " ";
				outputFile << p4 << "//" << p3 << " ";
				outputFile << p3 << "//" << p2 << std::endl;
			}
		}
	}

	outputFile.close();
}

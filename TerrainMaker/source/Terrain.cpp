#include "Terrain.h"
#include <iostream>
#include <fstream>
#include <random>
#include "PerlinNoise.h"

float frand(float min, float max)
{
	float f = (float)rand() / (RAND_MAX + 1);
	return min + f * (max - min);
}

float degreesToRadians(float degrees)
{
	return 2 * std::_Pi * (degrees / 360.0f);
}

Terrain::Terrain(unsigned int gridSizeX, unsigned int gridSizeY)
{
	m_heights = Array2D<float>(gridSizeX, gridSizeY);
}

// randomly set heights
void Terrain::generateRandom()
{
	// set each value to random between 1 and 10
	for (unsigned int x = 0; x < m_heights.getWidth(); x++)
	{
		for (unsigned int y = 0; y < m_heights.getHeight(); y++)
		{
			m_heights(x, y) = frand(-1, 1);
		}
	}
}

// randomly set heights using Perlin Noise
void Terrain::generatePerlin(float xScale, float yScale)
{
	// set each value to random perlin value
	for (float x = 0; x < m_heights.getWidth(); x++)
	{
		for (float y = 0; y < m_heights.getHeight(); y++)
		{
			m_heights(x, y) = PerlinNoise::getInstance().perlin(x * xScale, y * yScale);
		}
	}
}

// randomly set heights using several iterations of Perlin Noise
void Terrain::generateOctavePerlin(float xScale, float yScale, int octaves, float persistance)
{
	// set each value to random perlin value
	for (float x = 0; x < m_heights.getWidth(); x++)
	{
		for (float y = 0; y < m_heights.getHeight(); y++)
		{
			m_heights(x, y) = PerlinNoise::getInstance().octavePerlin(x * xScale, y * yScale, octaves, persistance);;
		}
	}
}

void Terrain::generateSinWaves(float xScale, float yScale)
{
	// set each value to random perlin value
	for (float x = 0; x < m_heights.getHeight(); x++)
	{
		for (float y = 0; y < m_heights.getWidth(); y++)
		{
			m_heights(x, y) = std::sinf(degreesToRadians(x / m_heights.getWidth() * 360.0f * xScale)) * std::sinf(degreesToRadians(y / m_heights.getHeight() * 360.0f * yScale)) * m_gridScale.y;
		}
	}
}

// write to obj file
void Terrain::writeObjFile(const std::string& fileName)
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
	m_centerPoint = Vector3(m_heights.getWidth() * m_gridScale.x * 0.5f - 0.5f, 0, m_heights.getHeight() * m_gridScale.z * 0.5f - 0.5f);

	// write verts
	for (unsigned int x = 0; x < m_heights.getWidth(); x++)
	{
		for (unsigned int y = 0; y < m_heights.getHeight(); y++)
		{
			outputFile << "v " << x * m_gridScale.x - m_centerPoint.x << " ";
			outputFile << m_heights(x, y) * m_gridScale.y - m_centerPoint.y << " ";
			outputFile << y * m_gridScale.z - m_centerPoint.z << std::endl;
		}
	}

	// write tris
	for (unsigned int x = 0, offset = 0; x < m_heights.getWidth(); x++)
	{
		for (unsigned int y = 0; y < m_heights.getHeight(); y++, offset++)
		{
			if (x < m_heights.getWidth() - 1 && y < m_heights.getHeight() - 1)
			{
				unsigned int p1 = offset + 1;
				unsigned int p2 = offset + 2;
				unsigned int p3 = offset + m_heights.getWidth() + 1;
				unsigned int p4 = offset + m_heights.getWidth() + 2;


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

// write to ply file
void Terrain::writePlyFile(const std::string& fileName)
{
	std::ofstream outputFile(fileName, std::ios::trunc);

	if (!outputFile.is_open())
	{
		std::cout << "Failed to open " << fileName << " for writing." << std::endl;
		return;
	}

	// write terrain

	// write ply file header
	outputFile << "ply\n";
	outputFile << "format ascii 1.0\n";
	outputFile << "comment created using TerrainMaker\n";
	outputFile << "element vertex " << m_heights.getWidth() * m_heights.getHeight() << std::endl;
	outputFile << "property float x\n";
	outputFile << "property float y\n";
	outputFile << "property float z\n";
	outputFile << "element face " << (m_heights.getWidth() - 1) * (m_heights.getHeight() - 1) * 2 << std::endl;
	outputFile << "property list uchar int vertex_indices\n";
	outputFile << "end_header\n";

	// calculate center point
	m_centerPoint = Vector3(m_heights.getWidth() * m_gridScale.x * 0.5f - 0.5f, 0.0f, m_heights.getHeight() * m_gridScale.z * 0.5f - 0.5f);

	// write verts / colors
	for (unsigned int x = 0; x < m_heights.getWidth(); x++)
	{
		for (unsigned int y = 0; y < m_heights.getHeight(); y++)
		{
			outputFile << x * m_gridScale.x - m_centerPoint.x << " ";
			outputFile << y * m_gridScale.z - m_centerPoint.z << " ";
			outputFile << m_heights(x, y) - m_centerPoint.y << " " << std::endl;
		}
	}

	// write tris
	for (unsigned int x = 0, offset = 0; x < m_heights.getWidth(); x++)
	{
		for (unsigned int y = 0; y < m_heights.getHeight(); y++, offset++)
		{
			if (x < m_heights.getWidth() - 1 && y < m_heights.getHeight() - 1)
			{
				unsigned int p1 = offset;
				unsigned int p2 = offset + 1;
				unsigned int p3 = offset + m_heights.getHeight();
				unsigned int p4 = offset + m_heights.getHeight() + 1;

				// tris
				outputFile << "3 " << p1 << " " << p3 << " " << p4 << std::endl;
				outputFile << "3 " << p1 << " " << p4 << " " << p2 << std::endl;
			}
		}
	}

	outputFile.close();
}

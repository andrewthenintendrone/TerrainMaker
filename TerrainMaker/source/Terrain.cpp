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
	float maxValue = 0;

	// set each value to random perlin value
	for (unsigned int x = 0; x < gridSizeX; x++)
	{
		for (unsigned int y = 0; y < gridSizeY; y++)
		{
			m_heights(x, y) = PerlinNoise::getInstance().octavePerlin(x * 0.025f, y * 0.025f, 5, 0.75f);
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

// write to ply file
void Terrain::writePlyFile(const std::string& fileName)
{
	std::ofstream outputFile(fileName, std::ios::trunc);

	if (!outputFile.is_open())
	{
		std::cout << "Failed to open " << fileName << " for writing." << std::endl;
		return;
	}

	// calculate lowest / highest points
	float highest = -1000;
	float lowest = 1000;

	for (int x = 0; x < gridSizeX; x++)
	{
		for (int y = 0; y < gridSizeY; y++)
		{
			highest = std::max(m_heights(x, y), highest);
			lowest = std::min(m_heights(x, y), lowest);
		}
	}

	float diff = highest - lowest;

	// write terrain

	// write ply file header
	outputFile << "ply\n";
	outputFile << "format ascii 1.0\n";
	outputFile << "comment created using TerrainMaker\n";
	outputFile << "element vertex " << gridSizeX * gridSizeY << std::endl;
	outputFile << "property float x\n";
	outputFile << "property float y\n";
	outputFile << "property float z\n";
	// color
	outputFile << "property uchar red\n";
	outputFile << "property uchar green\n";
	outputFile << "property uchar blue\n";
	outputFile << "element face " << (gridSizeX - 1) * (gridSizeY - 1) << std::endl;
	outputFile << "property list uchar int vertex_indices\n";
	outputFile << "end_header\n";

	// calculate center point
	m_centerPoint = Vector3(gridSizeX * m_gridScale.x * 0.5f - 0.5f, 0, gridSizeY * m_gridScale.z * 0.5f - 0.5f);

	// write verts / colors
	for (unsigned int x = 0; x < gridSizeX; x++)
	{
		for (unsigned int y = 0; y < gridSizeY; y++)
		{
			outputFile << x * m_gridScale.x - m_centerPoint.x << " ";
			outputFile << y * m_gridScale.z - m_centerPoint.z << " ";
			outputFile << m_heights(x, y) * m_gridScale.y - m_centerPoint.y << " ";

			Color currentColor;

			if (m_heights(x, y) <= lowest + diff * 0.33f)
			{
				currentColor = Color(0x7e3f12ff);
			}
			else if (m_heights(x, y) <= lowest + diff * 0.66f)
			{
				currentColor = Color(0xffc0cbff);
			}
			else
			{
				currentColor = Color(0xfffcf8ff);
			}

			outputFile << (int)currentColor.r << " ";
			outputFile << (int)currentColor.g << " ";
			outputFile << (int)currentColor.b << std::endl;
		}
	}

	// write tris
	for (unsigned int x = 0, offset = 0; x < gridSizeX; x++)
	{
		for (unsigned int y = 0; y < gridSizeY; y++, offset++)
		{
			if (x < gridSizeX - 1 && y < gridSizeY - 1)
			{
				unsigned int p1 = offset;
				unsigned int p2 = offset + 1;
				unsigned int p3 = offset + gridSizeX;
				unsigned int p4 = offset + gridSizeX + 1;

				outputFile << "4 " << p1 << " " << p3 << " " << p4 << " " << p2 <<std::endl;
			}
		}
	}

	outputFile.close();
}

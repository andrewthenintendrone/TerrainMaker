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

Terrain::Terrain(unsigned int gridSizeX, unsigned int gridSizeY) : m_gridSizeX(gridSizeX), m_gridSizeY(gridSizeY)
{
	m_heights = Array2D<float>(m_gridSizeX, m_gridSizeY);
}

// randomly set heights
void Terrain::generateRandom()
{
	// set each value to random between 1 and 10
	for (unsigned int x = 0; x < m_gridSizeX; x++)
	{
		for (unsigned int y = 0; y < m_gridSizeY; y++)
		{
			m_heights(x, y) = frand(-1, 1);
		}
	}
}

// randomly set heights using Perlin Noise
void Terrain::generatePerlin()
{
	// set each value to random perlin value
	for (unsigned int x = 0; x < m_gridSizeX; x++)
	{
		for (unsigned int y = 0; y < m_gridSizeY; y++)
		{
			m_heights(x, y) = PerlinNoise::getInstance().octavePerlin(x * 0.01f, y * 0.01f, 10, 0.5f);
		}
	}
}

// set heights using the diamond square algorithm
void Terrain::generateDiamondSquare(int featureSize)
{
	generateRandom();

	// seed corners
	m_heights(0, 0) = 0;
	m_heights(m_gridSizeX - 1, 0) = 0;
	m_heights(0, m_gridSizeY - 1) = 0;
	m_heights(m_gridSizeX - 1, m_gridSizeY - 1) = 0;

	int sampleSize = featureSize;

	float scale = 1.0f;

	//while (sampleSize > 1)
	//{
		//diamondSquare(sampleSize, scale);
	diamondSquare2(0, 0, m_gridSizeX - 1, m_gridSizeY - 1, 0.5f, 20);

		sampleSize /= 2;
		scale /= 2.0f;
	//}
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
	m_centerPoint = Vector3(m_gridSizeX * m_gridScale.x * 0.5f - 0.5f, 0, m_gridSizeY * m_gridScale.z * 0.5f - 0.5f);

	// write verts
	for (unsigned int x = 0; x < m_gridSizeX; x++)
	{
		for (unsigned int y = 0; y < m_gridSizeY; y++)
		{
			outputFile << "v " << x * m_gridScale.x - m_centerPoint.x << " ";
			outputFile << m_heights(x, y) * m_gridScale.y - m_centerPoint.y << " ";
			outputFile << y * m_gridScale.z - m_centerPoint.z << std::endl;
		}
	}

	// write tris
	for (unsigned int x = 0, offset = 0; x < m_gridSizeX; x++)
	{
		for (unsigned int y = 0; y < m_gridSizeY; y++, offset++)
		{
			if (x < m_gridSizeX - 1 && y < m_gridSizeY - 1)
			{
				unsigned int p1 = offset + 1;
				unsigned int p2 = offset + 2;
				unsigned int p3 = offset + m_gridSizeX + 1;
				unsigned int p4 = offset + m_gridSizeX + 2;


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
	outputFile << "element vertex " << m_gridSizeX * m_gridSizeY << std::endl;
	outputFile << "property float x\n";
	outputFile << "property float y\n";
	outputFile << "property float z\n";
	// color (currently unused)
	//outputFile << "property uchar red\n";
	//outputFile << "property uchar green\n";
	//outputFile << "property uchar blue\n";
	outputFile << "element face " << (m_gridSizeX - 1) * (m_gridSizeY - 1) << std::endl; // x2 whn using tris
	outputFile << "property list uchar int vertex_indices\n";
	outputFile << "end_header\n";

	// calculate center point
	m_centerPoint = Vector3(m_gridSizeX * m_gridScale.x * 0.5f - 0.5f, 0, m_gridSizeY * m_gridScale.z * 0.5f - 0.5f);

	// write verts / colors
	for (unsigned int x = 0; x < m_gridSizeX; x++)
	{
		for (unsigned int y = 0; y < m_gridSizeY; y++)
		{
			outputFile << x * m_gridScale.x - m_centerPoint.x << " ";
			outputFile << y * m_gridScale.z - m_centerPoint.z << " ";
			outputFile << m_heights(x, y) * m_gridScale.y - m_centerPoint.y << std::endl;
		}
	}

	// write tris
	for (unsigned int x = 0, offset = 0; x < m_gridSizeX; x++)
	{
		for (unsigned int y = 0; y < m_gridSizeY; y++, offset++)
		{
			if (x < m_gridSizeX - 1 && y < m_gridSizeY - 1)
			{
				unsigned int p1 = offset;
				unsigned int p2 = offset + 1;
				unsigned int p3 = offset + m_gridSizeX;
				unsigned int p4 = offset + m_gridSizeX + 1;

				// quads
				outputFile << "4 " << p1 << " " << p3 << " " << p4 << " " << p2 <<std::endl;

				// tris
				/*outputFile << "3 " << p1 << " " << p3 << " " << p4 << std::endl;
				outputFile << "3 " << p1 << " " << p4 << " " << p2 << std::endl;*/
			}
		}
	}

	outputFile.close();
}

void Terrain::diamondSquare(int stepsize, float scale)
{
	int halfstep = stepsize / 2;

	for (int y = halfstep; y < m_gridSizeY + halfstep; y += stepsize)
	{
		for (int x = halfstep; x < m_gridSizeX + halfstep; x += stepsize)
		{
			sampleSquare(x, y, stepsize, frand(-scale, scale));
		}
	}

	for (int y = 0; y < m_gridSizeY; y += stepsize)
	{
		for (int x = 0; x < m_gridSizeX; x += stepsize)
		{
			sampleDiamond(x + halfstep, y, stepsize, frand(-scale, scale));
			sampleDiamond(x, y + halfstep, stepsize, frand(-scale, scale));
		}
	}
}

void Terrain::sampleSquare(int x, int y, int size, float value)
{
	int hs = size / 2;

	// a     b 
	//
	//    x
	//
	// c     d

	double a = sample(x - hs, y - hs);
	double b = sample(x + hs, y - hs);
	double c = sample(x - hs, y + hs);
	double d = sample(x + hs, y + hs);

	setSample(x, y, ((a + b + c + d) / 4.0) + value);
}

void Terrain::sampleDiamond(int x, int y, int size, float value)
{
	int hs = size / 2;

	//   c
	//
	//a  x  b
	//
	//   d

	double a = sample(x - hs, y);
	double b = sample(x + hs, y);
	double c = sample(x, y - hs);
	double d = sample(x, y + hs);

	setSample(x, y, ((a + b + c + d) / 4.0) + value);
}

void Terrain::diamondSquare2(unsigned x1, unsigned y1, unsigned x2, unsigned y2, float range, unsigned level)
{
	if (level < 1)
		return;

	// diamonds
	for (unsigned i = x1 + level; i < x2; i += level)
	{
		for (unsigned j = y1 + level; j < y2; j += level)
		{
			float a = m_heights(i - level, j - level);
			float b = m_heights(i, j - level);
			float c = m_heights(i - level, j);
			float d = m_heights(i, j);
			float e = m_heights(i - level / 2, j - level / 2) = (a + b + c + d) / 4 + frand(-range, range);
		}
	}

	// squares
	for (unsigned i = x1 + 2 * level; i < x2; i += level)
	{
		for (unsigned j = y1 + 2 * level; j < y2; j += level)
		{
			float a = m_heights(i - level, j - level);
			float b = m_heights(i, j - level);
			float c = m_heights(i - level, j);
			float d = m_heights(i, j);
			float e = m_heights(i - level / 2, j - level / 2);

			float f = m_heights(i - level, j - level / 2) = (a + c + e + m_heights(i - 3 * level / 2, j - level / 2)) / 4 + frand(-range, range);
			float g = m_heights(i - level / 2, j - level) = (a + b + e + m_heights(i - level / 2, j - 3 * level / 2)) / 4 + frand(-range, range);
		}
	}

	diamondSquare2(x1, y1, x2, y2, range / 2, level / 2);
}

float Terrain::sample(int x, int y)
{
	return (m_heights(x & (m_gridSizeX - 1), y & (m_gridSizeY - 1)));
}

void Terrain::setSample(int x, int y, float value)
{
	m_heights(x & (m_gridSizeX - 1), y & (m_gridSizeY - 1)) = value;
}

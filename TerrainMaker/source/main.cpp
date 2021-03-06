#include <iostream>
#include "Terrain.h"
#include "Bitmask.h"

int main(int argc, char* argv[])
{
	srand(18);

	// create test terrain
	Terrain testTerrain(128, 128);
	testTerrain.setGridScale(Vector3(1, 100, 1));
	testTerrain.generateOctavePerlin(0.345, 0.345f, 8, 0.15f);
	testTerrain.writePlyFile("./terrain.ply");

	system("pause");
	return 0;
}


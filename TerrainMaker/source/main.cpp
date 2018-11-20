#include <iostream>
#include "Terrain.h"
#include "Bitmask.h"

int main(int argc, char* argv[])
{
	srand(18);

	// create test terrain
	Terrain testTerrain(256, 256);
	testTerrain.setGridScale(Vector3(1, 100, 1));
	testTerrain.generatePerlin();
	testTerrain.writePlyFile("./terrain.ply");

	system("pause");
	return 0;
}


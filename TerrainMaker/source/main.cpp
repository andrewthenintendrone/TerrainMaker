#include <iostream>
#include "Terrain.h"

int main(int argc, char* argv[])
{
	srand(8);

	// create test terrain
	Terrain testTerrain(256, 256);
	testTerrain.setGridScale(Vector3(1, 64, 1));
	testTerrain.generatePerlin();
	testTerrain.writePlyFile("./terrain.ply");

	system("pause");
    return 0;
}


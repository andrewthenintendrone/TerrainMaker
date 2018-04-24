#include <iostream>
#include "Terrain.h"

int main(int argc, char* argv[])
{
	srand(8);

	// create test terrain
	Terrain testTerrain;
	testTerrain.setGridScale(Vector3(1, 128, 1));
	testTerrain.generatePerlin();
	testTerrain.writePlyFile("./terrain.ply");

	system("pause");
    return 0;
}


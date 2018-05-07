#include <iostream>
#include "Terrain.h"

int main(int argc, char* argv[])
{
	srand(9);

	// create test terrain
	Terrain testTerrain(128, 128);
	testTerrain.setGridScale(Vector3(1, 1, 1));
	testTerrain.generateDiamondSquare(8);
	testTerrain.writePlyFile("./terrain.ply");

	system("pause");
    return 0;
}


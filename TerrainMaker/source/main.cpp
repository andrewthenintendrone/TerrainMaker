#include <iostream>
#include "Terrain.h"

int main(int argc, char* argv[])
{
	// create test terrain
	Terrain testTerrain;
	testTerrain.setGridScale(Vector3(1, 1, 1));
	testTerrain.generateSquared();
	testTerrain.writeToFile("C://Users//Andrew//Desktop//TestTerrain.obj");

	std::cout << "done" << std::endl;
	std::cin.get();

    return 0;
}


#include "ClashofEntios.hh"
#include "Renderer.hh"
#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>


void main() {
	std::ifstream file;
	int rows = 36;
	int columns = 74;
	Map map(rows, columns);

	map.readMap(file, "default.cfg");
}
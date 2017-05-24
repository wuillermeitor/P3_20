#include <iostream>
#include <string>
#include <fstream>
#include "ClashofEntios.hh"


std::ifstream file;
Map map;
bool player1torn;

void main() {
	player1torn = true;
	map.ReadMap(file, "default.cfg");
	map.drawMap(player1torn);
}
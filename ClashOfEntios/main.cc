#include <iostream>
#include <string>
#include <fstream>
#include "ClashofEntios.hh"


std::ifstream file;
Map map;
Player player;
bool player1torn;

void main() {
	enti::InputKey key;
	player1torn = true;
	map.ReadMap(file, "default.cfg");
	map.drawMap(player1torn);
	player.PlayerMovement(key, player1torn);
}
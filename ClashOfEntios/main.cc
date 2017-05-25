#include <iostream>
#include <string>
#include <fstream>
#include "ClashofEntios.hh"


std::ifstream file;
Map map;
bool player1torn;

std::vector<Entio>EntioPA;
std::vector<Entio>EntioPB;
void main() {
	enti::InputKey tecla{ enti::InputKey::ENTER };
	player1torn = true;
	map.ReadMap(file, "default.cfg");
	map.drawMap(player1torn);
	Player player(&map, EntioPA, EntioPB); 
	while (true) {
		map.drawMap(player1torn);
		player.PlayerMovement(tecla, EntioPA);
	}
}
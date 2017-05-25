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
	map.ReadMap(file, "default.cfg");
	map.drawMap(player1torn);
	Player player(&map, EntioPA, EntioPB);
	enti::InputKey tecla;
	player1torn = true;
	while (true) {
		map.drawMap(player1torn);
		player.PlayerMovement(tecla, EntioPA);
		tecla = enti::getInputKey();
	}
}
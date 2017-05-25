#include <iostream>
#include <string>
#include <fstream>
#include "ClashofEntios.hh"

void swapPlayer(std::vector<Entio>&Player1, std::vector<Entio>&Player2) {
	std::vector<Entio>aux = Player1;
	Player1 = Player2;
	Player2 = aux;
}

std::ifstream file;
Map map;
bool player1torn = true;
std::vector<Entio>EntioPA;
std::vector<Entio>EntioPB;
std::vector<Entio>CurrentPlayer;
std::vector<Entio>NextPlayer;
void main() {
	map.ReadMap(file, "default.cfg");
	map.drawMap(player1torn);
	Player player(&map, EntioPA, EntioPB);
	CurrentPlayer = EntioPA;
	NextPlayer = EntioPB;
	enti::InputKey tecla;
	while (true) {
		map.drawMap(player1torn);
		if (player.PlayerMovement(tecla, CurrentPlayer)) {
			swapPlayer(CurrentPlayer, NextPlayer);
			player1torn = !player1torn;
		}
		tecla = enti::getInputKey();
	}
}
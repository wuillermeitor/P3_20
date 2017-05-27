#include <iostream>
#include <string>
#include <fstream>
#include "ClashofEntios.hh"

//Función que cambia de jugador en el bucle del juego.
void swapPlayer(std::vector<Entio>&Player1, std::vector<Entio>&Player2) {
	std::vector<Entio>aux = Player1;
	Player1 = Player2;
	Player2 = aux;
}

//Función que ordena los entios en función de su fatiga.
void ordenarPorFatiga(std::vector<Entio>&Entios) {
	std::vector<Entio> tmp;
	for (int i = 1; i < Entios.size(); i++) {
		for (int j = 0; j < Entios.size() - 1; j++) {
			if (Entios[j].fatiga > Entios[j + 1].fatiga) {
				tmp.push_back(Entios[j]);
				Entios[j] = Entios[j + 1];
				Entios[j + 1] = tmp.back();
			}
		}
	}
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
			ordenarPorFatiga(CurrentPlayer);
			swapPlayer(CurrentPlayer, NextPlayer);
			player1torn = !player1torn;
			player.currentEntio = 0;
		}
		tecla = enti::getInputKey();
	}
}
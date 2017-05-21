#include <iostream>
#include <string>
#include <fstream>
#include "ClashofEntios.hh"
#include "Renderer.hh"

//Class Map
Map::Map(int _rows, int _columns) {
	row = _rows;
	column = _columns;
	map = new char*[row];
	for (int i = 0; i < row; i++) {
		map[i] = new char[column];
	}
}

void Map::readMap(std::ifstream &file, std::string filename) {
	file.open(filename);
	std::string line;
	char c;

	if (file.is_open()) {
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < column; j++) {
				file.get(c);
				map[i][j] = c;
				std::cout << map[i][j];
			}
		}
	}
	file.close();
	drawMap();
}

void Map::drawMap() {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			if (map[i][j] == 'X') {
				enti::cout << enti::Color::LIGHTRED << map[i][j];
				enti::cout << " ";
			}
			else if (map[i][j] == '.') {
				enti::cout << enti::Color::WHITE << map[i][j];
				enti::cout << " ";
			}
			else if (map[i][j] == ':') {
				enti::cout << enti::Color::LIGHTGREEN << map[i][j];
				enti::cout << " ";
			}
			else if (map[i][j] == 'O') {
				enti::cout << enti::Color::LIGHTCYAN << map[i][j];
				enti::cout << " ";
			}
			else if (map[i][j] == '\n') {
				enti::cout << enti::endl;
			}
			else {
				enti::cout << map[i][j];
				enti::cout << " ";
			}
		}
	}
	enti::cout<<enti::cend;
}

Map::~Map() {

}


//Class Player
Player::Player() {

}

void Player::PlayerMovement() {

}

Player::~Player() {

}
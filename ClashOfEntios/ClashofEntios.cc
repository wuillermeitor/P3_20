#include <iostream>
#include <string>
#include <fstream>
#include "ClashofEntios.hh"
#include "Renderer.hh"
//Examen
//mucha cosa pequeña



//CLASE MAPA
void Map::ReadMap(std::ifstream &file, std::string filename) {
	file.open(filename);
	char mapCharacter;

	if (file.is_open()) {
		infoMap = new symbols*[dimensiones.filas];
		for (int i = 0; i < dimensiones.filas; i++) {
			infoMap[i] = new symbols[dimensiones.columnas];
			for (int j = 0; j < dimensiones.columnas; j++) {
				file.get(mapCharacter);
				if (mapCharacter == static_cast<char>(symbols::MONTAÑA)) {
					infoMap[i][j] = symbols::MONTAÑA;
				}
				else if (mapCharacter == static_cast<char>(symbols::AGUA)) {
					infoMap[i][j] = symbols::AGUA;
				}
				else if (mapCharacter == static_cast<char>(symbols::BOSQUE)) {
					infoMap[i][j] = symbols::BOSQUE;
				}
				else if (mapCharacter == static_cast<char>(symbols::TIERRA)) {
					infoMap[i][j] = symbols::TIERRA;
				}
				else if (mapCharacter == static_cast<char>(symbols::ENTIO1)) {
					infoMap[i][j] = symbols::ENTIO1;
					EntioPB.push_back(Entio());
					EntioPB[0].caracter = infoMap[i][j];
				}
				else if (mapCharacter == static_cast<char>(symbols::ENTIO2)) {
					infoMap[i][j] = symbols::ENTIO2;
					EntioPB.push_back(Entio());
					EntioPB[1].caracter = infoMap[i][j];
				}
				else if (mapCharacter == static_cast<char>(symbols::ENTIO3)) {
					infoMap[i][j] = symbols::ENTIO3;
					EntioPB.push_back(Entio());
					EntioPB[2].caracter = infoMap[i][j];
				}
				else if (mapCharacter == static_cast<char>(symbols::ENTIO4)) {
					infoMap[i][j] = symbols::ENTIO4;
					EntioPB.push_back(Entio());
					EntioPB[3].caracter = infoMap[i][j];
				}
				else if (mapCharacter == static_cast<char>(symbols::ENTIO5)) {
					infoMap[i][j] = symbols::ENTIO5;
					EntioPB.push_back(Entio());
					EntioPB[4].caracter = infoMap[i][j];
				}
				else if (mapCharacter == static_cast<char>(symbols::ENTIO6)) {
					infoMap[i][j] = symbols::ENTIO6;
					EntioPB.push_back(Entio());
					EntioPB[5].caracter = infoMap[i][j];
				}

				else if (mapCharacter == static_cast<char>(symbols::ENTIOA)) {
					infoMap[i][j] = symbols::ENTIOA;
					EntioPA.push_back(Entio());
					EntioPA[0].caracter = infoMap[i][j];
				}
				else if (mapCharacter == static_cast<char>(symbols::ENTIOB)) {
					infoMap[i][j] = symbols::ENTIOB;
					EntioPA.push_back(Entio());
					EntioPA[1].caracter = infoMap[i][j];
				}
				else if (mapCharacter == static_cast<char>(symbols::ENTIOC)) {
					infoMap[i][j] = symbols::ENTIOC;
					EntioPA.push_back(Entio());
					EntioPA[2].caracter = infoMap[i][j];
				}
				else if (mapCharacter == static_cast<char>(symbols::ENTIOD)) {
					infoMap[i][j] = symbols::ENTIOD;
					EntioPA.push_back(Entio());
					EntioPA[3].caracter = infoMap[i][j];
				}
				else if (mapCharacter == static_cast<char>(symbols::ENTIOE)) {
					infoMap[i][j] = symbols::ENTIOE;
					EntioPA.push_back(Entio());
					EntioPA[4].caracter = infoMap[i][j];
				}
				else if (mapCharacter == static_cast<char>(symbols::ENTIOF)) {
					infoMap[i][j] = symbols::ENTIOF;
					EntioPA.push_back(Entio());
					EntioPA[5].caracter = infoMap[i][j];
				}
				else {
					infoMap[i][j] = symbols::EMPTY;
				}
			}
		}
	}
	file.close();
}

void Map::drawMap(bool _player1Torn) {

	enti::Color playerA;
	enti::Color playerB;

	if (_player1Torn) {
		playerA = enti::Color::YELLOW;
		playerB = enti::Color::WHITE;
	}
	else {
		playerA = enti::Color::WHITE;
		playerB = enti::Color::YELLOW;
	}

	for (int i = 0; i < dimensiones.filas; i++) {
		for (int j = 0; j < dimensiones.columnas; j++) {
			if (infoMap[i][j] == symbols::MONTAÑA) {
				enti::cout << enti::Color::LIGHTRED << static_cast<char>(infoMap[i][j]);
				enti::cout << " ";
			}
			else if (infoMap[i][j] == symbols::AGUA) {
				enti::cout << enti::Color::LIGHTCYAN << static_cast<char>(infoMap[i][j]);
				enti::cout << " ";
			}
			else if (infoMap[i][j] == symbols::BOSQUE) {
				enti::cout << enti::Color::LIGHTGREEN << static_cast<char>(infoMap[i][j]);
				enti::cout << " ";
			}
			else if (infoMap[i][j] == symbols::TIERRA) {
				enti::cout << enti::Color::WHITE << static_cast<char>(infoMap[i][j]);
				enti::cout << " ";
			}

			else if (infoMap[i][j] == symbols::ENTIOA) {
				enti::cout << playerA << static_cast<char>(infoMap[i][j]);
				enti::cout << " ";
			}
			else if (infoMap[i][j] == symbols::ENTIOB) {
				enti::cout << playerA << static_cast<char>(infoMap[i][j]);
				enti::cout << " ";
			}
			else if (infoMap[i][j] == symbols::ENTIOC) {
				enti::cout << playerA << static_cast<char>(infoMap[i][j]);
				enti::cout << " ";
			}
			else if (infoMap[i][j] == symbols::ENTIOD) {
				enti::cout << playerA << static_cast<char>(infoMap[i][j]);
				enti::cout << " ";
			}
			else if (infoMap[i][j] == symbols::ENTIOE) {
				enti::cout << playerA << static_cast<char>(infoMap[i][j]);
				enti::cout << " ";
			}
			else if (infoMap[i][j] == symbols::ENTIOF) {
				enti::cout << playerA << static_cast<char>(infoMap[i][j]);
				enti::cout << " ";
			}

			else if (infoMap[i][j] == symbols::ENTIO1) {
				enti::cout << playerB << static_cast<char>(infoMap[i][j]);
				enti::cout << " ";
			}
			else if (infoMap[i][j] == symbols::ENTIO2) {
				enti::cout << playerB << static_cast<char>(infoMap[i][j]);
				enti::cout << " ";
			}
			else if (infoMap[i][j] == symbols::ENTIO3) {
				enti::cout << playerB << static_cast<char>(infoMap[i][j]);
				enti::cout << " ";
			}
			else if (infoMap[i][j] == symbols::ENTIO4) {
				enti::cout << playerB << static_cast<char>(infoMap[i][j]);
				enti::cout << " ";
			}
			else if (infoMap[i][j] == symbols::ENTIO5) {
				enti::cout << playerB << static_cast<char>(infoMap[i][j]);
				enti::cout << " ";
			}
			else if (infoMap[i][j] == symbols::ENTIO6) {
				enti::cout << playerB << static_cast<char>(infoMap[i][j]);
				enti::cout << " ";
			}
		}
		enti::cout << enti::endl;
	}
	enti::cout << enti::cend;
}

symbols Map::posicion(const vector & location) {
	return infoMap[location.filas][location.columnas];
}

void Map::modificar(const vector & target, const symbols & value) {
	infoMap[target.filas][target.columnas] = value;
}


Map::~Map() {
	for (int i = 0; i < dimensiones.filas; i++) {
		delete[] this->infoMap[i];
	}
	delete[] this->infoMap;
}

//CLASE PLAYER
void Player::PlayerMovement(const enti::InputKey & key, bool _playerA) {
	CurrentMap->modificar(posicion, symbols::EMPTY);
	int currentEntio;

	if (key != enti::InputKey::NONE) {
		switch (key) {
		case enti::InputKey::ENTER:
			break;
		case enti::InputKey::W:
			if (posicion.columnas != static_cast<char>(symbols::MONTAÑA) && posicion.columnas != static_cast<char>(symbols::AGUA)) {
				posicion.columnas--;
			}
			break;
		case enti::InputKey::A:
			if (posicion.filas != static_cast<char>(symbols::MONTAÑA) && posicion.filas != static_cast<char>(symbols::AGUA)) {
				posicion.filas--;
			}
			break;
		case enti::InputKey::S:
			if (posicion.columnas + 1 != static_cast<char>(symbols::MONTAÑA) && posicion.columnas + 1 != static_cast<char>(symbols::AGUA)) {
				posicion.columnas++;
			}
			break;
		case enti::InputKey::D:
			if (posicion.filas + 1 != static_cast<char>(symbols::MONTAÑA) && posicion.filas + 1 != static_cast<char>(symbols::AGUA)) {
				posicion.filas++;
			}
			break;
		default:
			break;
		}
	}
	CurrentMap->modificar(posicion, symbols::ENTIOA);
}




/*

//Class Player
Player::Player(int posx, int posy, Map &mapa) :map{mapa} {
currentx = posx;
currenty = posy;

for (int i = 0; i < mapa.row; i++) {
for (int j = 0; j < mapa.column; j++) {
if (mapa.map[i][j] >= 'A' && mapa.map[i][j] <= 'F') {
Entio entio(mapa.map[i][j], i, j);
}
}
}
}


void Player::PlayerMovement(int posx, int posy, int entioactual) {

}

Entio::Entio(char identificador, int x, int y) {
entio = identificador;
posx = x;
posy = y;
vida = 10;
flechas = 10;
fatiga = 0;
}
*/
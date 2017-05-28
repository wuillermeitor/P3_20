#include <iostream>
#include <string>
#include <fstream>
#include "ClashofEntios.hh"
#include "Renderer.hh"

//CLASE MAPA
void Map::ReadMap(std::ifstream &file, std::string filename) {
	file.open(filename);//abre el fichero al que queremos acceder.
	char mapCharacter;//variable que usaremos para guardar el caracter de una posición.

	if (file.is_open()) {
		//bucles for anidados que comprobarán con cada carácter del mapa cuál es su símbolo,
		//y en función de este, se guardará en infoMap un símbolo u otro.
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
				}
				else if (mapCharacter == static_cast<char>(symbols::ENTIO2)) {
					infoMap[i][j] = symbols::ENTIO2;
				}
				else if (mapCharacter == static_cast<char>(symbols::ENTIO3)) {
					infoMap[i][j] = symbols::ENTIO3;
				}
				else if (mapCharacter == static_cast<char>(symbols::ENTIO4)) {
					infoMap[i][j] = symbols::ENTIO4;
				}
				else if (mapCharacter == static_cast<char>(symbols::ENTIO5)) {
					infoMap[i][j] = symbols::ENTIO5;
				}
				else if (mapCharacter == static_cast<char>(symbols::ENTIO6)) {
					infoMap[i][j] = symbols::ENTIO6;
				}

				else if (mapCharacter == static_cast<char>(symbols::ENTIOA)) {
					infoMap[i][j] = symbols::ENTIOA;
				}
				else if (mapCharacter == static_cast<char>(symbols::ENTIOB)) {
					infoMap[i][j] = symbols::ENTIOB;
				}
				else if (mapCharacter == static_cast<char>(symbols::ENTIOC)) {
					infoMap[i][j] = symbols::ENTIOC;
				}
				else if (mapCharacter == static_cast<char>(symbols::ENTIOD)) {
					infoMap[i][j] = symbols::ENTIOD;
				}
				else if (mapCharacter == static_cast<char>(symbols::ENTIOE)) {
					infoMap[i][j] = symbols::ENTIOE;
				}
				else if (mapCharacter == static_cast<char>(symbols::ENTIOF)) {
					infoMap[i][j] = symbols::ENTIOF;
				}
				else {
					infoMap[i][j] = symbols::EMPTY;
				}
			}
		}
	}
	file.close();//Finalmente, se cierra el archivo.
}

void Map::drawMap(bool _player1Torn, std::vector<Entio>&CurrentPlayer, int currentEntio) {
	//Dos variables que servirán para pintar a los entios del jugador actual de color amarillo.
	enti::Color playerA;
	enti::Color playerB;

	//Condición que comprueba cual es el jugador actual y le asigna a cada uno un color.
	if (_player1Torn) {
		playerA = enti::Color::YELLOW;
		playerB = enti::Color::WHITE;
	}
	else {
		playerA = enti::Color::WHITE;
		playerB = enti::Color::YELLOW;
	}

	//Bucles for anidados que recorrerán el mapa e irán imprimiéndolo en función de lo encontrado.
	for (int i = 0; i < dimensiones.filas; i++) {
		for (int j = 0; j < dimensiones.columnas; j++) {
			if (infoMap[i][j] == symbols::MONTAÑA && j < dimensiones.columnas-1) {
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
				if (CurrentPlayer[currentEntio].caracter == symbols::ENTIOA)
					enti::cout << enti::Color::LIGHTMAGENTA << static_cast<char>(infoMap[i][j]);
				else
					enti::cout << playerA << static_cast<char>(infoMap[i][j]);
				enti::cout << " ";
			}
			else if (infoMap[i][j] == symbols::ENTIOB) {
				if (CurrentPlayer[currentEntio].caracter == symbols::ENTIOB)
					enti::cout << enti::Color::LIGHTMAGENTA << static_cast<char>(infoMap[i][j]);
				else
					enti::cout << playerA << static_cast<char>(infoMap[i][j]);
				enti::cout << " ";
			}
			else if (infoMap[i][j] == symbols::ENTIOC) {
				if (CurrentPlayer[currentEntio].caracter == symbols::ENTIOC)
					enti::cout << enti::Color::LIGHTMAGENTA << static_cast<char>(infoMap[i][j]);
				else
					enti::cout << playerA << static_cast<char>(infoMap[i][j]);
				enti::cout << " ";
			}
			else if (infoMap[i][j] == symbols::ENTIOD) {
				if (CurrentPlayer[currentEntio].caracter == symbols::ENTIOD)
					enti::cout << enti::Color::LIGHTMAGENTA << static_cast<char>(infoMap[i][j]);
				else
					enti::cout << playerA << static_cast<char>(infoMap[i][j]);
				enti::cout << " ";
			}
			else if (infoMap[i][j] == symbols::ENTIOE) {
				if (CurrentPlayer[currentEntio].caracter == symbols::ENTIOE)
					enti::cout << enti::Color::LIGHTMAGENTA << static_cast<char>(infoMap[i][j]);
				else
					enti::cout << playerA << static_cast<char>(infoMap[i][j]);
				enti::cout << " ";
			}
			else if (infoMap[i][j] == symbols::ENTIOF) {
				if (CurrentPlayer[currentEntio].caracter == symbols::ENTIOF)
					enti::cout << enti::Color::LIGHTMAGENTA << static_cast<char>(infoMap[i][j]);
				else
					enti::cout << playerA << static_cast<char>(infoMap[i][j]);
				enti::cout << " ";
			}

			else if (infoMap[i][j] == symbols::ENTIO1) {
				if (CurrentPlayer[currentEntio].caracter == symbols::ENTIO1)
					enti::cout << enti::Color::LIGHTMAGENTA << static_cast<char>(infoMap[i][j]);
				else
					enti::cout << playerB << static_cast<char>(infoMap[i][j]);
				enti::cout << " ";
			}
			else if (infoMap[i][j] == symbols::ENTIO2) {
				if (CurrentPlayer[currentEntio].caracter == symbols::ENTIO2)
					enti::cout << enti::Color::LIGHTMAGENTA << static_cast<char>(infoMap[i][j]);
				else
					enti::cout << playerB << static_cast<char>(infoMap[i][j]);
				enti::cout << " ";
			}
			else if (infoMap[i][j] == symbols::ENTIO3) {
				if (CurrentPlayer[currentEntio].caracter == symbols::ENTIO3)
					enti::cout << enti::Color::LIGHTMAGENTA << static_cast<char>(infoMap[i][j]);
				else
					enti::cout << playerB << static_cast<char>(infoMap[i][j]);
				enti::cout << " ";
			}
			else if (infoMap[i][j] == symbols::ENTIO4) {
				if (CurrentPlayer[currentEntio].caracter == symbols::ENTIO4)
					enti::cout << enti::Color::LIGHTMAGENTA << static_cast<char>(infoMap[i][j]);
				else
					enti::cout << playerB << static_cast<char>(infoMap[i][j]);
				enti::cout << " ";
			}
			else if (infoMap[i][j] == symbols::ENTIO5) {
				if (CurrentPlayer[currentEntio].caracter == symbols::ENTIO5)
					enti::cout << enti::Color::LIGHTMAGENTA << static_cast<char>(infoMap[i][j]);
				else
					enti::cout << playerB << static_cast<char>(infoMap[i][j]);
				enti::cout << " ";
			}
			else if (infoMap[i][j] == symbols::ENTIO6) {
				if (CurrentPlayer[currentEntio].caracter == symbols::ENTIO6)
					enti::cout << enti::Color::LIGHTMAGENTA << static_cast<char>(infoMap[i][j]);
				else
					enti::cout << playerB << static_cast<char>(infoMap[i][j]);
				enti::cout << " ";
			}
		}
		enti::cout << enti::endl;
	}
}

void Map::drawHUD(int acciones, symbols entio, enti::InputKey & key, bool attack, bool sword, bool bow) {
	enti::cout << enti::endl;
	enti::cout << enti::Color::YELLOW << "Remaining movements: " << enti::Color::LIGHTCYAN << acciones << enti::endl;
	enti::cout << enti::Color::YELLOW << "Now moves character  " << enti::Color::LIGHTCYAN << static_cast<char>(entio) << enti::endl << enti::endl;
	if (acciones == 0) {
		enti::cout << enti::Color::LIGHTMAGENTA << "Press ENTER to end your turn!"<< enti::endl;
	}

	if (attack) {
		enti::cout << enti::Color::YELLOW << "Enter the weapon you want to choose:"<< enti::endl;
		enti::cout << enti::Color::YELLOW << "1 - SWORD"<< enti::endl;
		enti::cout << enti::Color::YELLOW << "2 - BOW" << enti::endl;
	}		
	if (sword || bow) {
		attack = false;
		enti::cout << enti::Color::YELLOW << "Enter the direction to attack:" << enti::endl;
		enti::cout << enti::Color::YELLOW << "1 - UP" << enti::endl;
		enti::cout << enti::Color::YELLOW << "2 - LEFT" << enti::endl;
		enti::cout << enti::Color::YELLOW << "3 - DOWN" << enti::endl;
		enti::cout << enti::Color::YELLOW << "4 - RIGHT" << enti::endl;
	}
	enti::cout << enti::cend;
}

symbols Map::posicion(const vector & location) {
	return infoMap[location.filas][location.columnas];
}

void Map::modificar(const vector & target, const symbols & value) {
	infoMap[target.filas][target.columnas] = value;
}

void Map::modificarPos(int & _row, int & _column, const symbols & value) {
	infoMap[_row][_column] = value;
}

symbols Map::guardarCaracter(int & _row, int & _column) {
	return infoMap[_row][_column];
}

Map::~Map() {
}


//CLASE PLAYER
Player::Player(Map * pCurrentMap, std::vector<Entio>&EntiosPlayerA, std::vector<Entio>&EntiosPlayerB) {
	CurrentMap = pCurrentMap;
	for (int i = 0; i < CurrentMap->dimensiones.filas; i++) {
		for (int j = 0; j < CurrentMap->dimensiones.columnas; j++) {
			if (CurrentMap->infoMap[i][j] == symbols::ENTIOA) {
				EntiosPlayerA.push_back(Entio());
				EntiosPlayerA[0].caracter = CurrentMap->infoMap[i][j];
				EntiosPlayerA[0].CurrentRow = i;
				EntiosPlayerA[0].CurrentCol = j;
			}
			else if (CurrentMap->infoMap[i][j] == symbols::ENTIOB) {
				EntiosPlayerA.push_back(Entio());
				EntiosPlayerA[1].caracter = CurrentMap->infoMap[i][j];
				EntiosPlayerA[1].CurrentRow = i;
				EntiosPlayerA[1].CurrentCol = j;
			}
			else if (CurrentMap->infoMap[i][j] == symbols::ENTIOC) {
				EntiosPlayerA.push_back(Entio());
				EntiosPlayerA[2].caracter = CurrentMap->infoMap[i][j];
				EntiosPlayerA[2].CurrentRow = i;
				EntiosPlayerA[2].CurrentCol = j;
			}
			else if (CurrentMap->infoMap[i][j] == symbols::ENTIOD) {
				EntiosPlayerA.push_back(Entio());
				EntiosPlayerA[3].caracter = CurrentMap->infoMap[i][j];
				EntiosPlayerA[3].CurrentRow = i;
				EntiosPlayerA[3].CurrentCol = j;
			}
			else if (CurrentMap->infoMap[i][j] == symbols::ENTIOE) {
				EntiosPlayerA.push_back(Entio());
				EntiosPlayerA[4].caracter = CurrentMap->infoMap[i][j];
				EntiosPlayerA[4].CurrentRow = i;
				EntiosPlayerA[4].CurrentCol = j;
			}
			else if (CurrentMap->infoMap[i][j] == symbols::ENTIOF) {
				EntiosPlayerA.push_back(Entio());
				EntiosPlayerA[5].caracter = CurrentMap->infoMap[i][j];
				EntiosPlayerA[5].CurrentRow = i;
				EntiosPlayerA[5].CurrentCol = j;
			}

			else if (CurrentMap->infoMap[i][j] == symbols::ENTIO1) {
				EntiosPlayerB.push_back(Entio());
				EntiosPlayerB[0].caracter = CurrentMap->infoMap[i][j];
				EntiosPlayerB[0].CurrentRow = i;
				EntiosPlayerB[0].CurrentCol = j;
			}
			else if (CurrentMap->infoMap[i][j] == symbols::ENTIO2) {
				EntiosPlayerB.push_back(Entio());
				EntiosPlayerB[1].caracter = CurrentMap->infoMap[i][j];
				EntiosPlayerB[1].CurrentRow = i;
				EntiosPlayerB[1].CurrentCol = j;
			}
			else if (CurrentMap->infoMap[i][j] == symbols::ENTIO3) {
				EntiosPlayerB.push_back(Entio());
				EntiosPlayerB[2].caracter = CurrentMap->infoMap[i][j];
				EntiosPlayerB[2].CurrentRow = i;
				EntiosPlayerB[2].CurrentCol = j;
			}
			else if (CurrentMap->infoMap[i][j] == symbols::ENTIO4) {
				EntiosPlayerB.push_back(Entio());
				EntiosPlayerB[3].caracter = CurrentMap->infoMap[i][j];
				EntiosPlayerB[3].CurrentRow = i;
				EntiosPlayerB[3].CurrentCol = j;
			}
			else if (CurrentMap->infoMap[i][j] == symbols::ENTIO5) {
				EntiosPlayerB.push_back(Entio());
				EntiosPlayerB[4].caracter = CurrentMap->infoMap[i][j];
				EntiosPlayerB[4].CurrentRow = i;
				EntiosPlayerB[4].CurrentCol = j;
			}
			else if (CurrentMap->infoMap[i][j] == symbols::ENTIO6) {
				EntiosPlayerB.push_back(Entio());
				EntiosPlayerB[5].caracter = CurrentMap->infoMap[i][j];
				EntiosPlayerB[5].CurrentRow = i;
				EntiosPlayerB[5].CurrentCol = j;
			}
		}
	}
}

bool Player::PlayerMovement(const enti::InputKey & key, std::vector<Entio>&CurrentPlayer, std::vector<Entio>&NextPlayer) {
	bool accionRealizada = false;
		if (key != enti::InputKey::ENTER) {
		if (CurrentPlayer[currentEntio].fatiga != 0) {
			CurrentMap->modificarPos(CurrentPlayer[currentEntio].CurrentRow, CurrentPlayer[currentEntio].CurrentCol, CurrentPlayer[currentEntio].nextPosition);
		}
		else {
			CurrentMap->modificarPos(CurrentPlayer[currentEntio].CurrentRow, CurrentPlayer[currentEntio].CurrentCol, symbols::TIERRA);
		}
	}

	if (key != enti::InputKey::NONE && acciones > 0) {
		if (key == enti::InputKey::ENTER) {
			CurrentPlayer[currentEntio].fatiga++;
			CurrentPlayer[currentEntio].hasmoved = false;
			if (currentEntio + 1 > 5) { currentEntio = 0; }
			else { currentEntio++; }
			accionRealizada = true;
		}
		else if (key == enti::InputKey::W || key == enti::InputKey::w) {
			if (CurrentMap->infoMap[CurrentPlayer[currentEntio].CurrentRow - 1][CurrentPlayer[currentEntio].CurrentCol] == symbols::TIERRA || CurrentMap->infoMap[CurrentPlayer[currentEntio].CurrentRow - 1][CurrentPlayer[currentEntio].CurrentCol] == symbols::BOSQUE) {
				CurrentPlayer[currentEntio].OldRow = CurrentPlayer[currentEntio].CurrentRow;
				CurrentPlayer[currentEntio].OldCol = CurrentPlayer[currentEntio].CurrentCol;
				CurrentPlayer[currentEntio].CurrentRow--;
				CurrentPlayer[currentEntio].fatiga++;
				CurrentPlayer[currentEntio].hasmoved = true;
				CurrentPlayer[currentEntio].nextPosition = CurrentMap->guardarCaracter(CurrentPlayer[currentEntio].CurrentRow, CurrentPlayer[currentEntio].CurrentCol);
				accionRealizada = true;
				attack = false;
				sword = false;
				bow = false;
			}
		}
		else if (key == enti::InputKey::A || key == enti::InputKey::a) {
			if (CurrentMap->infoMap[CurrentPlayer[currentEntio].CurrentRow][CurrentPlayer[currentEntio].CurrentCol - 1] == symbols::TIERRA || CurrentMap->infoMap[CurrentPlayer[currentEntio].CurrentRow][CurrentPlayer[currentEntio].CurrentCol - 1] == symbols::BOSQUE) {
				CurrentPlayer[currentEntio].OldRow = CurrentPlayer[currentEntio].CurrentRow;
				CurrentPlayer[currentEntio].OldCol = CurrentPlayer[currentEntio].CurrentCol;
				CurrentPlayer[currentEntio].CurrentCol--;
				CurrentPlayer[currentEntio].fatiga++;
				CurrentPlayer[currentEntio].hasmoved = true;
				CurrentPlayer[currentEntio].nextPosition = CurrentMap->guardarCaracter(CurrentPlayer[currentEntio].CurrentRow, CurrentPlayer[currentEntio].CurrentCol);
				accionRealizada = true;
				attack = false;
				sword = false;
				bow = false;
			}
		}
		else if (key == enti::InputKey::S || key == enti::InputKey::s) {
			if (CurrentMap->infoMap[CurrentPlayer[currentEntio].CurrentRow + 1][CurrentPlayer[currentEntio].CurrentCol] == symbols::TIERRA || CurrentMap->infoMap[CurrentPlayer[currentEntio].CurrentRow + 1][CurrentPlayer[currentEntio].CurrentCol] == symbols::BOSQUE) {
				CurrentPlayer[currentEntio].OldRow = CurrentPlayer[currentEntio].CurrentRow;
				CurrentPlayer[currentEntio].OldCol = CurrentPlayer[currentEntio].CurrentCol;
				CurrentPlayer[currentEntio].CurrentRow++;
				CurrentPlayer[currentEntio].fatiga++;
				CurrentPlayer[currentEntio].hasmoved = true;
				CurrentPlayer[currentEntio].nextPosition = CurrentMap->guardarCaracter(CurrentPlayer[currentEntio].CurrentRow, CurrentPlayer[currentEntio].CurrentCol);
				accionRealizada = true;
				attack = false;
				sword = false;
				bow = false;
			}
		}
		else if (key == enti::InputKey::D || key == enti::InputKey::d) {
			if (CurrentMap->infoMap[CurrentPlayer[currentEntio].CurrentRow][CurrentPlayer[currentEntio].CurrentCol + 1] == symbols::TIERRA || CurrentMap->infoMap[CurrentPlayer[currentEntio].CurrentRow][CurrentPlayer[currentEntio].CurrentCol + 1] == symbols::BOSQUE) {
				CurrentPlayer[currentEntio].OldRow = CurrentPlayer[currentEntio].CurrentRow;
				CurrentPlayer[currentEntio].OldCol = CurrentPlayer[currentEntio].CurrentCol;
				CurrentPlayer[currentEntio].CurrentCol++;
				CurrentPlayer[currentEntio].fatiga++;
				CurrentPlayer[currentEntio].hasmoved = true;
				CurrentPlayer[currentEntio].nextPosition = CurrentMap->guardarCaracter(CurrentPlayer[currentEntio].CurrentRow, CurrentPlayer[currentEntio].CurrentCol);
				accionRealizada = true;
				attack = false;
				sword = false;
				bow = false;
			}
		}	
		else if (key == enti::InputKey::Z || key == enti::InputKey::z) {
			if (attack == true || sword==true||bow==true){
				attack = false;
				sword = false;
				bow = false;
			}
			else {
				if (CurrentPlayer[currentEntio].hasmoved) {
					if (CurrentPlayer[currentEntio].CurrentRow != CurrentPlayer[currentEntio].OldRow || CurrentPlayer[currentEntio].CurrentCol != CurrentPlayer[currentEntio].OldCol && CurrentPlayer[currentEntio].hasmoved) {
						acciones++;
					}
					CurrentPlayer[currentEntio].CurrentRow = CurrentPlayer[currentEntio].OldRow;
					CurrentPlayer[currentEntio].CurrentCol = CurrentPlayer[currentEntio].OldCol;
				}
			}
		}
		else if (key == enti::InputKey::SPACEBAR) {
			attack = true;
		}
		
		if (attack) {
			if (key == enti::InputKey::NUM1) {
				sword = true;
				attack = false;
				if (sword) {
					enti::systemPause;
					if (key == enti::InputKey::NUM1) {
						if (CurrentMap->infoMap[CurrentPlayer[currentEntio].CurrentRow - 1][CurrentPlayer[currentEntio].CurrentCol] == NextPlayer[0].caracter) {
							NextPlayer.erase(NextPlayer.begin()+0);
							sword = false;
						}
						else {
							enti::cout << "you failed!";
							sword = false;
						}
					}
					else if (key == enti::InputKey::NUM2) {

					}
					else if (key == enti::InputKey::NUM3) {

					}
					else if (key == enti::InputKey::NUM4) {

					}
				}
			}
			else if (key == enti::InputKey::NUM2) {
				bow = true;
				attack = false;
			}
		}
		
		if (accionRealizada) { acciones--; }
	}


	CurrentMap->modificarPos(CurrentPlayer[currentEntio].CurrentRow, CurrentPlayer[currentEntio].CurrentCol, CurrentPlayer[currentEntio].caracter);


	if (acciones == 0 && key == enti::InputKey::ENTER) {
		acciones = 10;
		return true;
	}
	else {
		return false;
	}
}
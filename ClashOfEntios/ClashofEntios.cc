#include <iostream>
#include <string>
#include <fstream>
#include "ClashofEntios.hh"
#include "Renderer.hh"

int casillas;
int vidaquitada;


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
		playerB = enti::Color::LIGHTGRAY;
	}
	else {
		playerA = enti::Color::LIGHTGRAY;
		playerB = enti::Color::YELLOW;
	}

	//Bucles for anidados que recorrerán el mapa e irán imprimiéndolo en función de lo encontrado.
	//En caso de los entios, se pintará de color magenta aquel que se esté usando en ese momento.
	for (int i = 0; i < dimensiones.filas; i++) {
		for (int j = 0; j < dimensiones.columnas; j++) {
			if (infoMap[i][j] == symbols::MONTAÑA && j < dimensiones.columnas - 1) {
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

void Map::drawHUD(int acciones, int currentEntio, std::vector<Entio>&CurrentPlayer, std::vector<Entio>&NextPlayer, int &hit, bool &attack, bool &sword, bool &bow) {
	//Esta función imprimirá debajo del mapa los movimientos que le quedan al jugador, el entio que está moviendo, si ha finalizado
	//el turno, y le informará de cómo puede atacar cuando pulse espacio. También le informará del daño que le ha ausado al entio
	//enemigo y de si lo ha matado.
	enti::cout << enti::endl;
	enti::cout << enti::Color::YELLOW << "Remaining movements: " << enti::Color::LIGHTCYAN << acciones << enti::endl;
	enti::cout << enti::Color::YELLOW << "Now moves character  " << enti::Color::LIGHTCYAN << static_cast<char>(CurrentPlayer[currentEntio].caracter) << enti::endl << enti::endl;
	if (acciones == 0) {
		enti::cout << enti::Color::LIGHTMAGENTA << "Press ENTER to end your turn!" << enti::endl;
	}

	if (attack) {
		enti::cout << enti::Color::WHITE << "Enter the weapon you want to choose:" << enti::endl;
		enti::cout << enti::Color::YELLOW << "1 - SWORD" << enti::endl;
		enti::cout << enti::Color::YELLOW << "2 - BOW" << enti::endl;
	}

	if (sword || bow) {
		enti::cout << enti::Color::WHITE << "Enter the direction to attack:" << enti::endl;
		enti::cout << enti::Color::YELLOW << "1 - UP" << enti::endl;
		enti::cout << enti::Color::YELLOW << "2 - LEFT" << enti::endl;
		enti::cout << enti::Color::YELLOW << "3 - DOWN" << enti::endl;
		enti::cout << enti::Color::YELLOW << "4 - RIGHT" << enti::endl;
	}

	if (hit == 1) {
		enti::cout << enti::Color::WHITE << "You inflicted 10 damage to entio " << static_cast<char>(CurrentPlayer[currentEntio].villain) << enti::endl;
		enti::cout << enti::Color::LIGHTMAGENTA << "Entio " << static_cast<char>(CurrentPlayer[currentEntio].villain) << " killed!" << enti::endl;
		sword = false;
		bow = false;
	}
	else if(hit == 3){
		enti::cout << enti::Color::WHITE << "you failed!";
		sword = false;
		bow = false;
	}
	enti::cout << enti::cend;
}

void Map::modificarPos(int & _row, int & _column, const symbols & value) {
	//Esta función modifica el símbolo de la posicion indicada.
	infoMap[_row][_column] = value;
}

symbols Map::guardarCaracter(int & _row, int & _column) {
	//Esta función devuelve el símbolo que hay en la posición indicada.
	return infoMap[_row][_column];
}

Map::~Map() {
	//Destructor de la clase map.
	for (int i = 0; i < dimensiones.filas; i++) {
		delete[] this->infoMap[i];
	}
	delete[] this->infoMap;
}


//CLASE PLAYER
Player::Player(Map * pCurrentMap, std::vector<Entio>&EntiosPlayerA, std::vector<Entio>&EntiosPlayerB) {
	//el constructor de la clase player recorrerá el array de símbolos en busca de los carácteres que representan a
	//cada entio. Una vez encontrado, se le asignará a cada entio su símbolo correspondiente, una posición y será guardado en 
	//un vector, que cambiará en función del jugador al que le pertenezca el entio.
	CurrentMap = pCurrentMap;
	for (int i = 0; i < CurrentMap->dimensiones.filas; i++) {
		for (int j = 0; j < CurrentMap->dimensiones.columnas; j++) {
			if (CurrentMap->infoMap[i][j] == symbols::ENTIOA) {
				EntiosPlayerA.push_back(Entio());
				EntiosPlayerA[0].caracter = CurrentMap->infoMap[i][j];
				EntiosPlayerA[0].CurrentRow = i;
				EntiosPlayerA[0].CurrentCol = j;
				EntiosPlayerA[0].originRow = i;
				EntiosPlayerA[0].originCol = j;
				EntiosPlayerA[0].lastRow.push(EntiosPlayerA[0].CurrentRow);
				EntiosPlayerA[0].lastCol.push(EntiosPlayerA[0].CurrentCol);
			}
			else if (CurrentMap->infoMap[i][j] == symbols::ENTIOB) {
				EntiosPlayerA.push_back(Entio());
				EntiosPlayerA[1].caracter = CurrentMap->infoMap[i][j];
				EntiosPlayerA[1].CurrentRow = i;
				EntiosPlayerA[1].CurrentCol = j;
				EntiosPlayerA[1].originRow = i;
				EntiosPlayerA[1].originCol = j;
				EntiosPlayerA[1].lastRow.push(EntiosPlayerA[1].CurrentRow);
				EntiosPlayerA[1].lastCol.push(EntiosPlayerA[1].CurrentCol);
			}
			else if (CurrentMap->infoMap[i][j] == symbols::ENTIOC) {
				EntiosPlayerA.push_back(Entio());
				EntiosPlayerA[2].caracter = CurrentMap->infoMap[i][j];
				EntiosPlayerA[2].CurrentRow = i;
				EntiosPlayerA[2].CurrentCol = j;
				EntiosPlayerA[2].originRow = i;
				EntiosPlayerA[2].originCol = j;
				EntiosPlayerA[2].lastRow.push(EntiosPlayerA[2].CurrentRow);
				EntiosPlayerA[2].lastCol.push(EntiosPlayerA[2].CurrentCol);
			}
			else if (CurrentMap->infoMap[i][j] == symbols::ENTIOD) {
				EntiosPlayerA.push_back(Entio());
				EntiosPlayerA[3].caracter = CurrentMap->infoMap[i][j];
				EntiosPlayerA[3].CurrentRow = i;
				EntiosPlayerA[3].CurrentCol = j;
				EntiosPlayerA[3].originRow = i;
				EntiosPlayerA[3].originCol = j;
				EntiosPlayerA[3].lastRow.push(EntiosPlayerA[3].CurrentRow);
				EntiosPlayerA[3].lastCol.push(EntiosPlayerA[3].CurrentCol);
			}
			else if (CurrentMap->infoMap[i][j] == symbols::ENTIOE) {
				EntiosPlayerA.push_back(Entio());
				EntiosPlayerA[4].caracter = CurrentMap->infoMap[i][j];
				EntiosPlayerA[4].CurrentRow = i;
				EntiosPlayerA[4].CurrentCol = j;
				EntiosPlayerA[4].originRow = i;
				EntiosPlayerA[4].originCol = j;
				EntiosPlayerA[4].lastRow.push(EntiosPlayerA[4].CurrentRow);
				EntiosPlayerA[4].lastCol.push(EntiosPlayerA[4].CurrentCol);
			}
			else if (CurrentMap->infoMap[i][j] == symbols::ENTIOF) {
				EntiosPlayerA.push_back(Entio());
				EntiosPlayerA[5].caracter = CurrentMap->infoMap[i][j];
				EntiosPlayerA[5].CurrentRow = i;
				EntiosPlayerA[5].CurrentCol = j;
				EntiosPlayerA[5].originRow = i;
				EntiosPlayerA[5].originCol = j;
				EntiosPlayerA[5].lastRow.push(EntiosPlayerA[5].CurrentRow);
				EntiosPlayerA[5].lastCol.push(EntiosPlayerA[5].CurrentCol);
			}

			else if (CurrentMap->infoMap[i][j] == symbols::ENTIO1) {
				EntiosPlayerB.push_back(Entio());
				EntiosPlayerB[0].caracter = CurrentMap->infoMap[i][j];
				EntiosPlayerB[0].CurrentRow = i;
				EntiosPlayerB[0].CurrentCol = j;
				EntiosPlayerB[0].originRow = i;
				EntiosPlayerB[0].originCol = j;
				EntiosPlayerA[0].lastRow.push(EntiosPlayerA[0].CurrentRow);
				EntiosPlayerA[0].lastCol.push(EntiosPlayerA[0].CurrentCol);
			}
			else if (CurrentMap->infoMap[i][j] == symbols::ENTIO2) {
				EntiosPlayerB.push_back(Entio());
				EntiosPlayerB[1].caracter = CurrentMap->infoMap[i][j];
				EntiosPlayerB[1].CurrentRow = i;
				EntiosPlayerB[1].CurrentCol = j;
				EntiosPlayerB[1].originRow = i;
				EntiosPlayerB[1].originCol = j;
				EntiosPlayerA[1].lastRow.push(EntiosPlayerA[1].CurrentRow);
				EntiosPlayerA[1].lastCol.push(EntiosPlayerA[1].CurrentCol);
			}
			else if (CurrentMap->infoMap[i][j] == symbols::ENTIO3) {
				EntiosPlayerB.push_back(Entio());
				EntiosPlayerB[2].caracter = CurrentMap->infoMap[i][j];
				EntiosPlayerB[2].CurrentRow = i;
				EntiosPlayerB[2].CurrentCol = j;
				EntiosPlayerB[2].originRow = i;
				EntiosPlayerB[2].originCol = j;
				EntiosPlayerA[2].lastRow.push(EntiosPlayerA[2].CurrentRow);
				EntiosPlayerA[2].lastCol.push(EntiosPlayerA[2].CurrentCol);
			}
			else if (CurrentMap->infoMap[i][j] == symbols::ENTIO4) {
				EntiosPlayerB.push_back(Entio());
				EntiosPlayerB[3].caracter = CurrentMap->infoMap[i][j];
				EntiosPlayerB[3].CurrentRow = i;
				EntiosPlayerB[3].CurrentCol = j;
				EntiosPlayerB[3].originRow = i;
				EntiosPlayerB[3].originCol = j;
				EntiosPlayerA[3].lastRow.push(EntiosPlayerA[3].CurrentRow);
				EntiosPlayerA[3].lastCol.push(EntiosPlayerA[3].CurrentCol);
			}
			else if (CurrentMap->infoMap[i][j] == symbols::ENTIO5) {
				EntiosPlayerB.push_back(Entio());
				EntiosPlayerB[4].caracter = CurrentMap->infoMap[i][j];
				EntiosPlayerB[4].CurrentRow = i;
				EntiosPlayerB[4].CurrentCol = j;
				EntiosPlayerB[4].originRow = i;
				EntiosPlayerB[4].originCol = j;
				EntiosPlayerA[4].lastRow.push(EntiosPlayerA[4].CurrentRow);
				EntiosPlayerA[4].lastCol.push(EntiosPlayerA[4].CurrentCol);
			}
			else if (CurrentMap->infoMap[i][j] == symbols::ENTIO6) {
				EntiosPlayerB.push_back(Entio());
				EntiosPlayerB[5].caracter = CurrentMap->infoMap[i][j];
				EntiosPlayerB[5].CurrentRow = i;
				EntiosPlayerB[5].CurrentCol = j;
				EntiosPlayerB[5].originRow = i;
				EntiosPlayerB[5].originCol = j;
				EntiosPlayerA[5].lastRow.push(EntiosPlayerA[5].CurrentRow);
				EntiosPlayerA[5].lastCol.push(EntiosPlayerA[5].CurrentCol);
			}
		}
	}
}

int Player::arco(int casillas) {
	switch (casillas) {
	case 10:
		vidaquitada = 1;
		break;
	case 9:
		vidaquitada = 2;
		break;
	case 8:
		vidaquitada = 3;
		break;
	case 7:
		vidaquitada = 4;
		break;
	case 6:
		vidaquitada = 5;
		break;
	case 5:
		vidaquitada = 6;
		break;
	case 4:
		vidaquitada = 7;
		break;
	case 3:
		vidaquitada = 8;
		break;
	case 2:
		vidaquitada = 9;
		break;
	case 1:
		vidaquitada = 10;
		break;
	}
	return vidaquitada;
}

void Player::checkNextPlayerDie(std::vector<Entio>&NextPlayer) {
	for (int i = 0; i < NextPlayer.size(); i++) {
		if (NextPlayer[i].vida <= 0) {
			CurrentMap->modificarPos(NextPlayer[i].CurrentRow, NextPlayer[i].CurrentCol, NextPlayer[i].nextPosition);
			NextPlayer.erase(NextPlayer.begin() + i);
		}
	}
}

bool Player::PlayerMovement(enti::InputKey & key, std::vector<Entio>&CurrentPlayer, std::vector<Entio>&NextPlayer) {
	//Primero hacemos una declaración de variables. La primera será si se ha realizado alguna acción (inicialziada en false), 
	//y la segunda será un vector temporal que suaremos más adelante, y la tercera será el caracter del entio.
	bool accionRealizada = false;
	std::vector<Entio> tmp;
	symbols CheckEntio;

	//La primera condición será para pintar la posición anterior a la que se encontraba el jugador. Por eso solo tendremos en cuenta el movimiento,
	//y no si ha pulsado enter y la barra espaciadora.
	if (key != enti::InputKey::ENTER && key != enti::InputKey::SPACEBAR) {
		//Cuando se haya movido, pintaremos detras de él lo que había guardado en aquella posición. En el primer movimiento pintaremos tierra, y después
		//lo que hubiera en aquella posición.
		CurrentMap->modificarPos(CurrentPlayer[currentEntio].CurrentRow, CurrentPlayer[currentEntio].CurrentCol, CurrentPlayer[currentEntio].nextPosition);
	}

	//Ahora comprobaremos si el jugador ha realizado alguna acción.
	if (key != enti::InputKey::NONE && acciones > 0) {
		hit = 0;
		//El primer caso que tenemos es enter, es decir, si cambiará de entio.
		if (key == enti::InputKey::ENTER) {
			//En primer lugar, guardamos el caracter del entio actual en la variable creada anteriormente y le incrementamos la fatiga.
			CheckEntio = CurrentPlayer[currentEntio].caracter;
			CurrentPlayer[currentEntio].fatiga++;
			acciones--;
			//Después comprobaremos si el siguiente entio entra dentro del vector de entios que posee el jugador.
			if (currentEntio + 1 < CurrentPlayer.size()) {
				//En caso afirmativo, comprobaremos si la fatiga del siguiente entio es mayor a la del actual. Si es así, entrará en
				//un bucle que ordenará los entios por fatiga, y finalmente pasaremos a usar el entio de la primera posición, es decir,
				//el que está menos fatigado. De este modo nos aseguramos de que no se podrá acceder a entios de fatigas superiores
				//hasta que la del actual la iguale.
				if (CurrentPlayer[currentEntio + 1].fatiga > CurrentPlayer[currentEntio].fatiga) {
					for (int i = 1; i < CurrentPlayer.size(); i++) {
						for (int j = 0; j < CurrentPlayer.size() - 1; j++) {
							if (CurrentPlayer[j].fatiga > CurrentPlayer[j + 1].fatiga) {
								tmp.push_back(CurrentPlayer[j]);
								CurrentPlayer[j] = CurrentPlayer[j + 1];
								CurrentPlayer[j + 1] = tmp.back();
							}
						}
					}
					currentEntio = 0;
				}
				//En caso negativo, simplemente se accederá al siguiente entio del vector.
				else {
					currentEntio++;
				}
			}
			//En caso de que la siguiente posición se salga del vector, simplemente accederemos al primer entio de nuevo.
			//sin embargo, antes de eso comprobaremos si su fatiga es superior a la del último, y si es así, se ordenarán los entios por fatiga.
			else {
				if (CurrentPlayer[0].fatiga > CurrentPlayer[currentEntio].fatiga) {
					for (int i = 1; i < CurrentPlayer.size(); i++) {
						for (int j = 0; j < CurrentPlayer.size() - 1; j++) {
							if (CurrentPlayer[j].fatiga > CurrentPlayer[j + 1].fatiga) {
								tmp.push_back(CurrentPlayer[j]);
								CurrentPlayer[j] = CurrentPlayer[j + 1];
								CurrentPlayer[j + 1] = tmp.back();
							}
						}
					}
				}
				currentEntio = 0;
			}

			//En esta condición comprobamos si el entio actual es igual al anterior, lo cual significa que no ha cambiado de entio, 
			//con lo cual no se aumentará la fatiga ni las acciones disminuirán.
			if (CheckEntio == CurrentPlayer[currentEntio].caracter) {
				CurrentPlayer[currentEntio].fatiga--;
				acciones++;
			}
		}
		//A partir de ahora, el movimiento del jugador. 
		//En las cuatro direcciones es lo mismo. Se comprueba si en la siguiente casilla se puede caminar (Es decir, si es tierra o bosque),
		//y si se puede, guardaremos en un stack del propio entio la posición en la que se encontraba anteriormente, a continuación le cambiaremos
		//la posición, le aumentaremos la fatiga, guardaremos el caracter de la siguiente posición para poder pintarlo de nuevo la próxima vez que se mueva,
		//si ha realizado una acción pasará a true y los ataques a false.
		else if (key == enti::InputKey::W || key == enti::InputKey::w) {
			if (CurrentMap->infoMap[CurrentPlayer[currentEntio].CurrentRow - 1][CurrentPlayer[currentEntio].CurrentCol] == symbols::TIERRA || CurrentMap->infoMap[CurrentPlayer[currentEntio].CurrentRow - 1][CurrentPlayer[currentEntio].CurrentCol] == symbols::BOSQUE) {
				CurrentPlayer[currentEntio].lastRow.push(CurrentPlayer[currentEntio].CurrentRow);
				CurrentPlayer[currentEntio].lastCol.push(CurrentPlayer[currentEntio].CurrentCol);
				CurrentPlayer[currentEntio].CurrentRow--;
				CurrentPlayer[currentEntio].fatiga++;
				CurrentPlayer[currentEntio].nextPosition = CurrentMap->guardarCaracter(CurrentPlayer[currentEntio].CurrentRow, CurrentPlayer[currentEntio].CurrentCol);
				accionRealizada = true;
				attack = false;
				sword = false;
				bow = false;
			}
		}
		else if (key == enti::InputKey::A || key == enti::InputKey::a) {
			if (CurrentMap->infoMap[CurrentPlayer[currentEntio].CurrentRow][CurrentPlayer[currentEntio].CurrentCol - 1] == symbols::TIERRA || CurrentMap->infoMap[CurrentPlayer[currentEntio].CurrentRow][CurrentPlayer[currentEntio].CurrentCol - 1] == symbols::BOSQUE) {
				CurrentPlayer[currentEntio].lastRow.push(CurrentPlayer[currentEntio].CurrentRow);
				CurrentPlayer[currentEntio].lastCol.push(CurrentPlayer[currentEntio].CurrentCol);
				CurrentPlayer[currentEntio].CurrentCol--;
				CurrentPlayer[currentEntio].fatiga++;
				CurrentPlayer[currentEntio].nextPosition = CurrentMap->guardarCaracter(CurrentPlayer[currentEntio].CurrentRow, CurrentPlayer[currentEntio].CurrentCol);
				accionRealizada = true;
				attack = false;
				sword = false;
				bow = false;
			}
		}
		else if (key == enti::InputKey::S || key == enti::InputKey::s) {
			if (CurrentMap->infoMap[CurrentPlayer[currentEntio].CurrentRow + 1][CurrentPlayer[currentEntio].CurrentCol] == symbols::TIERRA || CurrentMap->infoMap[CurrentPlayer[currentEntio].CurrentRow + 1][CurrentPlayer[currentEntio].CurrentCol] == symbols::BOSQUE) {
				CurrentPlayer[currentEntio].lastRow.push(CurrentPlayer[currentEntio].CurrentRow);
				CurrentPlayer[currentEntio].lastCol.push(CurrentPlayer[currentEntio].CurrentCol);
				CurrentPlayer[currentEntio].CurrentRow++;
				CurrentPlayer[currentEntio].fatiga++;
				CurrentPlayer[currentEntio].nextPosition = CurrentMap->guardarCaracter(CurrentPlayer[currentEntio].CurrentRow, CurrentPlayer[currentEntio].CurrentCol);
				accionRealizada = true;
				attack = false;
				sword = false;
				bow = false;
			}
		}
		else if (key == enti::InputKey::D || key == enti::InputKey::d) {
			if (CurrentMap->infoMap[CurrentPlayer[currentEntio].CurrentRow][CurrentPlayer[currentEntio].CurrentCol + 1] == symbols::TIERRA || CurrentMap->infoMap[CurrentPlayer[currentEntio].CurrentRow][CurrentPlayer[currentEntio].CurrentCol + 1] == symbols::BOSQUE) {
				CurrentPlayer[currentEntio].lastRow.push(CurrentPlayer[currentEntio].CurrentRow);
				CurrentPlayer[currentEntio].lastCol.push(CurrentPlayer[currentEntio].CurrentCol);
				CurrentPlayer[currentEntio].CurrentCol++;
				CurrentPlayer[currentEntio].fatiga++;
				CurrentPlayer[currentEntio].nextPosition = CurrentMap->guardarCaracter(CurrentPlayer[currentEntio].CurrentRow, CurrentPlayer[currentEntio].CurrentCol);
				accionRealizada = true;
				attack = false;
				sword = false;
				bow = false;
			}
		}
		//Si el jugador pulsa Z y el entio estaba en proceso de ataque, se acabará el proceso.
		//Por otro lado, si en ese turno se ha movido, se le colocará en la anterior posición, la fatiga disminuirá, 
		//las acciones disponibles aumentarán y se quitará del stack la posición en la que se encuentra actualmente.
		else if (key == enti::InputKey::Z || key == enti::InputKey::z) {
			if (attack == true || sword == true || bow == true) {
				attack = false;
				sword = false;
				bow = false;
			}
			else if (CurrentPlayer[currentEntio].lastRow.size() > 0 && CurrentPlayer[currentEntio].lastCol.size() > 0) {
				if (CurrentPlayer[currentEntio].CurrentRow != CurrentPlayer[currentEntio].lastRow.top() || CurrentPlayer[currentEntio].CurrentCol != CurrentPlayer[currentEntio].lastCol.top()) {
					CurrentPlayer[currentEntio].CurrentRow = CurrentPlayer[currentEntio].lastRow.top();
					CurrentPlayer[currentEntio].CurrentCol = CurrentPlayer[currentEntio].lastCol.top();
					CurrentPlayer[currentEntio].lastCol.pop();
					CurrentPlayer[currentEntio].lastRow.pop();
					CurrentPlayer[currentEntio].fatiga--;
					acciones++;
				}
			}
		}
		//Si el jugador pulsa la barra espaciadora, el ataque pasará a true.
		else if (key == enti::InputKey::SPACEBAR) {
			attack = true;
		}
		//Si el ataque es true, le daremos a elegir entre espada y arco. Una vez elija una de las dos, el ataque
		//pasará a flase y la key a none, dado que si la dejáramos como estaba, realizaría instantáneamente un
		//ataque en el sentido y dirección al que correspondan los números 1 o 2. 
		if (attack) {
			if (key == enti::InputKey::NUM1) {
				key = enti::InputKey::NONE;
				sword = true;
				attack = false;
			}
			else if (key == enti::InputKey::NUM2) {
				key = enti::InputKey::NONE;
				bow = true;
				attack = false;
			}
		}
		if (bow) { //IMPORTANTE LAS FLECHAS NO RESPETAN LAS MONTAÑAS (SE TIENE QUE MODIFICAR)
			if (key == enti::InputKey::NUM1) {
				if (CurrentPlayer[currentEntio].flechas <= 10) {
					for (int i = 1; i < 10; i++) {
						if (CurrentMap->infoMap[CurrentPlayer[currentEntio].CurrentRow - i][CurrentPlayer[currentEntio].CurrentCol] == (NextPlayer[0].caracter)) {
							NextPlayer[0].vida - arco(i);
							checkNextPlayerDie(NextPlayer);
							break; // Para que no mate a todos los enemigos que haya en la linea de 10 casillas a lo metralleta
						}
						else if (CurrentMap->infoMap[CurrentPlayer[currentEntio].CurrentRow - i][CurrentPlayer[currentEntio].CurrentCol] == (NextPlayer[1].caracter)) {
							NextPlayer[1].vida - arco(i);
							checkNextPlayerDie(NextPlayer);
							break;
						}
						else if (CurrentMap->infoMap[CurrentPlayer[currentEntio].CurrentRow - i][CurrentPlayer[currentEntio].CurrentCol] == (NextPlayer[2].caracter)) {
							NextPlayer[2].vida - arco(i);
							checkNextPlayerDie(NextPlayer);
							break;
						}
						else if (CurrentMap->infoMap[CurrentPlayer[currentEntio].CurrentRow - i][CurrentPlayer[currentEntio].CurrentCol] == (NextPlayer[3].caracter)) {
							NextPlayer[3].vida - arco(i);
							checkNextPlayerDie(NextPlayer);
							break;
						}
						else if (CurrentMap->infoMap[CurrentPlayer[currentEntio].CurrentRow - i][CurrentPlayer[currentEntio].CurrentCol] == (NextPlayer[4].caracter)) {
							NextPlayer[4].vida - arco(i);
							checkNextPlayerDie(NextPlayer);
							break;
						}
						else if (CurrentMap->infoMap[CurrentPlayer[currentEntio].CurrentRow - i][CurrentPlayer[currentEntio].CurrentCol] == (NextPlayer[5].caracter)) {
							NextPlayer[5].vida - arco(i);
							checkNextPlayerDie(NextPlayer);
							break;
						} //Soc concient de que en comptes de repetir tot aixo per cada possible direcció del arc seria millor fer uyna funcio pero de momento ho deixo aixi
					}  //Tambe falta el cout<< You failed pero ara mateix no se on posarlo
				}
				else {
					enti::cout << "you failed!";
				}
			}
			else if (key == enti::InputKey::NUM2) {
				if (CurrentPlayer[currentEntio].flechas <= 10) {
					for (int i = 1; i < 10; i++) {
						if (CurrentMap->infoMap[CurrentPlayer[currentEntio].CurrentRow][CurrentPlayer[currentEntio].CurrentCol - i] == NextPlayer[0].caracter) {
							NextPlayer[0].vida - arco(i);
							checkNextPlayerDie(NextPlayer);
							break;
						}
						else if (CurrentMap->infoMap[CurrentPlayer[currentEntio].CurrentRow][CurrentPlayer[currentEntio].CurrentCol - i] == (NextPlayer[1].caracter)) {
							NextPlayer[1].vida - arco(i);
							checkNextPlayerDie(NextPlayer);
							break;
						}
						else if (CurrentMap->infoMap[CurrentPlayer[currentEntio].CurrentRow][CurrentPlayer[currentEntio].CurrentCol - i] == (NextPlayer[2].caracter)) {
							NextPlayer[2].vida - arco(i);
							checkNextPlayerDie(NextPlayer);
							break;
						}
						else if (CurrentMap->infoMap[CurrentPlayer[currentEntio].CurrentRow][CurrentPlayer[currentEntio].CurrentCol - i] == (NextPlayer[3].caracter)) {
							NextPlayer[3].vida - arco(i);
							checkNextPlayerDie(NextPlayer);
							break;
						}
						else if (CurrentMap->infoMap[CurrentPlayer[currentEntio].CurrentRow][CurrentPlayer[currentEntio].CurrentCol] == (NextPlayer[4].caracter)) {
							NextPlayer[4].vida - arco(i);
							checkNextPlayerDie(NextPlayer);
							break;
						}
						else if (CurrentMap->infoMap[CurrentPlayer[currentEntio].CurrentRow][CurrentPlayer[currentEntio].CurrentCol] == (NextPlayer[5].caracter)) {
							NextPlayer[5].vida - arco(i);
							checkNextPlayerDie(NextPlayer);
							break;
						}
					}
				}
				else {
					enti::cout << "you failed!";
				}
			}
			else if (key == enti::InputKey::NUM3) {
				if (CurrentPlayer[currentEntio].flechas <= 10) {
					for (int i = 1; i < 10; i++) {
						if (CurrentMap->infoMap[CurrentPlayer[currentEntio].CurrentRow + i][CurrentPlayer[currentEntio].CurrentCol] == (NextPlayer[0].caracter)) {
							NextPlayer[0].vida - arco(i);
							checkNextPlayerDie(NextPlayer);
							break;
						}
						else if (CurrentMap->infoMap[CurrentPlayer[currentEntio].CurrentRow + i][CurrentPlayer[currentEntio].CurrentCol] == (NextPlayer[1].caracter)) {
							NextPlayer[1].vida - arco(i);
							checkNextPlayerDie(NextPlayer);
							break;
						}
						else if (CurrentMap->infoMap[CurrentPlayer[currentEntio].CurrentRow + i][CurrentPlayer[currentEntio].CurrentCol] == (NextPlayer[2].caracter)) {
							NextPlayer[2].vida - arco(i);
							checkNextPlayerDie(NextPlayer);
							break;
						}
						else if (CurrentMap->infoMap[CurrentPlayer[currentEntio].CurrentRow + i][CurrentPlayer[currentEntio].CurrentCol] == (NextPlayer[3].caracter)) {
							NextPlayer[3].vida - arco(i);
							checkNextPlayerDie(NextPlayer);
							break;
						}
						else if (CurrentMap->infoMap[CurrentPlayer[currentEntio].CurrentRow + i][CurrentPlayer[currentEntio].CurrentCol] == (NextPlayer[4].caracter)) {
							NextPlayer[4].vida - arco(i);
							checkNextPlayerDie(NextPlayer);
							break;
						}
						else if (CurrentMap->infoMap[CurrentPlayer[currentEntio].CurrentRow + i][CurrentPlayer[currentEntio].CurrentCol] == (NextPlayer[5].caracter)) {
							NextPlayer[5].vida - arco(i);
							checkNextPlayerDie(NextPlayer);
							break;
						}
					}
				}
				else {
					enti::cout << "you failed!";
				}
			}
			else if (key == enti::InputKey::NUM4) {
				if (CurrentPlayer[currentEntio].flechas <= 10) {
					for (int i = 1; i < 10; i++) {
						if (CurrentMap->infoMap[CurrentPlayer[currentEntio].CurrentRow][CurrentPlayer[currentEntio].CurrentCol + i] == (NextPlayer[0].caracter)) {
							NextPlayer[0].vida - arco(i);
							checkNextPlayerDie(NextPlayer);
							break;
						}
						else if (CurrentMap->infoMap[CurrentPlayer[currentEntio].CurrentRow][CurrentPlayer[currentEntio].CurrentCol + i] == (NextPlayer[1].caracter)) {
							NextPlayer[1].vida - arco(i);
							checkNextPlayerDie(NextPlayer);
							break;
						}
						else if (CurrentMap->infoMap[CurrentPlayer[currentEntio].CurrentRow][CurrentPlayer[currentEntio].CurrentCol + i] == (NextPlayer[2].caracter)) {
							NextPlayer[2].vida - arco(i);
							checkNextPlayerDie(NextPlayer);
							break;
						}
						else if (CurrentMap->infoMap[CurrentPlayer[currentEntio].CurrentRow][CurrentPlayer[currentEntio].CurrentCol + i] == (NextPlayer[3].caracter)) {
							NextPlayer[3].vida - arco(i);
							checkNextPlayerDie(NextPlayer);
							break;
						}
						else if (CurrentMap->infoMap[CurrentPlayer[currentEntio].CurrentRow][CurrentPlayer[currentEntio].CurrentCol + i] == (NextPlayer[4].caracter)) {
							NextPlayer[4].vida - arco(i);
							checkNextPlayerDie(NextPlayer);
							break;
						}
						else if (CurrentMap->infoMap[CurrentPlayer[currentEntio].CurrentRow][CurrentPlayer[currentEntio].CurrentCol + i] == (NextPlayer[5].caracter)) {
							NextPlayer[5].vida - arco(i);
							checkNextPlayerDie(NextPlayer);
							break;
						}
					}
				}
				else {
					enti::cout << "you failed!";
				}
			}
			CurrentPlayer[currentEntio].flechas--;
		}
		//En caso de que el jugador haya elegido la espada, se le permitirá atacar en 4 direcciones.
		if (sword) {
			//Una vez ha elegido una, se comprobará si en esa posición hay un entio. En caso afirmativo, hit pasará a ser 1, es decir,
			//que ha asestado un golpe con la espada, se eliminará del vector de entios enemigos el entio al que se le ha atacado y se
			//pintará en su posición actual lo que tiene guardado (bosque o tierra).
			//En caso de qe no haya ningún entio, hit pasará a 3, es decir, que ha fallado.
			if (key == enti::InputKey::NUM1) {
				accionRealizada = true;
				for (int i = 0; i < NextPlayer.size(); i++) {
					if (CurrentMap->infoMap[CurrentPlayer[currentEntio].CurrentRow - 1][CurrentPlayer[currentEntio].CurrentCol] == NextPlayer[i].caracter) {
						hit = 1;
						CurrentPlayer[currentEntio].villain = NextPlayer[i].caracter;
						CurrentMap->modificarPos(NextPlayer[i].CurrentRow, NextPlayer[i].CurrentCol, NextPlayer[i].nextPosition);
						NextPlayer.erase(NextPlayer.begin() + i);
						break;
					}
					else {
						hit = 3;
					}
				}
			}
			else if (key == enti::InputKey::NUM2) {
				accionRealizada = true;
				for (int i = 0; i < NextPlayer.size(); i++) {
					if (CurrentMap->infoMap[CurrentPlayer[currentEntio].CurrentRow][CurrentPlayer[currentEntio].CurrentCol - 1] == NextPlayer[i].caracter) {
						hit = 1;
						CurrentPlayer[currentEntio].villain = NextPlayer[i].caracter;
						CurrentMap->modificarPos(NextPlayer[i].CurrentRow, NextPlayer[i].CurrentCol, NextPlayer[i].nextPosition);
						NextPlayer.erase(NextPlayer.begin() + i);
						break;
					}
					else {
						hit = 3;
					}
				}
			}
			else if (key == enti::InputKey::NUM3) {
				accionRealizada = true;
				for (int i = 0; i < NextPlayer.size(); i++) {
					if (CurrentMap->infoMap[CurrentPlayer[currentEntio].CurrentRow + 1][CurrentPlayer[currentEntio].CurrentCol] == NextPlayer[i].caracter) {
						hit = 1;
						CurrentPlayer[currentEntio].villain = NextPlayer[i].caracter;
						CurrentMap->modificarPos(NextPlayer[i].CurrentRow, NextPlayer[i].CurrentCol, NextPlayer[i].nextPosition);
						NextPlayer.erase(NextPlayer.begin() + i);
						break;
					}
					else {
						hit = 3;
					}
				}
			}
			else if (key == enti::InputKey::NUM4) {
				accionRealizada = true;
				for (int i = 0; i < NextPlayer.size(); i++) {
					if (CurrentMap->infoMap[CurrentPlayer[currentEntio].CurrentRow][CurrentPlayer[currentEntio].CurrentCol + 1] == NextPlayer[i].caracter) {
						hit = 1;
						CurrentPlayer[currentEntio].villain = NextPlayer[i].caracter;
						CurrentMap->modificarPos(NextPlayer[i].CurrentRow, NextPlayer[i].CurrentCol, NextPlayer[i].nextPosition);
						NextPlayer.erase(NextPlayer.begin() + i);
						break;
					}
					else {
						hit = 3;
					}
				}
			}
		}
	}
	//Cada vez que el jugador realice una acción, el booleano accionRealizada pasará a true. Si accionRealizada es true, se le descontará
	//una acción al jugador actual.
	if (accionRealizada) {
		acciones--;
	}

	//Al final, antes del return, se pintará en la posición deseada al entio actual en caso de que se haya movido.
	CurrentMap->modificarPos(CurrentPlayer[currentEntio].CurrentRow, CurrentPlayer[currentEntio].CurrentCol, CurrentPlayer[currentEntio].caracter);

	//Si el jugador se ha quedado sin acciones y pulsa enter, su turno acabará y devolverá true, lo cual producirá que se cambie de turno.
	//Si no, devolverá false.
	if (acciones == 0 && key == enti::InputKey::ENTER) {
		hit = 0;
		attack = false;
		sword = false;
		bow = false;
		acciones = 10;
		return true;
	}
	else {
		return false;
	}
}
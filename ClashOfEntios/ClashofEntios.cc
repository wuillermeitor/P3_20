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
	char mapCharacter;//variable que usaremos para guardar el caracter de una posici�n.

	if (file.is_open()) {
		//bucles for anidados que comprobar�n con cada car�cter del mapa cu�l es su s�mbolo,
		//y en funci�n de este, se guardar� en infoMap un s�mbolo u otro.
		infoMap = new symbols*[dimensiones.filas];
		for (int i = 0; i < dimensiones.filas; i++) {
			infoMap[i] = new symbols[dimensiones.columnas];
			for (int j = 0; j < dimensiones.columnas; j++) {
				file.get(mapCharacter);
				if (mapCharacter == static_cast<char>(symbols::MONTA�A)) {
					infoMap[i][j] = symbols::MONTA�A;
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
	//Dos variables que servir�n para pintar a los entios del jugador actual de color amarillo.
	enti::Color playerA;
	enti::Color playerB;

	//Condici�n que comprueba cual es el jugador actual y le asigna a cada uno un color.
	if (_player1Torn) {
		playerA = enti::Color::YELLOW;
		playerB = enti::Color::LIGHTGRAY;
	}
	else {
		playerA = enti::Color::LIGHTGRAY;
		playerB = enti::Color::YELLOW;
	}

	//Bucles for anidados que recorrer�n el mapa e ir�n imprimi�ndolo en funci�n de lo encontrado.
	//En caso de los entios, se pintar� de color magenta aquel que se est� usando en ese momento.
	for (int i = 0; i < dimensiones.filas; i++) {
		for (int j = 0; j < dimensiones.columnas; j++) {
			if (infoMap[i][j] == symbols::MONTA�A && j < dimensiones.columnas - 1) {
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
	//Esta funci�n imprimir� debajo del mapa los movimientos que le quedan al jugador, el entio que est� moviendo, si ha finalizado
	//el turno, y le informar� de c�mo puede atacar cuando pulse espacio. Tambi�n le informar� del da�o que le ha ausado al entio
	//enemigo y de si lo ha matado.
	int enemyentio = 0;
	for (int i = 0; i < NextPlayer.size(); i++) {
		if (NextPlayer[i].caracter == CurrentPlayer[currentEntio].villain) {
			enemyentio = i;
		}
	}
	enti::cout << enti::endl;
	enti::cout << enti::Color::YELLOW << "Remaining movements: " << enti::Color::LIGHTCYAN << acciones << enti::endl;
	enti::cout << enti::Color::YELLOW << "Now moves character  " << enti::Color::LIGHTCYAN << static_cast<char>(CurrentPlayer[currentEntio].caracter) << enti::endl << enti::endl;
	if (acciones == 0) {
		enti::cout << enti::Color::LIGHTMAGENTA << "Press ENTER to end your turn!" << enti::endl;
	}

	if (attack) {
		enti::cout << enti::Color::WHITE << "Enter the weapon you want to choose:" << enti::endl;
		enti::cout << enti::Color::YELLOW << "1 - SWORD" << enti::endl;
		enti::cout << enti::Color::YELLOW << "2 - BOW";
		if (CurrentPlayer[currentEntio].flechas == 0) {
			enti::cout << enti::Color::LIGHTRED << " (You have no more arrows left)" << enti::endl;
		}
	}

	if (sword) {
		enti::cout << enti::Color::WHITE << "Enter the direction to attack:" << enti::endl;
		enti::cout << enti::Color::YELLOW << "1 - UP" << enti::endl;
		enti::cout << enti::Color::YELLOW << "2 - LEFT" << enti::endl;
		enti::cout << enti::Color::YELLOW << "3 - DOWN" << enti::endl;
		enti::cout << enti::Color::YELLOW << "4 - RIGHT" << enti::endl;
	}
	if (bow && CurrentPlayer[currentEntio].flechas > 0) {
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
	}
	else if (hit == 2) {
		enti::cout << enti::Color::WHITE << "You inflicted " << CurrentPlayer[currentEntio].damageInflicted << " damage to entio " << static_cast<char>(NextPlayer[enemyentio].caracter) << enti::endl;
		if (NextPlayer[enemyentio].vida <= 0) {
			enti::cout << enti::Color::LIGHTMAGENTA << "Entio " << static_cast<char>(CurrentPlayer[currentEntio].villain) << " killed!" << enti::endl;
		}
		bow = false;
	}
	else if (hit == 3) {
		enti::cout << enti::Color::WHITE << "you failed!";
		sword = false;
		bow = false;
	}
	enti::cout << enti::cend;
}

void Map::modificarPos(int & _row, int & _column, const symbols & value) {
	//Esta funci�n modifica el s�mbolo de la posicion indicada.
	infoMap[_row][_column] = value;
}

symbols Map::guardarCaracter(int & _row, int & _column) {
	//Esta funci�n devuelve el s�mbolo que hay en la posici�n indicada.
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
	//el constructor de la clase player recorrer� el array de s�mbolos en busca de los car�cteres que representan a
	//cada entio. Una vez encontrado, se le asignar� a cada entio su s�mbolo correspondiente, una posici�n y ser� guardado en 
	//un vector, que cambiar� en funci�n del jugador al que le pertenezca el entio.
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
		return 1;
	case 9:
		return 2;
	case 8:
		return 3;
	case 7:
		return 4;
	case 6:
		return 5;
	case 5:
		return 6;
	case 4:
		return 7;
	case 3:
		return 8;
	}
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
	enti::cout << CurrentPlayer[currentEntio].vida << enti::endl;
	//Primero hacemos una declaraci�n de variables. La primera ser� si se ha realizado alguna acci�n (inicialziada en false), 
	//y la segunda ser� un vector temporal que suaremos m�s adelante, y la tercera ser� el caracter del entio.
	bool accionRealizada = false;
	std::vector<Entio> tmp;
	symbols CheckEntio;

	//La primera condici�n ser� para pintar la posici�n anterior a la que se encontraba el jugador. Por eso solo tendremos en cuenta el movimiento,
	//y no si ha pulsado enter y la barra espaciadora.
	if (key != enti::InputKey::ENTER && key != enti::InputKey::SPACEBAR) {
		//Cuando se haya movido, pintaremos detras de �l lo que hab�a guardado en aquella posici�n. En el primer movimiento pintaremos tierra, y despu�s
		//lo que hubiera en aquella posici�n.
		CurrentMap->modificarPos(CurrentPlayer[currentEntio].CurrentRow, CurrentPlayer[currentEntio].CurrentCol, CurrentPlayer[currentEntio].nextPosition);
	}

	//Ahora comprobaremos si el jugador ha realizado alguna acci�n.
	if (key != enti::InputKey::NONE && acciones > 0) {
		hit = 0;
		//El primer caso que tenemos es enter, es decir, si cambiar� de entio.
		if (key == enti::InputKey::ENTER) {
			//En primer lugar, guardamos el caracter del entio actual en la variable creada anteriormente y le incrementamos la fatiga.
			CheckEntio = CurrentPlayer[currentEntio].caracter;
			CurrentPlayer[currentEntio].fatiga++;
			acciones--;
			//Despu�s comprobaremos si el siguiente entio entra dentro del vector de entios que posee el jugador.
			if (currentEntio + 1 < CurrentPlayer.size()) {
				//En caso afirmativo, comprobaremos si la fatiga del siguiente entio es mayor a la del actual. Si es as�, entrar� en
				//un bucle que ordenar� los entios por fatiga, y finalmente pasaremos a usar el entio de la primera posici�n, es decir,
				//el que est� menos fatigado. De este modo nos aseguramos de que no se podr� acceder a entios de fatigas superiores
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
				//En caso negativo, simplemente se acceder� al siguiente entio del vector.
				else {
					currentEntio++;
				}
			}
			//En caso de que la siguiente posici�n se salga del vector, simplemente accederemos al primer entio de nuevo.
			//sin embargo, antes de eso comprobaremos si su fatiga es superior a la del �ltimo, y si es as�, se ordenar�n los entios por fatiga.
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

			//En esta condici�n comprobamos si el entio actual es igual al anterior, lo cual significa que no ha cambiado de entio, 
			//con lo cual no se aumentar� la fatiga ni las acciones disminuir�n.
			if (CheckEntio == CurrentPlayer[currentEntio].caracter) {
				CurrentPlayer[currentEntio].fatiga--;
				acciones++;
			}
		}
		//A partir de ahora, el movimiento del jugador. 
		//En las cuatro direcciones es lo mismo. Se comprueba si en la siguiente casilla se puede caminar (Es decir, si es tierra o bosque),
		//y si se puede, guardaremos en un stack del propio entio la posici�n en la que se encontraba anteriormente, a continuaci�n le cambiaremos
		//la posici�n, le aumentaremos la fatiga, guardaremos el caracter de la siguiente posici�n para poder pintarlo de nuevo la pr�xima vez que se mueva,
		//si ha realizado una acci�n pasar� a true y los ataques a false.
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
		//Si el jugador pulsa Z y el entio estaba en proceso de ataque, se acabar� el proceso.
		//Por otro lado, si en ese turno se ha movido, se le colocar� en la anterior posici�n, la fatiga disminuir�, 
		//las acciones disponibles aumentar�n y se quitar� del stack la posici�n en la que se encuentra actualmente.
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
		//Si el jugador pulsa la barra espaciadora, el ataque pasar� a true.
		else if (key == enti::InputKey::SPACEBAR) {
			attack = true;
			sword = false;
			bow = false;
		}
		//Si el ataque es true, le daremos a elegir entre espada y arco. Una vez elija una de las dos, el ataque
		//pasar� a flase y la key a none, dado que si la dej�ramos como estaba, realizar�a instant�neamente un
		//ataque en el sentido y direcci�n al que correspondan los n�meros 1 o 2. 
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
		if (bow) {
			if (CurrentPlayer[currentEntio].flechas > 0) {
				if (key == enti::InputKey::NUM1) {
					for (int i = 3; i <= 10; i++) {
						for (int entios = 0; entios < NextPlayer.size(); entios++) {
							if (CurrentMap->infoMap[CurrentPlayer[currentEntio].CurrentRow - i][CurrentPlayer[currentEntio].CurrentCol] == (NextPlayer[entios].caracter)) {
								hit = 2;
								CurrentPlayer[currentEntio].villain = NextPlayer[entios].caracter;
								NextPlayer[entios].vida -= arco(i);
								CurrentPlayer[currentEntio].damageInflicted = arco(i);
								break;
							}
							else if (CurrentMap->infoMap[CurrentPlayer[currentEntio].CurrentRow - i][CurrentPlayer[currentEntio].CurrentCol] == symbols::MONTA�A) {
								hit = 3;
								break;
							}
						}
					}
					if (hit != 2) {
						hit = 3;
					}
					accionRealizada = true;
					CurrentPlayer[currentEntio].flechas--;
				}
				if (key == enti::InputKey::NUM2) {
					for (int i = 3; i <= 10; i++) {
						for (int entios = 0; entios < NextPlayer.size(); entios++) {
							if (CurrentMap->infoMap[CurrentPlayer[currentEntio].CurrentRow][CurrentPlayer[currentEntio].CurrentCol - i] == (NextPlayer[entios].caracter)) {
								hit = 2;
								CurrentPlayer[currentEntio].villain = NextPlayer[entios].caracter;
								NextPlayer[entios].vida -= arco(i);
								CurrentPlayer[currentEntio].damageInflicted = arco(i);
								checkNextPlayerDie(NextPlayer);
								break;
							}
							else if (CurrentMap->infoMap[CurrentPlayer[currentEntio].CurrentRow][CurrentPlayer[currentEntio].CurrentCol - i] == symbols::MONTA�A) {
								hit = 3;
								break;
							}
						}
					}
					if (hit != 2) {
						hit = 3;
					}
					accionRealizada = true;
					CurrentPlayer[currentEntio].flechas--;
				}
				if (key == enti::InputKey::NUM3) {
					for (int i = 3; i <= 10; i++) {
						for (int entios = 0; entios < NextPlayer.size(); entios++) {
							if (CurrentMap->infoMap[CurrentPlayer[currentEntio].CurrentRow + i][CurrentPlayer[currentEntio].CurrentCol] == (NextPlayer[entios].caracter)) {
								hit = 2;
								CurrentPlayer[currentEntio].villain = NextPlayer[entios].caracter;
								NextPlayer[entios].vida -= arco(i);
								CurrentPlayer[currentEntio].damageInflicted = arco(i);
								checkNextPlayerDie(NextPlayer);
								break;
							}
							else if (CurrentMap->infoMap[CurrentPlayer[currentEntio].CurrentRow + i][CurrentPlayer[currentEntio].CurrentCol] == symbols::MONTA�A) {
								hit = 3;
								break;
							}
						}
					}
					if (hit != 2) {
						hit = 3;
					}
					accionRealizada = true;
					CurrentPlayer[currentEntio].flechas--;
				}
				if (key == enti::InputKey::NUM4) {
					for (int i = 3; i <= 10; i++) {
						for (int entios = 0; entios < NextPlayer.size(); entios++) {
							if (CurrentMap->infoMap[CurrentPlayer[currentEntio].CurrentRow][CurrentPlayer[currentEntio].CurrentCol + i] == (NextPlayer[entios].caracter)) {
								hit = 2;
								CurrentPlayer[currentEntio].villain = NextPlayer[entios].caracter;
								NextPlayer[entios].vida -= arco(i);
								CurrentPlayer[currentEntio].damageInflicted = arco(i);
								checkNextPlayerDie(NextPlayer);
								break;
							}
							else if (CurrentMap->infoMap[CurrentPlayer[currentEntio].CurrentRow][CurrentPlayer[currentEntio].CurrentCol + i] == symbols::MONTA�A) {
								hit = 3;
								break;
							}
						}
					}
					if (hit != 2) {
						hit = 3;
					}
					accionRealizada = true;
					CurrentPlayer[currentEntio].flechas--;
				}
			}
		}
		//En caso de que el jugador haya elegido la espada, se le permitir� atacar en 4 direcciones.
		if (sword) {
			//Una vez ha elegido una, se comprobar� si en esa posici�n hay un entio. En caso afirmativo, hit pasar� a ser 1, es decir,
			//que ha asestado un golpe con la espada, se eliminar� del vector de entios enemigos el entio al que se le ha atacado y se
			//pintar� en su posici�n actual lo que tiene guardado (bosque o tierra).
			//En caso de qe no haya ning�n entio, hit pasar� a 3, es decir, que ha fallado.
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
	//Cada vez que el jugador realice una acci�n, el booleano accionRealizada pasar� a true. Si accionRealizada es true, se le descontar�
	//una acci�n al jugador actual.
	if (accionRealizada) {
		acciones--;
	}

	//Al final, antes del return, se pintar� en la posici�n deseada al entio actual en caso de que se haya movido.
	CurrentMap->modificarPos(CurrentPlayer[currentEntio].CurrentRow, CurrentPlayer[currentEntio].CurrentCol, CurrentPlayer[currentEntio].caracter);

	//Si el jugador se ha quedado sin acciones y pulsa enter, su turno acabar� y devolver� true, lo cual producir� que se cambie de turno.
	//Si no, devolver� false.
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
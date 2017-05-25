#pragma once
#include <fstream>
#include <iostream>
#include "Input.inl.hh"
#include <conio.h>
#include <vector>

struct vector {
	int filas = 36, columnas = 74;
};

enum class symbols :char {
	MONTAÑA = 'X', AGUA = 'O', 
	BOSQUE = ':', TIERRA = '.',

	ENTIO1 = '1', ENTIO2 = '2', ENTIO3 = '3',
	ENTIO4 = '4', ENTIO5 = '5', ENTIO6 = '6',

	ENTIOA = 'A', ENTIOB = 'B', ENTIOC = 'C',
	ENTIOD = 'D', ENTIOE = 'E', ENTIOF = 'F',

	EMPTY = ' '
};

struct Entio {
	symbols caracter;
	int CurrentRow;
	int CurrentCol;
	int vida = 10;
	int fatiga = 0;
	int flechas = 10;
};


class Map {
	friend class Player;
public:
	void ReadMap(std::ifstream &file, std::string filename);
	void drawMap(bool _player1Torn);//método que crea el mapa.
	symbols posicion(const vector & location);
	void modificar(const vector & target, const symbols & value);//método que modifica una posición del mapa.
	void modificarPos(int & _row, int & _column, const symbols & value);//método que modifica una posición del mapa.
	~Map();//destructor del Map.
private:
	vector dimensiones;
	symbols**infoMap;
};


class Player {
	friend class Map;
public:
	Player(Map * pCurrentMap, std::vector<Entio>&EntiosPlayerA, std::vector<Entio>&EntiosPlayerB);
	bool PlayerMovement(const enti::InputKey & key, std::vector<Entio>&CurrentPlayer);//método que permite al jugador moverse.
	vector getPos();
	int acciones = 10;


private:
	Map * CurrentMap;
	int currentEntio = 0;
};








/*
class Map {
public:
	//Métodos

	Map(int _rows, int _columns);
	void readMap(std::ifstream &file, std::string filename);
	void drawMap();
	~Map();

	//Atributos
	int row;
	int column;
	char**map;
};

class Player {
public:
	//Métodos
	Player(int posx, int posy, Map &mapa);
	void PlayerMovement(const enti::InputKey & key, int posx, int posy, int entioactual);
	~Player();

	//Atributos
	Map &map;
	int newx, newy;
	int currentx, currenty;
	int alifeEntios;

	std::priority_queue<int> entiosPlayerA;
	std::priority_queue<int> entiosPlayerB;
};

class Entio {
public:
	//Métodos
	Entio(char identificador, int x, int y);
	~Entio();

	//Atributos
	char entio;
	int posx, posy;
	int vida;
	int fatiga;
	int flechas;
};
*/
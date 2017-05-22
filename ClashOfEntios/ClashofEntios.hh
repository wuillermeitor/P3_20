#pragma once
#include <fstream>
#include <iostream>
#include "Input.inl.hh"
#include <conio.h>
#include <queue>

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
	Player(int posx, int posy, Map &mapa);
	void PlayerMovement(int posx, int posy, int entioactual);
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
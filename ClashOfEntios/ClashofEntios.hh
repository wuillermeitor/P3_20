#pragma once
#include <fstream>
#include <iostream>
#include "Input.inl.hh"
#include <conio.h>
#include <vector>
#include <queue>

//struct de las coordenadas del mapa.
struct vector {
	int filas = 36, columnas = 74;
};

//enum con todos los símbolos del juego
enum class symbols :char {
	MONTAÑA = 'X', AGUA = 'O', 
	BOSQUE = ':', TIERRA = '.',

	ENTIO1 = '1', ENTIO2 = '2', ENTIO3 = '3',
	ENTIO4 = '4', ENTIO5 = '5', ENTIO6 = '6',

	ENTIOA = 'A', ENTIOB = 'B', ENTIOC = 'C',
	ENTIOD = 'D', ENTIOE = 'E', ENTIOF = 'F',

	EMPTY = ' '
};

//struct de los entios
struct Entio {
	symbols caracter;
	symbols nextPosition;
	bool hasmoved = false;
	int CurrentRow;
	int CurrentCol;
	int OldRow;
	int OldCol;
	int vida = 10;
	int fatiga = 0;
	int flechas = 10;
};


class Map {
	friend class Player;//esto nos permitirá acceder a parámetros de la clase Player
public:
	//Métodos de la clase
	void ReadMap(std::ifstream &file, std::string filename);//método que lee el mapa del archivo default.cfg
	void drawMap(bool _player1Torn, std::vector<Entio>&CurrentPlayer, int currentEntio);//método que dibujará el mapa en función de lo leído con el anterior método.
	void drawHUD(int acciones, symbols entio, enti::InputKey & key, bool attack, bool sword, bool bow);
	symbols posicion(const vector & location);//Método que devuelve el símbolo de la posición indicada
	void modificar(const vector & target, const symbols & value);//método que modifica una posición del mapa en función del struct vector.
	void modificarPos(int & _row, int & _column, const symbols & value);//método que modifica una posición del mapa en función de dos parámetros.
	symbols guardarCaracter(int & _row, int & _column);
	~Map();//destructor de la clase Map.
private:
	//Atributos de la clase
	vector dimensiones;
	symbols**infoMap;
	Player *player;
};


class Player {
	friend class Map;//esto nos permitirá acceder a parámetros de la clase Map
public:
	//Métodos
	Player(Map * pCurrentMap, std::vector<Entio>&EntiosPlayerA, std::vector<Entio>&EntiosPlayerB);//constructor de la clase player.
	bool PlayerMovement(const enti::InputKey & key, std::vector<Entio>&CurrentPlayer, std::vector<Entio>&NextPlayer);//método que permite al jugador moverse, así como cambiar
	//de entio y de jugador (en función de lo que devuelva el método).
	vector getPos();
	//Atributos
	int acciones = 10;
	int currentEntio = 0;
	bool player1torn = true;
	bool attack = false;
	bool bow = false;
	bool sword = false;
private:
	Map * CurrentMap;
};

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

//enum con todos los s�mbolos del juego
enum class symbols :char {
	MONTA�A = 'X', AGUA = 'O', 
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
	int CurrentRow;
	int CurrentCol;
	int OldRow;
	int OldCol;
	int vida = 10;
	int fatiga = 0;
	int flechas = 10;
};


class Map {
	friend class Player;//esto nos permitir� acceder a par�metros de la clase Player
public:
	//M�todos de la clase
	void ReadMap(std::ifstream &file, std::string filename);//m�todo que lee el mapa del archivo default.cfg
	void drawMap(bool _player1Torn);//m�todo que dibujar� el mapa en funci�n de lo le�do con el anterior m�todo.
	symbols posicion(const vector & location);//M�todo que devuelve el s�mbolo de la posici�n indicada
	void modificar(const vector & target, const symbols & value);//m�todo que modifica una posici�n del mapa en funci�n del struct vector.
	void modificarPos(int & _row, int & _column, const symbols & value);//m�todo que modifica una posici�n del mapa en funci�n de dos par�metros.
	symbols guardarCaracter(int & _row, int & _column);
	~Map();//destructor de la clase Map.
private:
	//Atributos de la clase
	vector dimensiones;
	symbols**infoMap;
};


class Player {
	friend class Map;//esto nos permitir� acceder a par�metros de la clase Map
public:
	//M�todos
	Player(Map * pCurrentMap, std::vector<Entio>&EntiosPlayerA, std::vector<Entio>&EntiosPlayerB);//constructor de la clase player.
	bool PlayerMovement(const enti::InputKey & key, std::vector<Entio>&CurrentPlayer);//m�todo que permite al jugador moverse, as� como cambiar
	//de entio y de jugador (en funci�n de lo que devuelva el m�todo).
	vector getPos();
	//Atributos
	int acciones = 10;
	int currentEntio = 0;
private:
	Map * CurrentMap;
};

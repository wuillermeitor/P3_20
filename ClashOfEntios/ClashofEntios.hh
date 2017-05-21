#pragma once
#include <fstream>
#include <iostream>
#include "Input.inl.hh"

class Map {
public:
	Map(int _rows, int _columns);
	void readMap(std::ifstream &file, std::string filename);
	void drawMap();
	~Map();
private:
	int row;
	int column;
	char**map;
};

class Player {
public:
	Player();
	void PlayerMovement();
	~Player();
};
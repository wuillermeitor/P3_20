#pragma once
#include <fstream>
#include <iostream>

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

};
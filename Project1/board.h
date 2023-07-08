#pragma once
#include "square.h"
#include "face.h"

class Board
{
public:
	Board(int x, int y, double p);
	~Board();
	int x;
	std::vector<std::vector<Square*>> board;
	void print(std::vector<std::vector<Square*>>);
	bool generateRandomBool(double probability);
	Face* face;	
	void renderBoard(sf::RenderWindow* window);
	void renderFace(sf::RenderWindow* window);
};


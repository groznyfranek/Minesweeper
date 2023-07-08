#include "board.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

Board::Board(int x, int y, double p)
{
	std::cout << x << "x" << y << " Board created\n";	
	srand(time(0));
	for (int i = 0; i < x; ++i)
	{
		std::vector<Square*> vec;
		for (int j = 0; j < y; ++j)
		{
			Square* s = new Square(generateRandomBool(p), i * 30, j * 30);
			vec.push_back(s);
		}
		board.push_back(vec);
	}
	this->x = x;
	face = new Face(x, y);
	print(board);
}

void Board::renderFace(sf::RenderWindow* window)
{
	window->draw(*(face->sprite));
}

void Board::renderBoard(sf::RenderWindow* window)
{	
	for (auto& element : board)
	{
		for(auto& el : element) window->draw(*(el->sprite));
	}	
}

bool Board::generateRandomBool(double probability)
{	
	double randomValue = static_cast<double>(rand()) / RAND_MAX;
	return randomValue < probability;
}
void Board::print(std::vector<std::vector<Square*>> vec)
{
	int x = vec.size();
	for (int i = 0; i < x; ++i)
	{		
		for (int j = 0; j < x; ++j)
		{
			std::cout << vec[j][i]->bomb<< " ";
		}
		std::cout << std::endl;
	}
}
Board::~Board()
{
	std::cout << "Board erased\n";
}
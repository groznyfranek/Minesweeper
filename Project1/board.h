#pragma once
#include "square.h"
#include "face.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <queue>
#include <ctime>

class Board
{
public:
	Board(int x, int y, double p, sf::RenderWindow* w);
	~Board();
	int x,y;
	int bombs;
	sf::RenderWindow* window;
	std::vector<std::vector<Square*>> board;
	std::vector<std::vector<Square*>> families;
	Face* face;
	void clickSquare(Square* s, sf::RenderWindow* window, const sf::Event& event);
	void print(std::vector<std::vector<Square*>>);			
	void renderBoard(sf::RenderWindow* window);
	void renderFace(sf::RenderWindow* window);
	void squareReveal(Square* s, sf::RenderWindow* window);
	void revealNotBomb(Square* s, const int& count);
	void showFamilies();
	bool generateRandomBool(double probability);
};
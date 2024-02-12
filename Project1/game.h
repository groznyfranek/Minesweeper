#pragma once
#include "board.h"
#include <thread>
#include <chrono>
#include <windows.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <SFML/Graphics.hpp>

class Game
{
public:
	Game(int x, int y, double p);
	~Game();
	int time;
	int score;
	Board* board;
	sf::RenderWindow* window;	
	sf::Text textScore;
	sf::Text textClock;
	sf::Font font;
	sf::Clock clock;
	std::string labelScore;
	std::string labelClock;
	void run();
	void labels();
	void handleClicks(const sf::Event& event);
	void win();
	void lose();
	void render();
	
};


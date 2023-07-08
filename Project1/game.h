#pragma once
#include "board.h"
class Game
{
public:
	Game(int x, int y, double p);
	~Game();
	Board* board;
	sf::RenderWindow* window;
	int time;
	int score;
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


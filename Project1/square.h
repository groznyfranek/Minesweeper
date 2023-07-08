#pragma once
#include <SFML/Graphics.hpp>
#include "button.h"

class Square :public Button
{
public:
	Square(bool s, int x, int y);
	~Square();
	int x;
	int y;
	void click(sf::RenderWindow* window, const sf::Event& event, std::vector<std::vector<Square*>> board);
	int check(std::vector<std::vector<Square*>>& board);
	bool isValid(int row, int col, std::vector<std::vector<Square*>>& board);
	bool bomb;
	enum class Status { DEF, CLICKED, FLAGGED, EXPLODED };
	Status status;
	void winPro();
	void losePro();
	void changeTexture(const std::string& name);
};


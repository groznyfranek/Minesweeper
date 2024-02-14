#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "button.h"

class Square :public Button
{
public:
	Square(bool s, int x, int y);
	~Square();
	int x;
	int y;	
	enum class Status { DEF, CLICKED, FLAGGED, EXPLODED };
	Status status;
	bool bomb;
	int check(std::vector<std::vector<Square*>>& board);
	bool isValid(int row, int col, std::vector<std::vector<Square*>>& board);	
	void losePro();
	void changeTexture(const std::string& name);
};
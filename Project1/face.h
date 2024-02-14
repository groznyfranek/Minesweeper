#pragma once
#include "button.h"
#include <iostream>
#include <SFML/Graphics.hpp>

class Face :public Button 
{
public:
	Face(int x, int y);
	~Face();
	enum class Status { DEF, DEAD, O, WIN};
	Status status;
	void click(sf::RenderWindow* window, const sf::Event& event);	
	void setO();
	void setDef();
	void setDead();
	void setWin();	
};


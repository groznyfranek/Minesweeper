#pragma once
#include "button.h"

class Face :public Button 
{
public:
	Face(int x, int y);
	void click(sf::RenderWindow* window, const sf::Event& event);
	~Face();
	void setO();
	void setDef();
	void setDead();
	void setWin();
	enum class Status { DEF, DEAD, O, WIN};
	Status status;
};


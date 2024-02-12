#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Button
{
public:
	Button();
	~Button();
	sf::Texture* texture;
	sf::Sprite* sprite;
};


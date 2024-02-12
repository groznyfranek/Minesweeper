#include "face.h"

Face::Face(int x, int y)
{
	std::cout << "The face has been created\n";
    texture = new sf::Texture;
	if (!texture->loadFromFile("img/smiled.png"))
	{
		std::cout << "Failed to load texture\n";
	}
	sprite = new sf::Sprite(*texture);
	sprite->setScale(1, 1);
	sprite->setPosition((15 * x) - 32, y + 10);
    status = Status::DEF;
}

void Face::click(sf::RenderWindow* window, const sf::Event& event)
{
    if (event.type == sf::Event::MouseButtonPressed)
    {
        if (event.mouseButton.button == sf::Mouse::Left)
        {
            sf::Vector2i mousePos = sf::Mouse::getPosition(*window);
            sf::Vector2f worldPos = window->mapPixelToCoords(mousePos);
            if (sprite->getGlobalBounds().contains(worldPos))
            {
                setO();
            }
        }
    }
}

void Face::setO()
{
    if (!texture->loadFromFile("img/ooo.png"))
    {
        std::cout << "Failed to load texture\n";
    }
    sprite->setTexture(*texture);
    status = Status::O;
}

void Face::setDef()
{
    if (!texture->loadFromFile("img/smiled.png"))
    {
        std::cout << "Failed to load texture\n";
    }
    sprite->setTexture(*texture);
    status = Status::DEF;
}

void Face::setDead()
{
    if (!texture->loadFromFile("img/dead.png"))
    {
        std::cout << "Failed to load texture\n";
    }
    sprite->setTexture(*texture);
    status = Status::DEAD;
}

void Face::setWin()
{
    if (!texture->loadFromFile("img/win.png"))
    {
        std::cout << "Failed to load texture\n";
    }
    sprite->setTexture(*texture);
    status = Status::WIN;
}

Face::~Face()
{
	std::cout << "The face has been destroyed\n";
}
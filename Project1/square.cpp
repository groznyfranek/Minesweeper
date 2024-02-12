#include "square.h"

Square::Square(bool s, int x, int y)
{
	this->bomb = s;
    this->x = x;
    this->y = y;
    status = Status::DEF;
    texture = new sf::Texture;
	if (!texture->loadFromFile("img/empty.png"))
	{
		std::cout << "Failed to load texture\n";
	}
	sprite = new sf::Sprite(*texture);
	sprite->setScale(1, 1);
	sprite->setPosition(x, y + 150);
	//std::cout << "Square created\n";
}

bool Square::isValid(int row, int col, std::vector<std::vector<Square*>>& board)
{
    return (row >= 0) && (row < board[0].size()) && (col >= 0) && (col < board.size());
}
int Square::check(std::vector<std::vector<Square*>>& board)
{
    int output = 0;
    int x = this->x / 30;
    int y = this->y / 30;
    int numRows = board.size();
    int numCols = board[0].size();
    
    if (y > 0)
    {
        if( board[x][y - 1]->bomb) ++output;
    }
    if (y < numRows - 1)
    {
        if (board[x][y + 1]->bomb) ++output;
    }
    if (x > 0)
    {
        if (board[x - 1][y]->bomb) ++output;
    }
    if (x < numCols - 1)
    {
        if (board[x + 1][y]->bomb) ++output;
    }
    if (x > 0 && y > 0)
    {
        if (board[x - 1][y - 1]->bomb) ++output;
    }
    if (x > 0 && y < numRows - 1)
    {
        if (board[x - 1][y + 1]->bomb) ++output;
    }
    if (x < numCols - 1 && y < numRows - 1)
    {
        if (board[x + 1][y + 1]->bomb) ++output;
    }
    if (x < numCols - 1 && y > 0)
    {
        if (board[x + 1][y - 1]->bomb) ++output;
    }
    return output;
}

void Square::winPro()
{
 
}

void Square::losePro()
{
    if (status == Status::FLAGGED && bomb == false)
    {
        changeTexture("img/crossed.png");
    }
    if (status == Status::DEF && bomb == true)
    {
        changeTexture("img/bomb.png");
    }
}

void Square::changeTexture(const std::string& name)
{
    if (!texture->loadFromFile(name))
    {
        std::cout << "Failed to load texture\n";
    }
    sprite->setTexture(*texture);
}



Square::~Square()
{
	std::cout << "Squared erased\n";
}

#include "board.h"

Board::Board(int x, int y, double p, sf::RenderWindow* w)
{
	std::cout << x << "x" << y << " Board created\n";	
    window = w;
    bombs = 0;
	srand(time(0));
	for (int i = 0; i < x; ++i)
	{
		std::vector<Square*> vec;
		for (int j = 0; j < y; ++j)
		{
			Square* s = new Square(generateRandomBool(p), i * 30, j * 30);
			vec.push_back(s);
		}
		board.push_back(vec);
	}
    for (auto& row : board)
    {
        for (auto& col : row)
        {
            if (col->bomb == true) ++bombs;
        }
    }
	this->x = x;
	this->y = y;
	face = new Face(x, y);
	//print(board);   
}
void Board::squareReveal(Square* s, sf::RenderWindow* window)
{
    sf::Vector2i mousePos = sf::Mouse::getPosition(*window);
    sf::Vector2f worldPos = window->mapPixelToCoords(mousePos);
    if (s->sprite->getGlobalBounds().contains(worldPos))
    {
        int count = s->check(board);
        if (s->bomb)
        {
            s->changeTexture("img/exploded.png");
            s->status = Square::Status::EXPLODED;
        }
        if (s->bomb == false)
        {
            s->status = Square::Status::CLICKED;
            switch (count)
            {
            case 0:
                s->changeTexture("img/clicked.png");
                showFamilies();
                break;
            case 1:
                s->changeTexture("img/one.png");
                break;
            case 2:
                s->changeTexture("img/two.png");
                break;
            case 3:
                s->changeTexture("img/three.png");
                break;
            case 4:
                s->changeTexture("img/four.png");
                break;
            case 5:
                s->changeTexture("img/five.png");
                break;
            case 6:
                s->changeTexture("img/six.png");
                break;
            case 7:
                s->changeTexture("img/seven.png");
                break;
            case 8:
                s->changeTexture("img/eight.png");
                break;
            }
        }
    }
}

void Board::showFamilies()
{
    for (int row = 0; row < board.size(); ++row)
    {
        for (int col = 0; col < board[0].size(); ++col)
        {
            if (board[row][col]->status == Square::Status::CLICKED)
            {
                for (int i = row - 1; i <= row + 1; ++i)
                {
                    for (int j = col - 1; j <= col + 1; ++j)
                    {
                        if ((i >= 0 && i < board.size()) && (j >= 0 && j < board[0].size()))
                        {
                            if (board[i][j]->status == Square::Status::DEF && board[i][j]->bomb == false && (i != row || j != col) && board[i][j]->check(board) == 0)
                            {
                                board[i][j]->status = Square::Status::CLICKED;
                                board[i][j]->changeTexture("img/clicked.png");
                                showFamilies();
                            }
                        }
                    }
                }
            }            
        }
    }
}
void Board::clickSquare(Square* s,sf::RenderWindow* window, const sf::Event& event)
{
    if (event.type == sf::Event::MouseButtonPressed)
    {
        if (event.mouseButton.button == sf::Mouse::Right)
        {
            sf::Vector2i mousePos = sf::Mouse::getPosition(*window);
            sf::Vector2f worldPos = window->mapPixelToCoords(mousePos);
            if (s->sprite->getGlobalBounds().contains(worldPos) && s->status == Square::Status::DEF)
            {
                s->changeTexture("img/flag.png");
                s->status = Square::Status::FLAGGED;
            }
            else if (s->sprite->getGlobalBounds().contains(worldPos) && s->status == Square::Status::FLAGGED)
            {
                s->changeTexture("img/empty.png");
                s->status = Square::Status::DEF;
            }
        }
        if (event.mouseButton.button == sf::Mouse::Left)
        {
            squareReveal(s, window);
        }
    }
}

void Board::renderFace(sf::RenderWindow* window)
{
	window->draw(*(face->sprite));
}

void Board::renderBoard(sf::RenderWindow* window)
{	
	for (auto& element : board)
	{
		for(auto& el : element) window->draw(*(el->sprite));
	}	
}

bool Board::generateRandomBool(double probability)
{	
	double randomValue = static_cast<double>(rand()) / RAND_MAX;
	return randomValue < probability;
}
void Board::print(std::vector<std::vector<Square*>> vec)
{
	int x = vec.size();
	for (int i = 0; i < x; ++i)
	{		
		for (int j = 0; j < x; ++j)
		{
			std::cout << vec[j][i]->bomb<< " ";
		}
		std::cout << std::endl;
	}
}
Board::~Board()
{
	std::cout << "Board erased\n";
}
#include "game.h"
#include "square.h"

Game::Game(int x, int y, double p)
{
	std::cout << "The game has started\n";
	window = new sf::RenderWindow(sf::VideoMode(x * 30, (y * 30) + 150 ), "Minesweeper");
	board = new Board(x, y, p, window);
	time = 0;
	clock.restart();

	if (!font.loadFromFile("./font.ttf"))
	{
		std::cout << "Failed to load font" << std::endl;
	}

	labelClock = std::to_string(time);
	textClock.setFont(font);
	textClock.setOutlineThickness(2.0f);
	textClock.setOutlineColor(sf::Color::Black);
	textClock.setPosition(sf::Vector2f((15 * x) - 32, y + 70));
	textClock.setCharacterSize(37);
	textClock.setString(labelClock);
}

void Game::run()
{
	while (window->isOpen())
	{
		sf::Event event;
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window->close();
			}
			handleClicks(event);
		}
		window->clear(sf::Color(124, 124, 124));
		render();
		win();
		lose();
		labels();
		window->display();
	}
}

void Game::win()
{
	int hiddenSquares = 0;
	for (auto& element : board->board)
	{
		for (auto& el : element)
		{
			if (el->status == Square::Status::DEF) ++hiddenSquares;
			if ((el->status == Square::Status::FLAGGED) && el->bomb == false) return;
		}
	}
	if (hiddenSquares != board->bombs)
	{
		for (auto& element : board->board)
		{
			for (auto& el : element)
			{
				if ((el->status == Square::Status::DEF) && el->bomb == true) return;				
			}
		}
	}
	board->face->setWin();
	std::string strResult = "You won!";
	LPCSTR lpcstr = static_cast<LPCSTR>(strResult.c_str());
	bool result = MessageBoxA(NULL, lpcstr, "WARNING", MB_OK);
	window->close();
}

void Game::lose()
{
	for (auto& element : board->board)
	{
		for (auto& el : element)
		{
			if (el->status == Square::Status::EXPLODED)
			{
				for (auto& element : board->board)
				{
					for (auto& el : element)
					{
						el->losePro();
					}
				}
				board->face->setDead();
				render();				
				window->display();
				std::string strResult = "You lost!";
				LPCSTR lpcstr = static_cast<LPCSTR>(strResult.c_str());
				bool result = MessageBoxA(NULL, lpcstr, "WARNING", MB_OK);				
				window->close();				
			}			
		}
	}	
}

void Game::render()
{
	if (board->face->status == Face::Status::O)
	{
		board->face->setDef();
	}
	board->renderBoard(window);
	board->renderFace(window);
}

void Game::handleClicks(const sf::Event& event)
{
	board->face->click(window, event);
	for (auto& element : board->board)
	{
		for (auto& el : element)
		{
			board->clickSquare(el, window, event);
		}
	}
}

void Game::labels()
{
	time = clock.getElapsedTime().asSeconds();
	labelClock = std::to_string(time);
	while (labelClock.size() <= 3)
	{
		labelClock += "0";
		std::reverse(labelClock.begin(), labelClock.end());
	}
	labelClock.pop_back();
	textClock.setString(labelClock);
	window->draw(textClock);
	textClock.setString(labelScore);
	window->draw(textScore);
}

Game::~Game()
{
	std::cout << "The game has stopped\n";
}
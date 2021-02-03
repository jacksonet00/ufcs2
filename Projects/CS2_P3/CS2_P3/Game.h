#pragma once
#include <SFML/Graphics.hpp>
#include "Board.h"

class Game
{
public:
	Game();

	static void Start();
	static void Stop();

	static void DrawBoard(Board& b, sf::RenderWindow& game, bool debugMode, int state);
	static void DisplayCounter(Board& b, sf::RenderWindow& game);
	static void HandleLeftClick(Board& b, sf::Vector2i& pos, int state);
	static void HandleRightClick(Board& b, sf::Vector2i& pos, int state);
};


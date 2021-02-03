#include <iostream>
#include "Game.h"
#include "Tile.h"
#include "TextureManager.h"
using namespace std;

Game::Game()
{

}

void Game::Start()
{
	sf::RenderWindow game(sf::VideoMode(800, 600), "Minesweeper");

	//==== Initialize ====\\

	Board b;
	b.RandomGen();

	sf::Sprite tile(TextureManager::Get("tile_hidden"));

	bool debugMode = false;
	int state = 0;

	// Buttons

	sf::Sprite face(TextureManager::Get("face_happy"));
	face.setPosition(sf::Vector2f(400 - (face.getTextureRect().width / 2), tile.getTextureRect().height * 16));

	sf::Sprite debug(TextureManager::Get("debug"));
	debug.setPosition(sf::Vector2f(400 + (face.getTextureRect().width / 2) + (debug.getTextureRect().width), tile.getTextureRect().height * 16));

	sf::Sprite test_1(TextureManager::Get("test_1"));
	test_1.setPosition(sf::Vector2f(400 + (face.getTextureRect().width / 2) + (test_1.getTextureRect().width * 2), tile.getTextureRect().height * 16));

	sf::Sprite test_2(TextureManager::Get("test_2"));
	test_2.setPosition(sf::Vector2f(400 + (face.getTextureRect().width / 2) + (test_1.getTextureRect().width * 3), tile.getTextureRect().height * 16));

	sf::Sprite test_3(TextureManager::Get("test_3"));
	test_3.setPosition(sf::Vector2f(400 + (face.getTextureRect().width / 2) + (test_1.getTextureRect().width * 4), tile.getTextureRect().height * 16));


	while (game.isOpen())
	{
		sf::Event e;
		while (game.pollEvent(e))
		{
			if (e.type == sf::Event::Closed)
			{
				Stop();
				game.close();
			}

			if (e.type == sf::Event::MouseButtonPressed)
			{
				if (e.mouseButton.button == sf::Mouse::Left)
				{
					auto pos = sf::Mouse::getPosition(game);

					HandleLeftClick(b, pos, state);

					if (face.getGlobalBounds().contains(sf::Vector2f(pos.x, pos.y)))
						b.RandomGen();

					if (debug.getGlobalBounds().contains(sf::Vector2f(pos.x, pos.y)))
					{
						// Toggle Debug Mode
						if (!debugMode)
							debugMode = true;
						else
							debugMode = false;
					}

					if (test_1.getGlobalBounds().contains(sf::Vector2f(pos.x, pos.y)))
						b.FileGen("testboard1");

					if (test_2.getGlobalBounds().contains(sf::Vector2f(pos.x, pos.y)))
						b.FileGen("testboard2");

					if (test_3.getGlobalBounds().contains(sf::Vector2f(pos.x, pos.y)))
						b.FileGen("testboard3");
				}

				if (e.mouseButton.button == sf::Mouse::Right)
				{
					auto pos = sf::Mouse::getPosition(game);

					HandleRightClick(b, pos, state);
				}
			}
		}

		//==== UPDATE ====\\

		state = b.GetState();

		if (state == 0)
		{
			// Default
			face.setTexture(TextureManager::Get("face_happy"));
		}
		if (state == 1)
		{
			// Loss
			face.setTexture(TextureManager::Get("face_lose"));
		}
		if (state == 2)
		{
			// Win
			face.setTexture(TextureManager::Get("face_win"));
			b.FlagMines();
		}

		b.UpdateBoard();

		//==== DRAW ====\\

		game.clear(sf::Color::White);

		DrawBoard(b, game, debugMode, state);
		DisplayCounter(b, game);
		game.draw(face);
		game.draw(debug);
		game.draw(test_1);
		game.draw(test_2);
		game.draw(test_3);

		game.display();
	}
}

void Game::Stop()
{
	TextureManager::ShutDown();
}

void Game::DrawBoard(Board& b, sf::RenderWindow& game, bool debugMode, int state)
{
	sf::Sprite tile(TextureManager::Get("tile_hidden"));

	for (int i = 0; i < 16; i++)
		for (int j = 0; j < 25; j++)
		{
			float xpos = j * tile.getTextureRect().width;
			float ypos = i * tile.getTextureRect().height;

			int value = b.GetTiles()[i][j].GetValue();

			if (b.GetTiles()[i][j].Revealed())
			{
				// Render Revealed Tile
				sf::Sprite tile_revealed(TextureManager::Get("tile_revealed"));
				tile_revealed.setPosition(sf::Vector2f(xpos, ypos));
				game.draw(tile_revealed);

				if (value > 0)
				{
					// Render the Number
					sf::Sprite num;
					num.setPosition(sf::Vector2f(xpos, ypos));

					if (value == 1)
						num.setTexture(TextureManager::Get("number_1"));
					if (value == 2)
						num.setTexture(TextureManager::Get("number_2"));
					if (value == 3)
						num.setTexture(TextureManager::Get("number_3"));
					if (value == 4)
						num.setTexture(TextureManager::Get("number_4"));
					if (value == 5)
						num.setTexture(TextureManager::Get("number_5"));
					if (value == 6)
						num.setTexture(TextureManager::Get("number_6"));
					if (value == 7)
						num.setTexture(TextureManager::Get("number_7"));
					if (value == 8)
						num.setTexture(TextureManager::Get("number_8"));

					game.draw(num);
				}

				if (b.GetTiles()[i][j].Mine())
				{
					// Render the Mine
					sf::Sprite mine(TextureManager::Get("mine"));
					mine.setPosition(xpos, ypos);
					game.draw(mine);
				}
			}
			else
			{
				// Render Hidden Tile
				sf::Sprite tile_hidden(TextureManager::Get("tile_hidden"));
				tile_hidden.setPosition(sf::Vector2f(xpos, ypos));
				game.draw(tile_hidden);

				if (b.GetTiles()[i][j].Flagged())
				{
					// Render the Flag
					sf::Sprite flag(TextureManager::Get("flag"));
					flag.setPosition(sf::Vector2f(xpos, ypos));
					game.draw(flag);
				}
			}

			if (debugMode || state == 1)
			{
				if (b.GetTiles()[i][j].Mine())
				{
					sf::Sprite debugMine(TextureManager::Get("mine"));
					debugMine.setPosition(sf::Vector2f(xpos, ypos));
					game.draw(debugMine);
				}
			}
		}
}

void Game::DisplayCounter(Board& b, sf::RenderWindow& game)
{
	int counter = b.GetCounter();
	int startPos = 0;
	sf::Sprite tile(TextureManager::Get("tile_hidden"));

	if (counter < 0)
	{
		startPos = 21;
		counter *= -1;

		sf::Sprite sign(TextureManager::Get("digits"));
		sign.setTextureRect(sf::IntRect(210, 0, 21, 32));
		sign.setPosition(sf::Vector2f(0, tile.getTextureRect().width * 16));
		game.draw(sign);
	}

	sf::Sprite digit_one(TextureManager::Get("digits"));
	digit_one.setTextureRect(sf::IntRect((counter / 10) * 21, 0, 21, 32));
	digit_one.setPosition(sf::Vector2f(startPos, tile.getTextureRect().width * 16));

	sf::Sprite digit_two(TextureManager::Get("digits"));
	digit_two.setTextureRect(sf::IntRect((counter % 10) * 21, 0, 21, 32));
	digit_two.setPosition(sf::Vector2f(startPos + 21, tile.getTextureRect().width * 16));

	game.draw(digit_one);
	game.draw(digit_two);
}

void Game::HandleLeftClick(Board& b, sf::Vector2i& pos, int state)
{
	if (state != 1)
	{
		sf::Sprite tile(TextureManager::Get("tile_hidden"));

		for (int i = 0; i < 16; i++)
		{
			for (int j = 0; j < 25; j++)
			{
				float xpos = j * tile.getTextureRect().width;
				float ypos = i * tile.getTextureRect().height;

				tile.setPosition(sf::Vector2f(xpos, ypos));

				if (tile.getGlobalBounds().contains(pos.x, pos.y))
				{
					if (!b.GetTiles()[i][j].Flagged())
						b.GetTiles()[i][j].Reveal();
				}
			}
		}
	}
}

void Game::HandleRightClick(Board& b, sf::Vector2i& pos, int state)
{
	if (state != 1)
	{
		sf::Sprite tile(TextureManager::Get("tile_hidden"));

		for (int i = 0; i < 16; i++)
		{
			for (int j = 0; j < 25; j++)
			{
				float xpos = j * tile.getTextureRect().width;
				float ypos = i * tile.getTextureRect().height;

				tile.setPosition(sf::Vector2f(xpos, ypos));

				if (tile.getGlobalBounds().contains(pos.x, pos.y))
				{
					if (b.GetTiles()[i][j].Flagged())
						b.GetTiles()[i][j].RemoveFlag();
					else
						b.GetTiles()[i][j].Flag();
				}
			}
		}
	}
}
#include "Board.h"
#include <string>
#include <fstream>
#include <sstream>
#include "Random.h"
using namespace std;

Board::Board()
{
	state = 0;
	mineCount = 0;

	tiles.resize(16);

	for (int i = 0; i < 16; i++)
		tiles[i].resize(25);
}

void Board::FileGen(string fileName)
{
	SetDefaultState();
	mineCount = 0;

	string filePath = "boards/" + fileName + ".brd";

	ifstream file(filePath);
	string line;
	bool mine = false;

	if (file.is_open())
	{
		for (int i = 0; i < 16; i++)
		{
			getline(file, line);

			for (int j = 0; j < 25; j++)
			{
				char temp = line.at(j);

				if (temp == '1')
				{
					mine = true;
					mineCount++;
				}
				if (temp == '0')
					mine = false;

				Tile t(mine);
				tiles[i][j] = t;
			}
		}

		SetTileValues();
	}
	else
	{
		throw runtime_error("File could not be opened");
	}
}

void Board::RandomGen()
{
	SetDefaultState();
	mineCount = 0;

	for (int i = 0; i < 16; i++)
		for (int j = 0; j < 25; j++)
		{
			Tile t;
			tiles[i][j] = t;
		}

	while (mineCount < 50)
	{
		int x = Random::Int(0, 15);
		int y = Random::Int(0, 24);

		if (!tiles[x][y].Mine())
		{
			tiles[x][y].SetMine();
			mineCount++;
		}
	}

	SetTileValues();
}

void Board::UpdateBoard()
{
	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 25; j++)
		{
			if (tiles[i][j].Revealed() && !tiles[i][j].Mine() && tiles[i][j].GetValue() == 0)
			{
				// 1. Check bounds.
				// 2. Check for Mines & Flags.
				// 3. Reveal Tile.

				if (i + 1 < 16)
					if (!tiles[i + 1][j].Mine() && !tiles[i + 1][j].Flagged())
						tiles[i + 1][j].Reveal();
				if (j + 1 < 25)
					if (!tiles[i][j + 1].Mine() && !tiles[i][j + 1].Flagged())
						tiles[i][j + 1].Reveal();
				if (i - 1 >= 0)
					if (!tiles[i - 1][j].Mine() && !tiles[i - 1][j].Flagged())
						tiles[i - 1][j].Reveal();
				if (j - 1 >= 0)
					if (!tiles[i][j - 1].Mine() && !tiles[i][j - 1].Flagged())
						tiles[i][j - 1].Reveal();
				if (i + 1 < 16 && j + 1 < 25)
					if (!tiles[i + 1][j + 1].Mine() && !tiles[i + 1][j + 1].Flagged())
						tiles[i + 1][j + 1].Reveal();
				if (i - 1 >= 0 && j - 1 >= 0)
					if (!tiles[i - 1][j - 1].Mine() && !tiles[i - 1][j - 1].Flagged())
						tiles[i - 1][j - 1].Reveal();
				if (i - 1 >= 0 && j + 1 < 25)
					if (!tiles[i - 1][j + 1].Mine() && !tiles[i - 1][j + 1].Flagged())
						tiles[i - 1][j + 1].Reveal();
				if (i + 1 < 16 && j - 1 >= 0)
					if (!tiles[i + 1][j - 1].Mine() && !tiles[i + 1][j - 1].Flagged())
						tiles[i + 1][j - 1].Reveal();
			}
		}
	}
}

void Board::SetTileValues()
{
	int count = 0;

	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 25; j++)
		{
			if (!tiles[i][j].Mine())
			{
				if (i + 1 < 16)
					if (tiles[i + 1][j].Mine())
						count++;
				if (j + 1 < 25)
					if (tiles[i][j + 1].Mine())
						count++;
				if (i - 1 >= 0)
					if (tiles[i - 1][j].Mine())
						count++;
				if (j - 1 >= 0)
					if (tiles[i][j - 1].Mine())
						count++;
				if (i + 1 < 16 && j + 1 < 25)
					if (tiles[i + 1][j + 1].Mine())
						count++;
				if (i - 1 >= 0 && j - 1 >= 0)
					if (tiles[i - 1][j - 1].Mine())
						count++;
				if (i - 1 >= 0 && j + 1 < 25)
					if (tiles[i - 1][j + 1].Mine())
						count++;
				if (i + 1 < 16 && j - 1 >= 0)
					if (tiles[i + 1][j - 1].Mine())
						count++;

				tiles[i][j].SetValue(count);
				count = 0;
			}
		}
	}
}

void Board::SetState(int s)
{
	if (s == 0 || s == 1 || s == 2)
		state = s;
}

void Board::SetDefaultState()
{
	state = 0;
}

void Board::RevealMines()
{
	for (int i = 0; i < 16; i++)
		for (int j = 0; j < 25; j++)
			if (tiles[i][j].Mine())
			{
				tiles[i][j].Reveal();
			}
}

void Board::HideMines()
{
	for (int i = 0; i < 16; i++)
		for (int j = 0; j < 25; j++)
			if (tiles[i][j].Mine())
			{
				tiles[i][j].Hide();
			}
}

void Board::FlagMines()
{
	for (int i = 0; i < 16; i++)
		for (int j = 0; j < 25; j++)
			if (tiles[i][j].Mine())
			{
				tiles[i][j].Flag();
			}
}

vector<vector<Tile>>& Board::GetTiles()
{
	return tiles;
}

int Board::GetState()
{
	int winCount = 0;

	if (state == 0)
	{
		for (int i = 0; i < 16; i++)
			for (int j = 0; j < 25; j++)
			{
				if (tiles[i][j].Revealed() && tiles[i][j].Mine())
					state = 1;
				if (tiles[i][j].Revealed() && !tiles[i][j].Mine())
					winCount++;
				if (!tiles[i][j].Revealed() && tiles[i][j].Mine())
					winCount++;
			}

		if (winCount == 400)
			state = 2;
	}
	

	return state;
}

int Board::GetMineCount()
{
	return mineCount;
}

int Board::GetCounter()
{
	int flagCount = 0;
	for (int i = 0; i < 16; i++)
		for (int j = 0; j < 25; j++)
		{
			if (tiles[i][j].Flagged())
				flagCount++;
		}

	return mineCount - flagCount;
}
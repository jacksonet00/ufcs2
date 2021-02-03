#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Tile.h"
#include "TextureManager.h"
using std::vector;

class Board
{
	vector<vector<Tile>> tiles;
	
	// State:
	// State 0 - Default
	// State 1 - Loss
	// State 2 - Victory
	int state;
	int mineCount;
public:
	Board();

	void FileGen(string fileName);
	void RandomGen();
	void UpdateBoard();

	void RevealMines();
	void HideMines();
	void FlagMines();

	void SetTileValues();
	void SetState(int s);
	void SetDefaultState();


	vector<vector<Tile>>& GetTiles();
	int GetState();
	int GetMineCount();
	int GetCounter();
};


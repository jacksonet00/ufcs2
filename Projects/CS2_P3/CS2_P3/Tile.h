#pragma once
class Tile
{
	bool isMine;
	bool isFlagged;
	bool hidden;
	int value;
public:
	Tile();
	Tile(bool m, bool f = false, bool h = true, int v = 0);

	bool Mine();
	bool Flagged();
	bool Revealed();

	void Reveal();
	void Hide();

	void Flag();
	void RemoveFlag();

	void SetValue(int v);
	void SetMine();

	int GetValue();
};


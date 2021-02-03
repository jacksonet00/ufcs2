#include "Tile.h"

Tile::Tile()
{
	isMine = false;
	isFlagged = false;
	hidden = true;
	value = 0;
}

Tile::Tile(bool m, bool f, bool h, int v)
{
	isMine = m;
	isFlagged = f;
	hidden = h;
	value = v;
}

bool Tile::Mine()
{
	return isMine;
}

bool Tile::Flagged()
{
	return isFlagged;
}

bool Tile::Revealed()
{
	return !hidden;
}

void Tile::Reveal()
{
	hidden = false;
}

void Tile::Hide()
{
	hidden = true;
}

void Tile::Flag()
{
	isFlagged = true;
}

void Tile::RemoveFlag()
{
	isFlagged = false;
}

void Tile::SetValue(int v)
{
	value = v;
}

void Tile::SetMine()
{
	isMine = true;
}

int Tile::GetValue()
{
	return value;
}
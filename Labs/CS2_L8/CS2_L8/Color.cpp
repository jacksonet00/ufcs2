#include "Color.h"
using namespace std;

Color::Color()
{
	_name = "";
	_value = 0;
}

Color::Color(string name, int value)
{
	_name = name;
	_value = value;
}

void Color::SetValue(int value)
{
	_value = value;
}

void Color::SetName(const char* name)
{
	_name = name;
}

unsigned char Color::GetR() const
{
	return (_value >> 16);
}

unsigned char Color::GetG() const
{
	return (_value >> 8);
}

unsigned char Color::GetB() const
{
	return (_value);
}

string Color::GetHexValue() const
{
	return "0x" + Color::ColorToHex(GetR()) + Color::ColorToHex(GetG()) + Color::ColorToHex(GetB());
}

string Color::GetName() const
{
	return _name;
}

string Color::ColorToHex(unsigned char color)
{
	string hexVals[17] = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F" };

	int div = (int)color / 16;
	int mod = (int)color % 16;

	return hexVals[div] + hexVals[mod];
}
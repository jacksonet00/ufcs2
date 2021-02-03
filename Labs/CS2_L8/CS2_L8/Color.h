#pragma once
#include <string>
using std::string;

class Color
{
	string _name;
	int _value;
public:
	Color();
	Color(string name, int value);

	void SetValue(int value);
	void SetName(const char* name);

	unsigned char GetR() const;
	unsigned char GetG() const;
	unsigned char GetB() const;
	string GetHexValue() const;
	string GetName() const;

	static string ColorToHex(unsigned char color);
};
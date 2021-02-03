#pragma once

class Pixel
{
	unsigned char blue;
	unsigned char green;
	unsigned char red;
public:
	Pixel(unsigned char B = 0, unsigned char G = 0, unsigned char R = 0);

	unsigned char GetBlue();
	unsigned char GetGreen();
	unsigned char GetRed();
};


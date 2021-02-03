#include "Pixel.h"

Pixel::Pixel(unsigned char B, unsigned char G, unsigned char R)
{
	blue = B;
	green = G;
	red = R;
}

unsigned char Pixel::GetBlue()
{
	return blue;
}

unsigned char Pixel::GetGreen()
{
	return green;
}

unsigned char Pixel::GetRed()
{
	return red;
}
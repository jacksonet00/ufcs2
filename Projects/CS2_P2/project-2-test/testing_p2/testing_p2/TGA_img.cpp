#include "TGA_img.h"
using namespace std;

TGA_img::TGA_img()
{
	
}

TGA_img::TGA_img(TGA_head& head, vector<Pixel>& pixels)
{
	header = head;
	imgData = pixels;
}

TGA_head& TGA_img::GetHead()
{
	return header;
}

vector<Pixel>& TGA_img::GetData()
{
	return imgData;
}
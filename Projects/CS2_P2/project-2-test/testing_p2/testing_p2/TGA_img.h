#pragma once
#include <vector>
#include "TGA_head.h"
#include "Pixel.h"
using std::vector;

class TGA_img
{
	TGA_head header;
	vector<Pixel> imgData;
public:
	TGA_img();
	TGA_img(TGA_head& head, vector<Pixel>& pixels);

	TGA_head& GetHead();
	vector<Pixel>& GetData();
};


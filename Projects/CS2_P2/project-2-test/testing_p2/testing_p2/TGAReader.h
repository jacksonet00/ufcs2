#pragma once
#include <fstream>
#include "TGA_head.h"
#include "TGA_img.h"
#include "Pixel.h"
using std::ifstream;

class TGAReader
{
	ifstream file;
public:
	TGAReader(const char* path = "");
	
	TGA_img& ReadTGAImg();
	TGA_head& ReadTGAHead();
	vector<Pixel>& ReadTGAData();
	Pixel& ReadPixel();

	unsigned char ReadUnsignedChar();
	char ReadChar();
	short ReadShort();
};


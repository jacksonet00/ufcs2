#pragma once
#include <fstream>
#include <vector>
#include "Pixel.h"
#include "TGAHead.h"
#include "TGAImg.h"
using std::ifstream;

class TGAReader
{
	ifstream file;
public:
	TGAReader();

	void Open(const char* path);

	TGAImg ReadImg();
	TGAHead ReadHead();
	vector<Pixel> ReadData(int pixelCount);
	Pixel ReadPixel();

	char ReadChar();
	unsigned char ReadUnsignedChar();
	short ReadShort();
};


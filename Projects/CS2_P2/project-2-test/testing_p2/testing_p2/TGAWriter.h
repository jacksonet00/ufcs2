#pragma once
#include <vector>
#include <fstream>
#include "TGA_img.h"
#include "TGA_head.h"
#include "Pixel.h"
using std::ofstream;
using std::vector;

class TGAWriter
{
	ofstream file;
public:
	TGAWriter(const char* path = "");

	void WriteTGAImg(TGA_img& img);
	void WriteTGAHead(TGA_head& header);
	void WriteTGAData(vector<Pixel>& data);
	void WritePixel(Pixel& pixel);

	void WriteChar(char data);
	void WriteUnsignedChar(unsigned char data);
	void WriteShort(short data);
};



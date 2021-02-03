#pragma once
#include <fstream>
#include <vector>
#include "Pixel.h"
#include "TGAHead.h"
#include "TGAImg.h"
using std::ofstream;

class TGAWriter
{
	ofstream file;
public:
	TGAWriter();

	void Open(const char* path);

	void WriteImg(TGAImg& image);
	void WriteHead(TGAHead& head);
	void WriteData(vector<Pixel>& data);
	void WritePixel(Pixel& pixel);

	void WriteChar(char data);
	void WriteUnsignedChar(unsigned char data);
	void WriteShort(short data);
};


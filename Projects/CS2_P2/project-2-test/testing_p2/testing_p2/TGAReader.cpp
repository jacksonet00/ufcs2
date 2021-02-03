#include "TGAReader.h"
using namespace std;

TGAReader::TGAReader(const char* path)
{
	file.open(path, ios_base::binary);
	if (!file.is_open())
	{
		throw runtime_error("The specified file failed to open.");
	}
}

TGA_img& TGAReader::ReadTGAImg()
{
	TGA_head imgH = ReadTGAHead();
	
	vector<Pixel> imgD = ReadTGAData();

	TGA_img readImg(imgH, imgD);

	return readImg;
}

TGA_head& TGAReader::ReadTGAHead()
{
	char il, cmt, dtc;
	short cmo, cml;
	char cmd;
	short xo, yo, w, h;
	char bpp, id;

	il = ReadChar();
	cmt = ReadChar();
	dtc = ReadChar();
	
	cmo = ReadShort();
	cml = ReadShort();

	cmd = ReadChar();

	xo = ReadShort();
	yo = ReadShort();
	w = ReadShort();
	h = ReadShort();

	bpp = ReadChar();
	id = ReadChar();

	TGA_head read(il, cmt, dtc, cmo, cml, cmd, xo, yo, w, h, bpp, id);

	return read;

}

vector<Pixel>& TGAReader::ReadTGAData()
{
	vector<Pixel> imgData;

	while (!file.eof())
	{
		Pixel newPixel = ReadPixel();
		imgData.push_back(newPixel);
	}

	return imgData;
}

Pixel& TGAReader::ReadPixel()
{
	unsigned char B, G, R;
	B = ReadUnsignedChar();
	G = ReadUnsignedChar();
	R = ReadUnsignedChar();

	Pixel read(B, G, R);

	return read;
}

unsigned char TGAReader::ReadUnsignedChar()
{
	unsigned char temp;
	file.read((char*)&temp, sizeof(temp));
	return temp;
}

char TGAReader::ReadChar()
{
	char temp;
	file.read((char*)&temp, sizeof(temp));
	return temp;
}

short TGAReader::ReadShort()
{
	short temp;
	file.read((char*)&temp, sizeof(temp));
	return temp;
}
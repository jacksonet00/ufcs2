#include "TGAReader.h"
using namespace std;

TGAReader::TGAReader()
{
	
}

void TGAReader::Open(const char* path)
{
	if (file.is_open())
		file.close();

	file.open(path, ios_base::binary);
	if (!file.is_open())
	{
		throw runtime_error("The specified file failed to open.");
	}
}

TGAImg TGAReader::ReadImg()
{
	TGAHead imageHeader = ReadHead();

	int pixelCount = imageHeader.GetPixelCount();

	vector<Pixel> imageData = ReadData(pixelCount);

	TGAImg image(imageHeader, imageData);

	return image;
}

TGAHead TGAReader::ReadHead()
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

	TGAHead imageHeader(il, cmt, dtc, cmo, cml, cmd, xo, yo, w, h, bpp, id);

	return imageHeader;
}

vector<Pixel> TGAReader::ReadData(int pixelCount)
{
	vector<Pixel> imageData;
	
	for (int i = 0; i < pixelCount; i++)
	{
		Pixel nextPixel = ReadPixel();
		imageData.push_back(nextPixel);
	}

	return imageData;
}

Pixel TGAReader::ReadPixel()
{
	unsigned char B = ReadUnsignedChar();
	unsigned char G = ReadUnsignedChar();
	unsigned char R = ReadUnsignedChar();

	Pixel newPixel(B, G, R);

	return newPixel;
}

char TGAReader::ReadChar()
{
	char temp;
	file.read((char*)&temp, sizeof(temp));
	return temp;
}

unsigned char TGAReader::ReadUnsignedChar()
{
	unsigned char temp;
	file.read((char*)&temp, sizeof(temp));
	return temp;
}

short TGAReader::ReadShort()
{
	short temp;
	file.read((char*)&temp, sizeof(temp));
	return temp;
}

#include "TGA_head.h"
using namespace std;

TGA_head::TGA_head()
{
	idLength = 0;
	colorMapType = 0;
	dataTypeCode = 0;
	colorMapOrigin = 0;
	colorMapLength = 0;
	colorMapDepth = 0;
	xOrigin = 0;
	yOrigin = 0;
	width = 0;
	height = 0;
	bitsPerPixel = 0;
	imageDescriptor = 0;
}

TGA_head::TGA_head(char il, char cmt, char dtc, short cmo, short cml, char cmd, short xo, short yo, short w, short h, char bpp, char id)
{
	idLength = il;
	colorMapType = cmt;
	dataTypeCode = dtc;
	colorMapOrigin = cmo;
	colorMapLength = cml;
	colorMapDepth = cmd;
	xOrigin = xo;
	yOrigin = yo;
	width = w;
	height = h;
	bitsPerPixel = bpp;
	imageDescriptor = id;
}

char TGA_head::GetIdLength()
{
	return idLength;
}

char TGA_head::GetColorMapType()
{
	return colorMapType;
}

char TGA_head::GetDataTypeCode()
{
	return dataTypeCode;
}

short TGA_head::GetColorMapOrigin()
{
	return colorMapOrigin;
}

short TGA_head::GetColorMapLength()
{
	return colorMapLength;
}

char TGA_head::GetColorMapDepth()
{
	return colorMapDepth;
}

short TGA_head::GetXOrigin()
{
	return xOrigin;
}

short TGA_head::GetYOrigin()
{
	return yOrigin;
}

short TGA_head::GetHeight()
{
	return height;
}

short TGA_head::GetWidth()
{
	return width;
}

char TGA_head::GetBitsPerPixel()
{
	return bitsPerPixel;
}

char TGA_head::GetImageDescriptor()
{
	return imageDescriptor;
}
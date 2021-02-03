#include "TGAHead.h"
using namespace std;

TGAHead::TGAHead()
{
	idLength = (char)0;
	colorMapType = (char)0;
	dataTypeCode = (char)0;
	colorMapOrigin = (short)0;
	colorMapLength = (short)0;
	colorMapDepth = (char)0;
	xOrigin = (short)0;
	yOrigin = (short)0;
	width = (short)0;
	height = (short)0;
	bitsPerPixel = (char)0;
	imageDescriptor = (char)0;
}

TGAHead::TGAHead(char il, char cmt, char dtc, short cmo, short cml, char cmd, short xo, short yo, short w, short h, char bpp, char id)
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

char TGAHead::GetIdLength()
{
	return idLength;
}

char TGAHead::GetColorMapType()
{
	return colorMapType;
}

char TGAHead::GetDataTypeCode()
{
	return dataTypeCode;
}

short TGAHead::GetColorMapOrigin()
{
	return colorMapOrigin;
}

short TGAHead::GetColorMapLength()
{
	return colorMapLength;
}

char TGAHead::GetColorMapDepth()
{
	return colorMapDepth;
}

short TGAHead::GetXOrigin()
{
	return xOrigin;
}

short TGAHead::GetYOrigin()
{
	return yOrigin;
}

short TGAHead::GetHeight()
{
	return height;
}

short TGAHead::GetWidth()
{
	return width;
}

char TGAHead::GetBitsPerPixel()
{
	return bitsPerPixel;
}

char TGAHead::GetImageDescriptor()
{
	return imageDescriptor;
}

int TGAHead::GetPixelCount()
{
	int height = (int)GetHeight();
	int width = (int)GetWidth();

	return (width * height);
}
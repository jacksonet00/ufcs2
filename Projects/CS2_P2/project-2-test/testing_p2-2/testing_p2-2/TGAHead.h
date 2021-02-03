#pragma once

class TGAHead
{
	char idLength;
	char colorMapType;
	char dataTypeCode;
	short colorMapOrigin;
	short colorMapLength;
	char colorMapDepth;
	short xOrigin;
	short yOrigin;
	short width;
	short height;
	char bitsPerPixel;
	char imageDescriptor;
public:
	TGAHead();
	TGAHead(char il, char cmt, char dtc, short cmo, short cml, char cmd, short xo, short yo, short w, short h, char bpp, char id);

	char GetIdLength();
	char GetColorMapType();
	char GetDataTypeCode();
	short GetColorMapOrigin();
	short GetColorMapLength();
	char GetColorMapDepth();
	short GetXOrigin();
	short GetYOrigin();
	short GetHeight();
	short GetWidth();
	char GetBitsPerPixel();
	char GetImageDescriptor();
	int GetPixelCount();
};


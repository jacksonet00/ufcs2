#include "TGAWriter.h"
using namespace std;

TGAWriter::TGAWriter()
{
	
}

void TGAWriter::Open(const char* path)
{
	if (file.is_open())
		file.close();

	file.open(path, ios_base::binary);
	if (!file.is_open())
	{
		throw runtime_error("The specified file failed to open.");
	}
}

void TGAWriter::WriteImg(TGAImg& image)
{
	TGAHead imageHeader = image.GetHead();
	vector<Pixel> imageData = image.GetData();

	WriteHead(imageHeader);
	WriteData(imageData);
}

void TGAWriter::WriteHead(TGAHead& head)
{
	char il, cmt, dtc;
	short cmo, cml;
	char cmd;
	short xo, yo, w, h;
	char bpp, id;

	il = head.GetIdLength();
	cmt = head.GetColorMapType();
	dtc = head.GetDataTypeCode();
	cmo = head.GetColorMapOrigin();
	cml = head.GetColorMapLength();
	cmd = head.GetColorMapDepth();
	xo = head.GetXOrigin();
	yo = head.GetYOrigin();
	w = head.GetWidth();
	h = head.GetHeight();
	bpp = head.GetBitsPerPixel();
	id = head.GetImageDescriptor();
	
	WriteChar(il);
	WriteChar(cmt);
	WriteChar(dtc);

	WriteShort(cmo);
	WriteShort(cml);

	WriteChar(cmd);

	WriteShort(xo);
	WriteShort(yo);
	WriteShort(w);
	WriteShort(h);

	WriteChar(bpp);
	WriteChar(id);
}

void TGAWriter::WriteData(vector<Pixel>& data)
{
	for (unsigned int i = 0; i < data.size(); i++)
	{
		WritePixel(data[i]);
	}
}

void TGAWriter::WritePixel(Pixel& pixel)
{
	unsigned char B, G, R;

	B = pixel.GetBlue();
	G = pixel.GetGreen();
	R = pixel.GetRed();

	WriteUnsignedChar(B);
	WriteUnsignedChar(G);
	WriteUnsignedChar(R);
}

void TGAWriter::WriteChar(char data)
{
	file.write((char*)&data, sizeof(data));
}

void TGAWriter::WriteUnsignedChar(unsigned char data)
{
	file.write((char*)&data, sizeof(data));
}

void TGAWriter::WriteShort(short data)
{
	file.write((char*)&data, sizeof(data));
}
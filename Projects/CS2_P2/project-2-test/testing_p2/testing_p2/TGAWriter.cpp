#include "TGAWriter.h"
using namespace std;

TGAWriter::TGAWriter(const char* path)
{
	file.open(path, ios_base::binary);
	if (!file.is_open())
	{
		throw runtime_error("The specified file failed to open.");
	}
}

void TGAWriter::WriteTGAImg(TGA_img& img)
{
	TGA_head imgHeader = img.GetHead();
	vector<Pixel> imgData = img.GetData();

	WriteTGAHead(imgHeader);
	WriteTGAData(imgData);
}

void TGAWriter::WriteTGAHead(TGA_head& header)
{
	WriteChar(header.GetIdLength());
	WriteChar(header.GetColorMapType());
	WriteChar(header.GetDataTypeCode());

	WriteShort(header.GetColorMapOrigin());
	WriteShort(header.GetColorMapLength());

	WriteChar(header.GetColorMapDepth());

	WriteShort(header.GetXOrigin());
	WriteShort(header.GetYOrigin());
	WriteShort(header.GetWidth());
	WriteShort(header.GetHeight());

	WriteChar(header.GetBitsPerPixel());
	WriteChar(header.GetImageDescriptor());

}

void TGAWriter::WriteTGAData(vector<Pixel>& data)
{
	for (unsigned int i = 0; i < data.size(); i++)
	{
		WritePixel(data[i]);
	}
}

void TGAWriter::WritePixel(Pixel& pixel)
{
	WriteUnsignedChar(pixel.GetBlue());
	WriteUnsignedChar(pixel.GetGreen());
	WriteUnsignedChar(pixel.GetRed());
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
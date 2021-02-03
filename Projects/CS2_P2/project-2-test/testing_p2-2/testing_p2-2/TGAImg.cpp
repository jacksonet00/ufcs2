#include "TGAImg.h"
using namespace std;

TGAImg::TGAImg()
{

}

TGAImg::TGAImg(TGAHead& head, vector<Pixel>& pixels)
{
	header = head;
	imgData = pixels;
}

TGAHead TGAImg::GetHead()
{
	return header;
}

vector<Pixel> TGAImg::GetData()
{
	return imgData;
}

void TGAImg::SetHead(TGAHead& head)
{
	header = head;
}

void TGAImg::SetData(vector<Pixel>& pixels)
{
	imgData = pixels;
}
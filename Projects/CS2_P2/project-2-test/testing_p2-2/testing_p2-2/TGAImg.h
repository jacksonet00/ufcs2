#pragma once
#include <vector>
#include "TGAHead.h"
#include "Pixel.h"
using std::vector;

class TGAImg
{
	TGAHead header;
	vector<Pixel> imgData;
public:
	TGAImg();
	TGAImg(TGAHead& head, vector<Pixel>& pixels);

	TGAHead GetHead();
	vector<Pixel> GetData();

	void SetHead(TGAHead& head);
	void SetData(vector<Pixel>& pixels);
};


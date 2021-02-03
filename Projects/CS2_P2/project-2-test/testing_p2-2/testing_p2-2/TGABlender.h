#pragma once
#include "TGAHead.h"
#include "TGAImg.h"
#include "Pixel.h"

class TGABlender
{
public:
	TGABlender();

	TGAImg Multiply(TGAImg& top, TGAImg& bottom);
	TGAImg Subtract(TGAImg& top, TGAImg& bottom);
	TGAImg Screen(TGAImg& top, TGAImg& bottom);
	TGAImg Overlay(TGAImg& top, TGAImg& bottom);
	TGAImg AddToChannel(TGAImg& img, unsigned char val, char RGB);
	TGAImg Scale(TGAImg& img, unsigned char val, char RGB);
	TGAImg GetChannel(TGAImg& img, char RGB);
	TGAImg CombineChannels(TGAImg& red, TGAImg& green, TGAImg& blue);
	TGAImg Rotate180(TGAImg& img);
};


#include "TGABlender.h"
#include <cmath>
using namespace std;

TGABlender::TGABlender()
{

}

TGAImg TGABlender::Multiply(TGAImg& top, TGAImg& bottom)
{
	TGAHead multiplyHead;
	vector<Pixel> topData, bottomData, multiplyData;
	float B, G, R;

	topData = top.GetData();
	bottomData = bottom.GetData();

	multiplyHead = top.GetHead();

	for (unsigned int i = 0; i < topData.size(); i++)
	{
		float topB = (float)top.GetData()[i].GetBlue();
		float topG = (float)top.GetData()[i].GetGreen();
		float topR = (float)top.GetData()[i].GetRed();
					 
		float botB = (float)bottom.GetData()[i].GetBlue();
		float botG = (float)bottom.GetData()[i].GetGreen();
		float botR = (float)bottom.GetData()[i].GetRed();

		topB /= 255;
		topG /= 255;
		topR /= 255;

		botB /= 255;
		botG /= 255;
		botR /= 255;

		B = (topB * botB * 255) + 0.5f;
		G = (topG * botG * 255) + 0.5f;
		R = (topR * botR * 255) + 0.5f;

		Pixel newPixel((unsigned char)B, (unsigned char)G, (unsigned char)R);
		multiplyData.push_back(newPixel);
	}

	TGAImg multiplyImg(multiplyHead, multiplyData);

	return multiplyImg;
}

TGAImg TGABlender::Subtract(TGAImg& top, TGAImg& bottom)
{
	TGAHead subtractHead;
	vector<Pixel> topData, bottomData, subtractData;
	unsigned char B, G, R;

	topData = top.GetData();
	bottomData = bottom.GetData();

	subtractHead = top.GetHead();

	for (unsigned int i = 0; i < topData.size(); i++)
	{
		if (bottomData[i].GetBlue() - topData[i].GetBlue() < 0)
			B = 0;
		else if (bottomData[i].GetBlue() - topData[i].GetBlue() > 255)
			B = 255;
		else
			B = bottomData[i].GetBlue() - topData[i].GetBlue();

		if (bottomData[i].GetGreen() - topData[i].GetGreen() < 0)
			G = 0;
		else if (bottomData[i].GetGreen() - topData[i].GetGreen() > 255)
			G = 255;
		else
			G = bottomData[i].GetGreen() - topData[i].GetGreen();

		if (bottomData[i].GetRed() - topData[i].GetRed() < 0)
			R = 0;
		else if (bottomData[i].GetRed() - topData[i].GetRed() > 255)
			R = 255;
		else
			R = bottomData[i].GetRed() - topData[i].GetRed();

		Pixel newPixel(B, G, R);
		subtractData.push_back(newPixel);
	}

	TGAImg subtractImg(subtractHead, subtractData);

	return subtractImg;
}

TGAImg TGABlender::Screen(TGAImg& top, TGAImg& bottom)
{
	TGAHead screenHead;
	vector<Pixel> topData, bottomData, screenData;
	float B, G, R;

	topData = top.GetData();
	bottomData = bottom.GetData();

	screenHead = top.GetHead();

	for (unsigned int i = 0; i < topData.size(); i++)
	{
		float topB = (float)(topData[i].GetBlue() / 255);
		float topG = (float)(topData[i].GetGreen() / 255);
		float topR = (float)(topData[i].GetRed() / 255);

		float botB = (float)(bottomData[i].GetBlue() / 255);
		float botG = (float)(bottomData[i].GetGreen() / 255);
		float botR = (float)(bottomData[i].GetRed() / 255);

		if (1 - (1 - topB) * (1 - botB) > 1)
			B = 1;
		else if (1 - (1 - topB) * (1 - botB) < 0)
			B = 0;
		else
			B = 1 - (1 - topB) * (1 - botB);

		if (1 - (1 - topG) * (1 - botG) > 1)
			G = 1;
		else if (1 - (1 - topG) * (1 - botG) < 0)
			G = 0;
		else
			G = 1 - (1 - topG) * (1 - botG);

		if (1 - (1 - topR) * (1 - botR) > 1)
			R = 1;
		else if (1 - (1 - topR) * (1 - botR) < 0)
			R = 0;
		else
			R = 1 - (1 - topR) * (1 - botR);


		B *= 255;
		G *= 255;
		R *= 255;

		B = round(B);
		G = round(G);
		R = round(R);


		Pixel newPixel((unsigned char)B, (unsigned char)G, (unsigned char)R);
		screenData.push_back(newPixel);
	}

	TGAImg screenImg(screenHead, screenData);

	return screenImg;
}

TGAImg TGABlender::Overlay(TGAImg& top, TGAImg& bottom)
{
	TGAHead overlayHead;
	vector<Pixel> topData, bottomData, overlayData;
	float B, G, R;

	topData = top.GetData();
	bottomData = bottom.GetData();

	overlayHead = top.GetHead();

	for (unsigned int i = 0; i < topData.size(); i++)
	{
		float topB = (float)(topData[i].GetBlue() / 255);
		float topG = (float)(topData[i].GetGreen() / 255);
		float topR = (float)(topData[i].GetRed() / 255);

		float botB = (float)(bottomData[i].GetBlue() / 255);
		float botG = (float)(bottomData[i].GetGreen() / 255);
		float botR = (float)(bottomData[i].GetRed() / 255);

		if (botB > 0.5f)
		{
			if (1 - (2 * (1 - topB) * (1 - botB)) > 1)
				B = 1;
			else if (1 - (2 * (1 - topB) * (1 - botB)) < 0)
				B = 0;
			else
				B = 1 - (2 * (1 - topB) * (1 - botB));
		}
		else
		{
			if (2 * topB * botB > 1)
				B = 1;
			else if (2 * topB * botB < 0)
				B = 0;
			else
				B = 2 * topB * botB;
		}

		if (botG > 0.5f)
		{
			if (1 - (2 * (1 - topG) * (1 - botB)) > 1)
				B = 1;
			else if (1 - (2 * (1 - topB) * (1 - botG)) < 0)
				G = 0;
			else
				G = 1 - (2 * (1 - topG) * (1 - botG));
		}
		else
		{
			if (2 * topG * topG > 1)
				G = 1;
			else if (2 * topG * botG < 0)
				G = 0;
			else
				G = 2 * topG * botG;
		}

		if (botR > 0.5f)
		{
			if (1 - (2 * (1 - topR) * (1 - botR)) > 1)
				R = 1;
			else if (1 - (2 * (1 - topR) * (1 - botR)) < 0)
				R = 0;
			else
				R = 1 - (2 * (1 - topR) * (1 - botR));
		}
		else
		{
			if (2 * topR * botR > 1)
				R = 1;
			else if (2 * topR * botR < 0)
				R = 0;
			else
				R = 2 * topR * botR;
		}

		B *= 255;
		G *= 255;
		R *= 255;

		B = round(B);
		G = round(G);
		R = round(R);

		Pixel newPixel((unsigned char)B, (unsigned char)G, (unsigned char)R);
		overlayData.push_back(newPixel);
	}
		
		TGAImg overlayImg(overlayHead, overlayData);

		return overlayImg;
}

TGAImg TGABlender::AddToChannel(TGAImg& img, unsigned char val, char RGB)
{
	TGAHead imageHeader = img.GetHead();
	vector<Pixel> imageData;
	unsigned char B, G, R;

	if (RGB == 'B')
	{
		for (int i = 0; i < imageHeader.GetPixelCount(); i++)
		{
			if (img.GetData()[i].GetBlue() + val > 255)
				B = 255;
			else if (img.GetData()[i].GetBlue() + val < 0)
				B = 0;
			else
				B = img.GetData()[i].GetBlue() + val;

			G = img.GetData()[i].GetGreen();
			R = img.GetData()[i].GetRed();

			Pixel newPixel(B, G, R);
			imageData.push_back(newPixel);
		}
	}

	if (RGB == 'G')
	{
		for (int i = 0; i < imageHeader.GetPixelCount(); i++)
		{
			if (img.GetData()[i].GetGreen() + val > 255)
				G = 255;
			else if (img.GetData()[i].GetGreen() + val < 0)
				G = 0;
			else
				G = img.GetData()[i].GetGreen() + val;

			B = img.GetData()[i].GetBlue();
			R = img.GetData()[i].GetRed();

			Pixel newPixel(B, G, R);
			imageData.push_back(newPixel);
		}
	}

	if (RGB == 'R')
	{
		for (int i = 0; i < imageHeader.GetPixelCount(); i++)
		{
			if (img.GetData()[i].GetRed() + val > 255)
				R = 255;
			else if (img.GetData()[i].GetRed() + val < 0)
				R = 0;
			else
				R = img.GetData()[i].GetRed() + val;

			G = img.GetData()[i].GetGreen();
			B = img.GetData()[i].GetBlue();

			Pixel newPixel(B, G, R);
			imageData.push_back(newPixel);
		}
	}

	TGAImg image(imageHeader, imageData);

	return image;
}

TGAImg TGABlender::Scale(TGAImg& img, unsigned char val, char RGB)
{
	TGAHead imageHeader = img.GetHead();
	vector<Pixel> imageData;
	unsigned char B, G, R;

	if (RGB == 'B')
	{
		for (unsigned int i = 0; i < img.GetData().size(); i++)
		{
			if (img.GetData()[i].GetBlue() * val > 255)
				B = 255;
			else if (img.GetData()[i].GetBlue() * val < 0)
				B = 0;
			else
				B = img.GetData()[i].GetBlue() * val;

			G = img.GetData()[i].GetGreen();
			R = img.GetData()[i].GetRed();

			Pixel newPixel(B, G, R);
			imageData.push_back(newPixel);
		}
	}

	if (RGB == 'G')
	{
		for (unsigned int i = 0; i < img.GetData().size(); i++)
		{
			if (img.GetData()[i].GetGreen() * val > 255)
				G = 255;
			else if (img.GetData()[i].GetGreen() * val < 0)
				G = 0;
			else
				G = img.GetData()[i].GetGreen() * val;

			B = img.GetData()[i].GetBlue();
			R = img.GetData()[i].GetRed();

			Pixel newPixel(B, G, R);
			imageData.push_back(newPixel);
		}
	}

	if (RGB == 'R')
	{
		for (unsigned int i = 0; i < img.GetData().size(); i++)
		{
			if (img.GetData()[i].GetRed() * val > 255)
				R = 255;
			else if (img.GetData()[i].GetRed() * val < 0)
				R = 0;
			else
				R = img.GetData()[i].GetRed() * val;

			G = img.GetData()[i].GetGreen();
			B = img.GetData()[i].GetBlue();

			Pixel newPixel(B, G, R);
			imageData.push_back(newPixel);
		}
	}

	TGAImg image(imageHeader, imageData);

	return image;
}

TGAImg TGABlender::GetChannel(TGAImg& img, char RGB)
{
	TGAHead imageHeader = img.GetHead();
	vector<Pixel> imageData;
	unsigned char B, G, R;

	if (RGB == 'B')
	{
		for (unsigned int i = 0; i < img.GetData().size(); i++)
		{
			R = G = B = img.GetData()[i].GetBlue();

			Pixel newPixel(B, G, R);
			imageData.push_back(newPixel);
		}
	}

	if (RGB == 'G')
	{
		for (unsigned int i = 0; i < img.GetData().size(); i++)
		{
			R = G = B = img.GetData()[i].GetGreen();

			Pixel newPixel(B, G, R);
			imageData.push_back(newPixel);
		}
	}

	if (RGB == 'R')
	{
		for (unsigned int i = 0; i < img.GetData().size(); i++)
		{
			R = G = B = img.GetData()[i].GetRed();

			Pixel newPixel(B, G, R);
			imageData.push_back(newPixel);
		}
	}

	TGAImg image(imageHeader, imageData);

	return image;
}

TGAImg TGABlender::CombineChannels(TGAImg& red, TGAImg& green, TGAImg& blue)
{
	TGAHead imageHeader = red.GetHead();
	vector<Pixel> imageData;
	unsigned char B, G, R;

	for (unsigned int i = 0; i < red.GetData().size(); i++)
	{
		B = blue.GetData()[i].GetBlue();
		G = green.GetData()[i].GetGreen();
		R = red.GetData()[i].GetRed();

		Pixel newPixel(B, G, R);
		imageData.push_back(newPixel);
	}

	TGAImg image(imageHeader, imageData);

	return image;
}

TGAImg TGABlender::Rotate180(TGAImg& img)
{
	TGAHead imageHeader = img.GetHead();
	vector<Pixel> imageData;
	unsigned char B, G, R;

	for (int i = (img.GetData().size() - 1); i >= 0; i--)
	{
		B = img.GetData()[i].GetBlue();
		G = img.GetData()[i].GetGreen();
		R = img.GetData()[i].GetRed();

		Pixel newPixel(B, G, R);
		imageData.push_back(newPixel);
	}

	TGAImg image(imageHeader, imageData);

	return image;
}
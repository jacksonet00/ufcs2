#include <iostream>
#include <fstream>
#include <vector>
#include "Pixel.h"
#include "TGA_head.h"
#include "TGA_img.h"
#include "TGAReader.h"
#include "TGAWriter.h"
using namespace std;


int main()
{
	TGAReader read_car("input/car.tga");

	TGA_img car_img = read_car.ReadTGAImg(); // Reads 0 pixels consistently.

	TGAWriter write_car("output/car2.tga");

	write_car.WriteTGAImg(car_img);

	return 0;
}
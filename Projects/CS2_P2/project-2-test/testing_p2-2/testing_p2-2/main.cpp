#include <iostream>
#include <vector>
#include "Pixel.h"
#include "TGAHead.h"
#include "TGAImg.h"
#include "TGAReader.h"
#include "TGAWriter.h"
#include "TGABlender.h"
#include "TGATesting.h"
using namespace std;

int main()
{
	// Read in all the files.
	TGAImg car, circles, layer_blue, layer_green, layer_red, layer1, layer2, pattern1, pattern2, text, text2;

	TGAReader reader;
	TGABlender blender;
	TGAWriter writer;
	TGATesting test;

	reader.Open("input/car.tga");
	car = reader.ReadImg();

	reader.Open("input/circles.tga");
	circles = reader.ReadImg();

	reader.Open("input/layer_blue.tga");
	layer_blue = reader.ReadImg();

	reader.Open("input/layer_green.tga");
	layer_green = reader.ReadImg();

	reader.Open("input/layer_red.tga");
	layer_red = reader.ReadImg();

	reader.Open("input/layer1.tga");
	layer1 = reader.ReadImg();

	reader.Open("input/layer2.tga");
	layer2 = reader.ReadImg();

	reader.Open("input/pattern1.tga");
	pattern1 = reader.ReadImg();

	reader.Open("input/pattern2.tga");
	pattern2 = reader.ReadImg();

	reader.Open("input/text.tga");
	text = reader.ReadImg();

	reader.Open("input/text2.tga");
	text2 = reader.ReadImg();

	writer.Open("testing.tga");
	writer.WriteImg(car);

	// Task 1:
	TGAImg part1 = blender.Multiply(layer1, pattern1);
	writer.Open("output/part1.tga");
	writer.WriteImg(part1);
	reader.Open("examples/EXAMPLE_part1.tga");
	TGAImg EXAMPLE_part1 = reader.ReadImg();
	bool test1 = test.CompareTGA(part1, EXAMPLE_part1);
	test.PrintMsg(test1, 1);

	/*

	// Task 2:
	TGAImg part2 = blender.Subtract(layer2, car);
	writer.Open("output/part2.tga");
	writer.WriteImg(part2);
	reader.Open("examples/EXAMPLE_part2.tga");
	TGAImg EXAMPLE_part2 = reader.ReadImg();
	bool test2 = test.CompareTGA(part2, EXAMPLE_part2);
	test.PrintMsg(test2, 2);

	// Task 3:
	TGAImg temp3 = blender.Multiply(layer1, pattern2);
	TGAImg part3 = blender.Screen(text, temp3);
	writer.Open("output/part3.tga");
	writer.WriteImg(part3);
	reader.Open("examples/EXAMPLE_part3.tga");
	TGAImg EXAMPLE_part3 = reader.ReadImg();
	bool test3 = test.CompareTGA(part3, EXAMPLE_part3);
	test.PrintMsg(test3, 3);

	// Task 4:
	TGAImg temp4 = blender.Multiply(layer2, circles);
	TGAImg part4 = blender.Subtract(pattern2, temp4);
	writer.Open("output/part4.tga");
	writer.WriteImg(part4);
	reader.Open("examples/EXAMPLE_part4.tga");
	TGAImg EXAMPLE_part4 = reader.ReadImg();
	bool test4 = test.CompareTGA(part4, EXAMPLE_part4);
	test.PrintMsg(test4, 4);

	// Task 5:
	TGAImg part5 = blender.Overlay(layer1, pattern1); // Overlay is not working properly.
	writer.Open("output/part5.tga");
	writer.WriteImg(part5);
	reader.Open("examples/EXAMPLE_part5.tga");
	TGAImg EXAMPLE_part5 = reader.ReadImg();
	bool test5 = test.CompareTGA(part5, EXAMPLE_part5);
	test.PrintMsg(test5, 5);

	// Task 6:
	TGAImg part6 = blender.AddToChannel(car, 200, 'G');
	writer.Open("output/part6.tga");
	writer.WriteImg(part6);
	reader.Open("examples/EXAMPLE_part6.tga");
	TGAImg EXAMPLE_part6 = reader.ReadImg();
	bool test6 = test.CompareTGA(part4, EXAMPLE_part6);
	test.PrintMsg(test6, 6);

	// Task 7:
	TGAImg temp7 = blender.Scale(car, 4, 'R');
	TGAImg part7 = blender.Scale(temp7, 0, 'B');
	writer.Open("output/part7.tga");
	writer.WriteImg(part7);
	reader.Open("examples/EXAMPLE_part7.tga");
	TGAImg EXAMPLE_part7 = reader.ReadImg();
	bool test7 = test.CompareTGA(part7, EXAMPLE_part7);
	test.PrintMsg(test7, 7);

	// Task 8:
	TGAImg part8b = blender.GetChannel(car, 'B');
	TGAImg part8g = blender.GetChannel(car, 'G');
	TGAImg part8r = blender.GetChannel(car, 'R');
	writer.Open("output/part8_b.tga");
	writer.WriteImg(part8b);
	writer.Open("output/part8_g.tga");
	writer.WriteImg(part8g);
	writer.Open("output/part8_r.tga");
	writer.WriteImg(part8r);
	reader.Open("examples/EXAMPLE_part8_b.tga");
	TGAImg EXAMPLE_part8_b, EXAMPLE_part8_g, EXAMPLE_part8_r;
	EXAMPLE_part8_b = reader.ReadImg();
	reader.Open("examples/EXAMPLE_part8_g.tga");
	EXAMPLE_part8_g = reader.ReadImg();
	reader.Open("examples/EXAMPLE_part8_r.tga");
	EXAMPLE_part8_r = reader.ReadImg();
	bool test8b, test8g, test8r;
	test8b = test.CompareTGA(part8b, EXAMPLE_part8_b);
	test8g = test.CompareTGA(part8g, EXAMPLE_part8_g);
	test8r = test.CompareTGA(part8r, EXAMPLE_part8_r);
	test.PrintMsg((test8b && test8g && test8r), 8);

	// Task 9:
	TGAImg part9 = blender.CombineChannels(layer_red, layer_green, layer_blue);
	writer.Open("output/part9.tga");
	writer.WriteImg(part9);
	reader.Open("examples/EXAMPLE_part9.tga");
	TGAImg EXAMPLE_part9 = reader.ReadImg();
	bool test9 = test.CompareTGA(part9, EXAMPLE_part9);
	test.PrintMsg(test9, 9);

	// Task 10:
	TGAImg part10 = blender.Rotate180(text2);
	writer.Open("output/part10.tga");
	writer.WriteImg(part10);
	reader.Open("examples/EXAMPLE_part10.tga");
	TGAImg EXAMPLE_part10 = reader.ReadImg();
	bool test10 = test.CompareTGA(part10, EXAMPLE_part10);
	test.PrintMsg(test10, 10);

	// Extra Credit:
	//TGAImg extracredit = blender.Grid2X2(car, circles, pattern1, text);
	//writer.Open("output/extracredit.tga");
	//writer.WriteImg(extracredit);

	*/

	return 0;
}
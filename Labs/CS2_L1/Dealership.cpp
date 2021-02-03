#include <iostream>
#include <vector>
#include "Vehicle.h"
#include "Vehicle.cpp"
#include "Showroom.h"
#include "Showroom.cpp"
#include "Dealership.h"
#include "main.cpp"
#include <string>
using namespace std;

Dealership(string name = "Generic Dealership", unsigned int capacity = 0) {
	this -> name = name;
	this -> capacity = capacity;
	showroomCount = 0

}

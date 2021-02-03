#include <iostream>
#include <vector>
#include "Vehicle.h"
#include "Vehicle.cpp"
#include "Showroom.h"
#include "main.cpp"
#include "Dealership.h"
#include "Dealership.cpp"
#include <string>
using namespace std;

Showroom(string name = "Unnamed Showroom", unsigned int capacity = 0) {
	this -> name = name;
	this -> capacity = capacity;
	vehicleCount = 0;
}

vector<Vehicle> GetVehicleList() {
	return vehicleList;
}

void AddVehicle(Vehicle v) {
	if (vehicleCount >= cpacity) {
		cout << "Showroom is full! Cannot add" << v.GetYearMakeModel() << endl;
	}

	else {
		vehicleList.push_back(v);
		vehicleCount++
	}
}

void ShowInventory() {
	if (vehicleCount <= 0) {
		cout << name << " is empty!" << endl;
	}

	else {
		cout << "Vehicles in " << name << enl;

		for(int i = 0; i < vehicleCount; i++) {
			vehicleList.at(i).Display();
		}
	}
}

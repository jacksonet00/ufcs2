#include <iostream>
#include <vector>
#include "Vehicle.h"
#include "main.cpp"
#include "Showroom.h"
#include "Showroom.cpp"
#include "Dealership.h"
#include "Dealership.cpp"
#include <string>
using namespace std;

Vehicle() {
   make = "COP3503";
   model = "Rust Bucket";
   year = 1900;
   price = 0.00f;
   mileage = 0;
}

Vehicle(string make, string model, int year, float price, int mileage) {
   this -> make = make;
   this -> model = model;
   this -> year = year;
   this -> price = price;
   this -> mileage = mileage;
}

void Display() {
 
 cout << year << " " << make << " " << model << " $" << price << " " << mileage << endl;
   
}

string GetYearMakeModel() {

   string yearString = to_string(year);
   string info = yearString + " " + make + " " + model;

   return info;
}

float GetPrice() {

   return price;
}

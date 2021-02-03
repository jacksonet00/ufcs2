#include <string>
using namespace std;

class Vehicle {
   
  private:
     string make;
     string model;
     unsigned int year;
     float price;
     unsigned int mileage;
     
  public:
   Vehicle();
   Vehicle(string make, string model, int year, float price, int mileage);
   Vehicle() = default;
   void Display();
   string GetYearMakeModel();
   float GetPrice();
   
};

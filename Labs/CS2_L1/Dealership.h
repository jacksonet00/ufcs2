#include <string>
using namespace std;

class Dealership {

private:
	vector<Showroom> showroomList;
	string name;
	int capacity;
	int showroomCount;

public:
	Dealership(string name = "Generic Dealership", unsigned int capacity = 0);
	void AddShowroom(Showroom s);
	float GetAveragePrice();
	void ShowInventory();

};

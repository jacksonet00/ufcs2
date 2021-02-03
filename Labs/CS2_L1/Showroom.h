#include <string>
#include <vector>
using namespace std;

class Showroom {

private:
	string name;
	vector<Vehicle> vehicleList;
	int capacity;
	int vehicleCount;

public:
	Showroom(string name = "Unnamed Showroom", unsigned int cpaacity = 0);
	vector<Vehicle> GetVehicleList();
	void AddVehicle(Vehicle v);
	void ShowInventory();
	float GetInventoryValue();

};

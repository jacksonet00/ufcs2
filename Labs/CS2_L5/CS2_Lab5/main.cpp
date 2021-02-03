#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <climits>
using namespace std;

struct Weapon
{
	string name;
	int power;
	float powerLevel;
	Weapon(string n, int p, float pl);
};

struct Starship
{
	string name;
	string cls;
	short length;
	int capacity;
	float speed;
	vector<Weapon> inventory;
	Starship(string n, string c, short l, int cap, float s, vector<Weapon> inv);
};

void loadData(string path, vector<Starship>& data);
void PrintAll(vector<Starship>& data);
void PrintShip(Starship& ship);
void StrongestWeaponOwner(vector<Starship>& data);
void StrongestShip(vector<Starship>& data);
void WeakestShip(vector<Starship>& data);
void UnarmedShips(vector<Starship>& data);

int main()
{
	cout << "Which file(s) to open?\n";
	cout << "1. friendlyships.shp" << endl;
	cout << "2. enemyships.shp" << endl;
	cout << "3. Both files" << endl;
	int option;
	cin >> option;

	/* Load files here */

	string path1 = "friendlyships.shp";
	string path2 = "enemyships.shp";
	vector<Starship> data;

	switch (option)
	{
	case 1:
		loadData(path1, data);
		break;
	case 2:
		loadData(path2, data);
		break;
	case 3:
		loadData(path1, data);
		loadData(path2, data);
		break;
	default:
		cout << "Please select a valid option from the menu." << endl;
		break;
	}

	cout << "1. Print all ships" << endl;
	cout << "2. Starship with the strongest weapon" << endl;
	cout << "3. Strongest starship overall" << endl;
	cout << "4. Weakest ship (ignoring unarmed)" << endl;
	cout << "5. Unarmed ships" << endl;

	cin >> option;

	/* Work your magic here */

	switch (option)
	{
	case 1:
		PrintAll(data);
		break;
	case 2:
		StrongestWeaponOwner(data);
		break;
	case 3:
		StrongestShip(data);
		break;
	case 4:
		WeakestShip(data);
		break;
	case 5:
		UnarmedShips(data);
		break;
	default:
		cout << "Please select a valid option from the menu." << endl;
		break;
	}

	return 0;
}

void loadData(string path, vector<Starship>& data)
{
	ifstream binaryIn(path);

	int count;
	binaryIn.read((char*)&count, sizeof(count));

	while (count > 0)
	{
		// Read Name of Starship
		int inNameLen;
		char* inName;
		binaryIn.read((char*)&inNameLen, sizeof(inNameLen));
		inName = new char[inNameLen];
		binaryIn.read(inName, inNameLen);

		// Read Class of Starship
		int inClassLen;
		char* inClass;
		binaryIn.read((char*)&inClassLen, sizeof(inClassLen));
		inClass = new char[inClassLen];
		binaryIn.read(inClass, inClassLen);

		// Read Length of Starship (m)
		short inLength;
		binaryIn.read((char*)&inLength, sizeof(inLength));

		// Read Capacity of Starship (TJ)
		int inCap;
		binaryIn.read((char*)&inCap, sizeof(inCap));

		// Read Speed of Starship
		float inSpeed;
		binaryIn.read((char*)&inSpeed, sizeof(inSpeed));

		// Read Weapons in Starship Inventory
		int weaponsCount;
		vector<Weapon> inInventory;
		binaryIn.read((char*)&weaponsCount, sizeof(weaponsCount));

		while (weaponsCount > 0)
		{
			// Read Name of Weapon
			int wNameLen;
			char* wName;
			binaryIn.read((char*)&wNameLen, sizeof(wNameLen));
			wName = new char[wNameLen];
			binaryIn.read(wName, wNameLen);

			// Read Power of Weapon
			int wPower;
			binaryIn.read((char*)&wPower, sizeof(wPower));

			// Read Power Level of Weapon
			float wPowerLevel;
			binaryIn.read((char*)&wPowerLevel, sizeof(wPowerLevel));

			// Add Weapon to Inventory
			Weapon newWeapon(wName, wPower, wPowerLevel);
			inInventory.push_back(newWeapon);

			weaponsCount--;
		}

		// Store Starship in Vector
		Starship newStarship(inName, inClass, inLength, inCap, inSpeed, inInventory);
		data.push_back(newStarship);

		count--;
	}
}

Starship::Starship(string n, string c, short l, int cap, float s, vector<Weapon> inv)
{
	name = n;
	cls = c;
	length = l;
	capacity = cap;
	speed = s;
	inventory = inv;
}

Weapon::Weapon(string n, int p, float pl)
{
	name = n;
	power = p;
	powerLevel = pl;
}

void PrintAll(vector<Starship>& data)
{
	for (unsigned int i = 0; i < data.size(); i++)
	{
		PrintShip(data[i]);
	}
}

void PrintShip(Starship& ship)
{
	cout << "Name: " << ship.name << endl;
	cout << "Class: " << ship.cls << endl;
	cout << "Length: " << ship.length << endl;
	cout << "Shield capacity: " << ship.capacity << endl;
	cout << "Maximum Warp: " << ship.speed << endl;
	cout << "Armaments: " << endl;

	if (ship.inventory.size() == 0)
	{
		cout << "Unarmed" << endl;
	}
	else
	{
		int totalPower = 0;

		for (unsigned int i = 0; i < ship.inventory.size(); i++)
		{
			cout << ship.inventory[i].name << ", " << ship.inventory[i].power << ", " << ship.inventory[i].powerLevel << endl;
			totalPower += ship.inventory[i].power;
		}

		cout << "Total firepower: " << totalPower << endl;
	}

	cout << "\n";
}

void StrongestWeaponOwner(vector<Starship>& data)
{
	if (data.size() > 0)
	{
		Starship max = data[0];
		int maxVal = 0;

		for (unsigned int i = 0; i < data.size(); i++)
		{
			for (unsigned int j = 0; j < data[i].inventory.size(); j++)
			{
				if (data[i].inventory[j].power > maxVal)
				{
					max = data[i];
					maxVal = data[i].inventory[j].power;
				}
			}
		}

		PrintShip(max);
	}
}

void StrongestShip(vector<Starship>& data)
{
	if (data.size() > 0)
	{
		Starship max = data[0];
		int maxVal = 0;

		for (unsigned int i = 0; i < data.size(); i++)
		{
			if (data[i].inventory.size() > 0)
			{
				int tempTotal = 0;

				for (unsigned int j = 0; j < data[i].inventory.size(); j++)
				{
					tempTotal += data[i].inventory[j].power;
				}

				if (tempTotal > maxVal)
				{
					max = data[i];
					maxVal = tempTotal;
				}
			}
		}

		PrintShip(max);
	}
}

void WeakestShip(vector<Starship>& data)
{
	if (data.size() > 0)
	{
		Starship min = data[0];
		int minVal = INT_MAX;

		for (unsigned int i = 0; i < data.size(); i++)
		{
			if (data[i].inventory.size() > 0)
			{
				int tempTotal = 0;

				for (unsigned int j = 0; j < data[i].inventory.size(); j++)
				{
					tempTotal += data[i].inventory[j].power;
				}

				if (tempTotal < minVal)
				{
					min = data[i];
					minVal = tempTotal;
				}
			}
		}

		PrintShip(min);
	}
}

void UnarmedShips(vector<Starship>& data)
{
	if (data.size() > 0)
	{
		vector<Starship> unarmedShipList;
		for (unsigned int i = 0; i < data.size(); i++)
		{
			if (data[i].inventory.size() == 0)
			{
				unarmedShipList.push_back(data[i]);
			}
		}

		PrintAll(unarmedShipList);
	}
}
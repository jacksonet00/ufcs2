#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <map>
#include <random>
#include <ctime>
using namespace std;

struct State
{
	string name;
	int income;
	long population;
	int houseIncome;
	int numHouseholds;
	State(string n = "", int i = 0, long p = 0, int hi = 0, int nh = 0);
};

void RollDice(int numberOfRolls, int numberOfSides);
int Random(int min, int max);
void LoadStates(const char* path, map<string, State>& data);
void PrintStates(map<string, State>& data);
void PrintState(State& data);
void SearchStates(string& search, map<string, State>& data);

mt19937 random_mt;

int Random(int min, int max)
{
	uniform_int_distribution<int> dist(min, max);
	return dist(random_mt);
}

int main()
{
	cout << "1. Random Numbers\n";
	cout << "2. State Info\n";

	int option;
	cin >> option;

	if (option == 1)
	{
		int randomSeed;
		cout << "Random seed value: ";
		cin >> randomSeed;
		random_mt.seed(randomSeed);

		int numRolls, numSides;
		cout << "Number of times to roll the die: ";
		cin >> numRolls;

		cout << "Number of sides on this die: ";
		cin >> numSides;

		RollDice(numRolls, numSides);
	}
	else if (option == 2)
	{
		map<string, State> states;
		LoadStates("states.csv", states);

		cout << "1. Print all states" << endl;
		cout << "2. Search for a state" << endl;
		
		cin >> option;
		
		if (option == 1)
		{
			PrintStates(states);
		}
		else if (option == 2)
		{
			string term;
			cin >> term;
			SearchStates(term, states);
		}
	}

	return 0;
}

State::State(string n, int i, long p, int hi, int nh)
{
	name = n;
	income = i;
	population = p;
	houseIncome = hi;
	numHouseholds = nh;
}

void RollDice(int numberOfRolls, int numberOfSides)
{
	map<int, int> diceRolls;

	for (int i = 1; i <= numberOfSides; i++)
	{
		diceRolls[i] = 0;
	}

	for (int i = 0; i < numberOfRolls; i++)
	{
		int roll = Random(1, numberOfSides);
		diceRolls[roll]++;
	}

	for (auto iter = diceRolls.begin(); iter != diceRolls.end(); ++iter)
	{
		cout << iter->first << ": " << iter->second << endl;
	}
}

void LoadStates(const char* path, map<string, State>& data)
{
	ifstream file(path);

	if (file.is_open())
	{
		string line;
		string name, income, population, houseIncome, numHouseholds;

		// Remove headings
		getline(file, line);

		while (!file.eof())
		{
			getline(file, line);

			istringstream stream(line);

			getline(stream, name, ',');
			getline(stream, income, ',');
			getline(stream, population, ',');
			getline(stream, houseIncome, ',');
			getline(stream, numHouseholds, ',');

			State newState(name, stoi(income), stol(population), stoi(houseIncome), stoi(numHouseholds));

			data.emplace(name, newState);
		}
	}
}

void PrintStates(map<string, State>& data)
{
	for (auto iter = data.begin(); iter != data.end(); ++iter)
	{
		PrintState(iter->second);
		cout << endl;
	}
}

void PrintState(State& data)
{
	cout << data.name << endl;
	cout << "Population: " << data.population << endl;
	cout << "Per Capita Income: " << data.income << endl;
	cout << "Median Household Income: " << data.houseIncome << endl;
	cout << "Number of Households: " << data.numHouseholds << endl;
}

void SearchStates(string& search, map<string, State>& data)
{
	if (data.find(search) != data.end())
		PrintState(data[search]);
	else
		cout << "No match found for " << search << endl;
}
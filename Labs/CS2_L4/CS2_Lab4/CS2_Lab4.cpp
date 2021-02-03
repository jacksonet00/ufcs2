#include <iomanip>
#include <iostream>
#include<fstream>
#include<sstream>
#include<vector>
using namespace std;

struct LegoSet
{
	string number;
	string theme;
	string name;
	int pieceCount;
	int miniFigCount;
	double price;
};

//Prototypes
void loadData(string path, vector<LegoSet>& data);
void maxPrice(vector<LegoSet>& data);
void maxPieceCount(vector<LegoSet>& data);
void searchByName(string name, vector<LegoSet>& data);
void searchByTheme(string theme, vector<LegoSet>& data);
void partCountInfo(vector<LegoSet>& data);
void priceInfo(vector<LegoSet>& data);
void miniFigInfo(vector<LegoSet>& data);
void oneOfEverything(vector<LegoSet>& data);
void printSet(LegoSet& set);
void simplePrintSet(LegoSet& set);


int main()
{
	cout << std::fixed << setprecision(2);
	cout << "Which file(s) to open?\n";
	cout << "1. lego1.csv" << endl;
	cout << "2. lego2.csv" << endl;
	cout << "3. lego3.csv" << endl;
	cout << "4. All 3 files" << endl;
	int option;
	cin >> option;

	vector<LegoSet> data;

	string path1 = "lego1.csv";
	string path2 = "lego2.csv";
	string path3 = "lego3.csv";

	switch (option)
	{
	case 1:
		loadData(path1, data);
		break;
	case 2:
		loadData(path2, data);
		break;
	case 3:
		loadData(path3, data);
		break;
	case 4:
		loadData(path1, data);
		loadData(path2, data);
		loadData(path3, data);
		break;
	default:
		cout << "Please enter a valid integer 1-4." << endl;
		break;
	}


	cout << "1. Most Expensive set" << endl;
	cout << "2. Largest piece count" << endl;
	cout << "3. Search for set name containing..." << endl;
	cout << "4. Search themes..." << endl;
	cout << "5. Part count information" << endl;
	cout << "6. Price information" << endl;
	cout << "7. Minifigure information" << endl;
	cout << "8. If you bought one of everything..." << endl;
	cout << "0. Exit" << endl;

	int choice;
	cin >> choice;
	cin.get();  // Clear newline character for any later input

	cout << "Total number of sets: " << data.size() << "\n" << endl;

	string query;
	
	switch (choice)
	{
	case 1:
		maxPrice(data);
		break;
	case 2:
		maxPieceCount(data);
		break;
	case 3:
		getline(cin, query);
		searchByName(query, data);
		break;
	case 4:
		getline(cin, query);
		searchByTheme(query, data);
		break;
	case 5:
		partCountInfo(data);
		break;
	case 6:
		priceInfo(data);
		break;
	case 7:
		miniFigInfo(data);
		break;
	case 8:
		oneOfEverything(data);
		break;
	case 0:
		break;
	default:
		cout << "Please enter a valid integer 1-8 or 0 to close." << endl;
		break;
	}

	return 0;
}

void loadData(string path, vector<LegoSet>& data)
{
	ifstream file(path);

	if (file.is_open())
	{
		string line;
		string number, theme, name, miniFigCount, pieceCount, price;

		// Remove headings
		getline(file, line);

		while (!file.eof())
		{
			// 1. Get a line from the file
			getline(file, line);

			// 2. Break line into seperate pieces based on comma delimiter
			istringstream stream(line);

			getline(stream, number, ',');
			getline(stream, theme, ',');
			getline(stream, name, ',');
			getline(stream, miniFigCount, ',');
			getline(stream, pieceCount, ',');
			getline(stream, price, ',');

			LegoSet set;
			set.number = number;
			set.theme = theme;
			set.name = name;
			set.miniFigCount = stoi(miniFigCount);
			set.pieceCount = stoi(pieceCount);
			set.price = stod(price);

			data.push_back(set);

		}
	}
	
}

void maxPrice(vector<LegoSet>& data)
{
	LegoSet max = data.at(0);

	for (unsigned int i = 0; i < data.size(); i++)
	{
		if (data.at(i).price > max.price)
			max = data.at(i);
	}

	cout << "The most expensive set is:" << endl;
	printSet(max);
}

void maxPieceCount(vector<LegoSet>& data)
{
	LegoSet max = data.at(0);

	for (unsigned int i = 0; i < data.size(); i++)
	{
		if (data.at(i).pieceCount > max.pieceCount)
			max = data.at(i);
	}

	cout << "The set with the highest parts count:" << endl;
	printSet(max);
}

void searchByName(string name, vector<LegoSet>& data)
{
	vector<LegoSet> results;
	
	for (unsigned int i = 0; i < data.size(); i++)
	{
		if (data.at(i).name.find(name) != string::npos)
		{
			results.push_back(data.at(i));
		}
	}

	if (results.size() == 0)
		cout << "No sets found matching that search term" << endl;
	else
	{
		cout << "Sets matching \"" << name << "\":" << endl;

		for (unsigned int i = 0; i < results.size(); i++)
		{
			simplePrintSet(results.at(i));
		}
	}
}

void searchByTheme(string theme, vector<LegoSet>& data)
{
	cout << "Sets matching \"" << theme << "\":" << endl;

	for (unsigned int i = 0; i < data.size(); i++)
	{
		if (data.at(i).theme == theme)
			simplePrintSet(data.at(i));
	}
}

void partCountInfo(vector<LegoSet>& data)
{
	int total = 0;
	int avg = 0;

	for (unsigned int i = 0; i < data.size(); i++)
		total += data.at(i).pieceCount;

	avg = total / data.size();

	cout << "Average part count for " << data.size() << " sets: " << avg << endl;
}

void priceInfo(vector<LegoSet>& data)
{
	double total = 0;
	double avg = 0;
	LegoSet min = data.at(0);
	LegoSet max = data.at(0);

	for (unsigned int i = 0; i < data.size(); i++)
	{
		total += data.at(i).price;

		if (data.at(i).price < min.price)
			min = data.at(i);

		if (data.at(i).price > max.price)
			max = data.at(i);
	}

	avg = total / data.size();

	cout << "Average price for " << data.size() << " sets: $" << avg << endl;
	cout << endl;

	cout << "Least expensive set:" << endl;
	printSet(min);
	
	cout << endl;

	cout << "Most expensive set:" << endl;
	printSet(max);
}

void miniFigInfo(vector<LegoSet>& data)
{
	int total = 0;
	int avg = 0;
	LegoSet max = data.at(0);

	for (unsigned int i = 0; i < data.size(); i++)
	{
		total += data.at(i).miniFigCount;

		if (data.at(i).miniFigCount > max.miniFigCount)
			max = data.at(i);
	}

	avg = total / data.size();

	cout << "Average number of minifigures: " << avg << endl;
	cout << "Set with the most minifigures:" << endl;
	printSet(max);
}

void oneOfEverything(vector<LegoSet>& data)
{
	double totalPrice = 0;
	int totalPieceCount = 0;
	int totalFigCount = 0;

	for (unsigned int i = 0; i < data.size(); i++)
	{
		totalPrice += data.at(i).price;
		totalPieceCount += data.at(i).pieceCount;
		totalFigCount += data.at(i).miniFigCount;
	}

	cout << "If you bought one of everything..." << endl;
	cout << "It would cost: $" << totalPrice << endl;
	cout << "You would have " << totalPieceCount << " pieces in your collection" << endl;
	cout << "You would have an army of " << totalFigCount << " minifigures!" << endl;
}

void printSet(LegoSet& set)
{
	cout << "Name: " << set.name << endl;
	cout << "Number: " << set.number << endl;
	cout << "Theme: " << set.theme << endl;
	cout << "Price: $" << set.price << endl;
	cout << "Minifigures: " << set.miniFigCount << endl;
	cout << "Piece count: " << set.pieceCount << endl;
}

void simplePrintSet(LegoSet& set)
{
	cout << set.number << " " << set.name << " $" << set.price << endl;
}
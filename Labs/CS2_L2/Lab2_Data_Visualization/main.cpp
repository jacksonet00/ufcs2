#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

int main()
{
    string dataTitle;
    string columnOneTitle;
    string columnTwoTitle;
    string dataPoint;

    string dataString;
    vector<string> dataStrings;

    int dataInt;
    vector<int> dataInts;

    //Prompt the user for a title for data. Output the title
    cout << "Enter a title for the data:" << endl;
    getline(cin, dataTitle);
    cout << "You entered: " << dataTitle << "\n" << endl;

    //Prompt the user for the headers of two columns of a table. Output the column headers
    cout << "Enter the column 1 header:" << endl;
    getline(cin, columnOneTitle);
    cout << "You entered: " << columnOneTitle << "\n" << endl;

    cout << "Enter the column 2 header:" << endl;
    getline(cin, columnTwoTitle);
    cout << "You entered: " << columnTwoTitle << "\n" << endl;

    //Prompt the user for data points in format (string, int)
    while (true) {

        cout << "Enter a data point (-1 to stop input):" << endl;
        getline(cin, dataPoint);

        if (dataPoint == "-1") {
            break;
        }
        else {
            //find comma count errors
            int numCommas = 0;
            for (unsigned int i = 0; i < dataPoint.size(); i++) {
                if (dataPoint[i] == ',') {
                    numCommas++;
                }
            }
            //print errors
            if (numCommas == 0) {
                cout << "Error: No comma in string.\n" << endl;
            }
            if (numCommas > 1) {
                cout << "Error: Too many commas in input.\n" << endl;
            }

            if (numCommas == 1) {

                int commaInt = dataPoint.find(',');

                //error checking for stoi function
                try {
                    dataString = dataPoint.substr(0, commaInt);
                    dataInt = stoi(dataPoint.substr(commaInt + 1));

                    dataStrings.push_back(dataString);
                    dataInts.push_back(dataInt);

                    cout << "Data string: " << dataString << endl;
                    cout << "Data integer: " << dataInt << "\n" << endl;
                }

                catch (invalid_argument&) {
                    cout << "Error: Comma not followed by an integer.\n" << endl;
                }
            }
        }
    }

    //Output the information in a formatted table
    cout << endl;
    cout << setw(33) << dataTitle << endl;
    cout << setw(20) << left << columnOneTitle << "|" << setw(23) << right << columnTwoTitle << endl;
    cout << "--------------------------------------------" << endl;

    //print data to table
    for (unsigned int i = 0; i < dataStrings.size(); i++) {
        cout << setw(20) << left << dataStrings.at(i) << "|" << setw(23) << right << dataInts.at(i) << endl;
    }

    cout << endl;

    //Output the information as a formatted histogram
    for (unsigned int i = 0; i < dataStrings.size(); i++) {
        cout << setw(20) << dataStrings.at(i) << " ";
        for (int j = 0; j < dataInts.at(i); j++) {
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}
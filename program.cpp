#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
#include <algorithm>

using namespace std;

struct AirlineData {
    string airline;
    long long avail_seat_km_per_week;       
    int incidents_85_99;
    int incidents_00_14;

    int totalIncidents() const {
        return incidents_85_99 + incidents_00_14;
    }
};

/************************************************************
 *                       Read the file                        *
 ************************************************************/
void readFile(const string& filename, vector<AirlineData>& airlines) {
    ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        cerr << "Error opening input file: " << filename << endl;
        return;
    }

    string line;
    getline(inputFile, line); // Skip header line
    while (getline(inputFile, line)) {
        stringstream ss(line);
        AirlineData data;
        getline(ss, data.airline, ','); 
        ss >> data.avail_seat_km_per_week; 
        ss.ignore(); 
        ss >> data.incidents_85_99; 
        ss.ignore(); 
        ss >> data.incidents_00_14; 
        airlines.push_back(data);
    }

    inputFile.close();
}

/************************************************************
 *                        DisplayAirline                    *
 ************************************************************/
void displayAirlineData(const vector<AirlineData>& airlines) {
    cout << left << setw(26) << "Airline"
         << setw(20) << "Available Seat KM"
         << setw(15) << "Incidents (85-99)"
         << setw(15) << "Incidents (00-14)"
         << setw(10) << "Total Incidents"
         << endl;

    cout << string(150, '-') << endl;

    for (vector<AirlineData>::const_iterator it = airlines.begin(); it != airlines.end(); ++it) {
        const AirlineData& airline = *it;
        cout << left << setw(29) << airline.airline
             << setw(28) << airline.avail_seat_km_per_week
             << setw(22) << airline.incidents_85_99
             << setw(18) << airline.incidents_00_14
             << setw(10) << airline.totalIncidents() // Display total incidents
             << endl;
    }
}

/************************************************************
 *                        bubbleSort                        *
 ************************************************************/
void bubbleSort(vector<AirlineData>& data) {
    bool madeASwap;
    int swapsMade = 0;

    do {
        madeASwap = false;
        for (size_t i = 0; i < data.size() - 1; ++i) {
            if (data[i].totalIncidents() > data[i + 1].totalIncidents()) { // Ascending order
                swap(data[i], data[i + 1]);
                madeASwap = true;
                swapsMade++;
            }
        }
    } while (madeASwap);

    cout << "Bubble sort made " << swapsMade << " swaps in ascending order based on the total incidents:" << endl;
    displayAirlineData(data);

    // Write sorted data to a file
    ofstream outputFile("DataBubbleSorted.csv");
    if (outputFile.is_open()) {
        outputFile << "Airline,Available Seat KM,Incidents (85-99),Incidents (00-14),Total Incidents\n"; // Header
        for (vector<AirlineData>::const_iterator it = data.begin(); it != data.end(); ++it) {
            const AirlineData& airline = *it;
            outputFile << airline.airline << ","
                       << airline.avail_seat_km_per_week << ","
                       << airline.incidents_85_99 << ","
                       << airline.incidents_00_14 << ","
                       << airline.totalIncidents() << "\n";
        }
        outputFile.close();
    } else {
        cerr << "Error opening output file for bubble sort." << endl;
    }
}

/**************************************************************
 *                        selectionSort                       *
 **************************************************************/
void selectionSort(vector<AirlineData>& data) {
    int n = data.size();
    int swapsMade = 0;

    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (data[j].totalIncidents() < data[minIndex].totalIncidents()) { 
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(data[i], data[minIndex]);
            swapsMade++;
        }
    }
    
    cout << "Selection sort made " << swapsMade << " swaps in ascending order based on the total incidents." << endl;
    displayAirlineData(data);

    // Write sorted data to a file
    ofstream outputFile("DataSelectionSorted.csv");
    if (outputFile.is_open()) {
        outputFile << "Airline,Available Seat KM,Incidents (85-99),Incidents (00-14),Total Incidents\n"; // Header
        for (vector<AirlineData>::const_iterator it = data.begin(); it != data.end(); ++it) {
            const AirlineData& airline = *it;
            outputFile << airline.airline << ","
                       << airline.avail_seat_km_per_week << ","
                       << airline.incidents_85_99 << ","
                       << airline.incidents_00_14 << ","
                       << airline.totalIncidents() << "\n";
        }
        outputFile.close();
    } else {
        cerr << "Error opening output file for selection sort." << endl;
    }
}

int main() {
    vector<AirlineData> airlines;
    readFile("airline-safety.csv", airlines);
    
    // Display unsorted airline data
    cout << left << setw(20) << string(100,'*') << endl;
    cout << endl << endl;
    cout << left << setw(30) << "  Unsorted Airlines Data " << endl;
    cout << endl << endl;
    cout << left << setw(20) <<string(100, '*') << endl;
    cout << endl;
    displayAirlineData(airlines);
    cout << "\n\n\n";
    
    // Create a copy for bubble sort
    vector<AirlineData> airlinesBubble = airlines;

    // Sort and display airline data
    cout << left << setw(20) << string(100, '*') << endl;
    cout << endl << endl;
    cout << left << setw(30) << "Bubble Sorted Airlines Data (by total incidents)" << endl;
    cout << endl << endl;
    cout << left << setw(20) << string(100, '*') << endl;
    bubbleSort(airlinesBubble);
    cout << "\n\n\n";

    // Create a copy for selection sort
    vector<AirlineData> airlinesSelection = airlines;

    // Sort and display airline data
    cout << left << setw(20) << string(100, '*') << endl;
    cout << endl << endl;
    cout << left << setw(30) << "Selection Sorted Airlines Data (by total incidents)" << endl;
    cout << endl << endl;
    cout << left << setw(20) << string(100, '*') << endl;
    selectionSort(airlinesSelection);
    cout << "\n\n\n";
    
    return 0;
}

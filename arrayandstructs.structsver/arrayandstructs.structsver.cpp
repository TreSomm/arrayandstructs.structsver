#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>

using namespace std;

const int numd = 7;

struct Runner {
    string name;
    int miles[numd];
    int totalMiles;
    double averageMiles;
};

void readDataFromFile(string filename, vector<Runner>& runners);
void calculateStats(vector<Runner>& runners);
void displayResults(const vector<Runner>& runners);

int main() {
    vector<Runner> runners;
    readDataFromFile("runners.txt", runners);
    calculateStats(runners);
    displayResults(runners);

    return 0;
}

void readDataFromFile(string filename, vector<Runner>& runners) {
    ifstream inputFile(filename);
    Runner runner;
    while (inputFile >> runner.name) {
        for (int i = 0; i < numd; ++i) {
            inputFile >> runner.miles[i];
        }
        runners.push_back(runner);
    }

    inputFile.close();
}

void calculateStats(vector<Runner>& runners) {
    for (Runner& runner : runners) {
        runner.totalMiles = 0;
        for (int i = 0; i < numd; ++i) {
            runner.totalMiles += runner.miles[i];
        }
        runner.averageMiles = static_cast<double>(runner.totalMiles) / numd;
    }
}

void displayResults(const vector<Runner>& runners) {
    cout << setw(10) << "Runner" << setw(10) << "Mon" << setw(10) << "Tue" << setw(10) << "Wed"
        << setw(10) << "Thu" << setw(10) << "Fri" << setw(10) << "Sat" << setw(10) << "Sun"
        << setw(15) << "Total" << setw(15) << "Average" << endl;

    for (const Runner& runner : runners) {
        cout << setw(10) << runner.name;
        for (int i = 0; i < numd; ++i) {
            cout << setw(10) << runner.miles[i];
        }
        cout << setw(15) << runner.totalMiles << setw(15) << fixed << setprecision(2) << runner.averageMiles << endl;
    }
}
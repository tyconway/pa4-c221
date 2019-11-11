#include <ctime>
#include <cstdlib>
#include <iostream>
#include <string>
#include "Utility.h"
using namespace std;

int main(int argc, char** argv) {
    cout << endl;

    srand(time(0));
    if (argc == 1) {
        sortFromFile("numbers.txt");
    } else if (argc == 2 && string(argv[1]) == "test") {
        // specify nothing
        timedSort();
    } else if (argc == 4 && string(argv[1]) == "test") {
        // specify everything
        timedSort(stoi(string(argv[2])), string(argv[3]));
    }
    else if (argc == 2) {
        cout << "Sorting from " << string(argv[1]) << endl;
        sortFromFile(string(argv[1]));
    } else {
        cout << "Invalid input.\n";
    }

}
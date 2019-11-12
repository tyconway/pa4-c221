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
        printf("<For use help, see README.>\n\n");
        sortFromFile("numbers.txt");
    } else if (argc == 2 && string(argv[1]) == "test") {
        // specify nothing
        printf("<For use help, see README.>\n\n");
        timedSort();
    } else if (argc == 4 && string(argv[1]) == "test") {
        // specify everything
        timedSort(stoi(string(argv[2])), string(argv[3]));
    }
    else if (argc == 2) {
        printf("<For use help, see README.>\n\n");
        cout << "Sorting from " << string(argv[1]);
        sortFromFile(string(argv[1]));
    } else {
        printf("<For use help, see README.>\n\n");
        cout << "Invalid input.\n";
    }

}
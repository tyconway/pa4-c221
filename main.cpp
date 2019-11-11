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
        cout << "WARNING: Not yet implemented.\n";
    } else if (argc == 2) {
        cout << "Sorting from " << string(argv[1]) << endl;
        sortFromFile(string(argv[1]));
    } else {
        cout << "Too many inputs. Please use only one.\n";
    }

}
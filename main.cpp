#include <iostream>
#include "Utility.h"
using namespace std;

int main(int argc, char** argv) {
    cout << endl;

    if (argc == 1) {
        cout << "Program expected a file input:\n"
             << "./a.out <filename.txt>\n"
             << "Filename \"numbers.txt\" assumed and proceeding...\n";
            int* data = parseFile("numbers.txt");
            int type = data[0];
            int count = data[1];
            int* numbers = new int[count];
            for (int index = 0; index < count; index++) {
                numbers[index] = data[index + 2];
            }
            sortArray(type, count, numbers);
    } else if (argc == 2) {
        cout << "Parsing " << argv[1] << " and sorting numbers:\n";
    } else {
        cout << "Too many inputs. Please use only one.\n";
    }

    cout << endl;
}
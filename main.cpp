#include <iostream>
using namespace std;

int main(int argc, char** argv) {
    cout << endl;

    if (argc == 1) {
        cout << "Program expected a file input:\n"
             << "./a.out <filename.txt>";
    } else if (argc == 2) {
        cout << "Parsing " << argv[1] << " and sorting numbers:\n";
    } else {
        cout << "Too many inputs. Please use only one.\n";
    }

    cout << endl;
}
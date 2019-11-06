#ifndef UTILITY_H
#define UTILITY_H

#include <fstream>
#include <string>
#include <exception>
#include "bubblesort.h"
#include "heapsort.h"
using namespace std;

void writeFile(int size, int* data) {
    ofstream ofs;
    ofs.open("output.txt");
    for (int i = 0; i < size; i++) {
        ofs << data[i] << endl;
    }
    ofs.close();
}

void sortArray(int type, int count, int* numbers) {
    // for (int i = 0; i < count; i++) {
    //     cout << numbers[i] << endl;
    // }
    try {
        if (type == 0) {
            writeFile(count, bubbleSort(count, numbers));
        } else if (type == 1) {
            writeFile(count, heapSort(count, numbers));
        } else if (type == 2) {
            // Merge 
        } else if (type == 3) {
            // Quick
        } else {
            // Invalid
        }
    }
    catch (const exception& e)
	{
		cerr << "\nException: " << e.what() << '\n';
	} 

    return;
}


int* parseFile(string filename) {
    ifstream fin;
    fin.open(filename);
    int n;
    // Skip first number
    fin >> n;
    fin >> n;
    int *arr = new int[n + 2];
    int number;
    fin.close();
    fin.open(filename);
    int i = 0;
    while (fin >> number) {
        arr[i] = number;
        i++;
    }
    return arr;
}

#endif
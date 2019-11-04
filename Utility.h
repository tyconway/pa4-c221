#ifndef UTILITY_H
#define UTILITY_H

#include <fstream>
#include <string>
#include "bubblesort.h"
using namespace std;

void sortArray(int type, int count, int* numbers) {
    // for (int i = 0; i < count; i++) {
    //     cout << numbers[i] << endl;
    // }

    if (type == 0) {
        // Bubble 
    } else if (type == 1) {
        // Heap
    } else if (type == 2) {
        // Merge 
    } else if (type == 3) {
        // Quick
    } else {
        // Invalid
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
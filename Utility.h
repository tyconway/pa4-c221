#ifndef UTILITY_H
#define UTILITY_H

#include <fstream>
#include <string>
#include <exception>
#include "bubblesort.h"
#include "heapsort.h"
#include "mergesort.h"
#include "quicksort.h"
using namespace std;

void writeFile(int size, int* data) {
    ofstream ofs;
    ofs.open("output.txt");
    for (int i = 0; i < size; i++) {
        ofs << data[i] << endl;
    }
    ofs.close();
}

void printArr(int count, int* arr) {
    cout << "[Arr]:\n";
    for (int i = 0; i < count; i++) {
        cout << arr[i] << endl;
    }
}

vector<int>* arrToVec(int count, int* numbers) {
    vector<int> *converted = new vector<int>();
    for (int i = 0; i < count; i++) {
        converted->push_back(numbers[i]);
    }
    return converted;
}

int* vecToArr(vector<int>* vec) {
    int* arr = new int[vec->size()];
    for (int i = 0; i < vec->size(); i++) {
        arr[i] = vec->at(i);
    }
    return arr;
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
            writeFile(count, mergeSort(count, numbers));
        } else if (type == 3) {
            vector<int> *vec = arrToVec(count, numbers);
            vec = quickSort(count, vec);
            int* arr = vecToArr(vec);
            writeFile(count, arr);
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
    fin.close();
    return arr;
}

void sortFromFile(string filename) {
    int* data = parseFile(filename);
    int type = data[0];
    int count = data[1];
    int* numbers = new int[count];
    for (int index = 0; index < count; index++) {
        numbers[index] = data[index + 2];
    }
    sortArray(type, count, numbers);
}

#endif
#ifndef UTILITY_H
#define UTILITY_H

#include <fstream>
#include <string>
#include <exception>
#include <chrono>
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
            writeFile(count, BubbleSort(count, numbers));
        } else if (type == 1) {
            writeFile(count, HeapSort(count, numbers));
        } else if (type == 2) {
            writeFile(count, MergeSort(count, numbers));
        } else if (type == 3) {
            vector<int> *vec = arrToVec(count, numbers);
            vec = QuickSort(count, vec);
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

enum listType { random, increasing, decreasing };

void log_csv(string filename, chrono::duration<double, nano> elapsed, int currPushCount)
{
    double microsecondsDenominator = 1000; 
    double elapsed_time = elapsed.count()/microsecondsDenominator;
    ofstream ofs;
    string csv_filename = "logs/" + filename + ".csv";
    ofs.open(csv_filename, ios::app);
    ofs << currPushCount << "," << elapsed_time << "\n";
    ofs.close();
}

int* generateList(int n, listType type) {
    // generate requested type
    int* numbers = new int[n];
    switch(type) {
        case random:
            for (int i = 0; i < n; i++) {
                int r = (rand() % n);
                numbers[i] = r;
            }
            break;
        case increasing:
            for (int i = 0; i < n; i++) {
                numbers[i] = i;
            }
            break;
        case decreasing:
            for (int i = 0; i < n; i++) {
                numbers[i] = n - i;
            }
            break;
    }
    return numbers;
}

void timedSort(int n = 1000, string selectedType = "random") {
    // Try to match type
    listType type;
    printf("Parsing type");
    if (selectedType == "random") {
        type = random;
    } else if (selectedType == "increasing") {
        type = increasing;
    } else if (selectedType == "decreasing") {
        type = decreasing;
    } else {
        cout << "Bad type.";
        return;
    }
    printf(", done.\n");
    // time trials
    printf("Starting time trials, ");
    auto start = chrono::high_resolution_clock::now();
    auto curr = chrono::high_resolution_clock::now();
    auto elapsed = curr - start;
    for (int trial = 0; trial <= n; trial += (n / 100)) {
        int* numbers = generateList(trial, type);

        start = chrono::high_resolution_clock::now();
        int* sortedBubble = BubbleSort(trial, numbers);
        curr = chrono::high_resolution_clock::now();
        elapsed = curr - start;
        log_csv(selectedType + "_bubble", elapsed, trial);

        start = chrono::high_resolution_clock::now();
        int* sortedHeap = HeapSort(trial, numbers);
        curr = chrono::high_resolution_clock::now();
        elapsed = curr - start;
        log_csv(selectedType + "_heap", elapsed, trial);

        start = chrono::high_resolution_clock::now();
        int* sortedMerge = MergeSort(trial, numbers);
        curr = chrono::high_resolution_clock::now();
        elapsed = curr - start;
        log_csv(selectedType + "_merge", elapsed, trial);

        // Convert numbers to vector
        vector<int>* vector = arrToVec(trial, numbers);
        start = chrono::high_resolution_clock::now();
        vector = QuickSort(trial, vector);
        curr = chrono::high_resolution_clock::now();
        elapsed = curr - start;
        log_csv(selectedType + "_quick", elapsed, trial);
        cout << "\r" << "Running time trials, " << trial;
    }
    cout << "\r" << "Running time trials, done.\n";
}

#endif
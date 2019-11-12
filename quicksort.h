#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <vector>
#include <ctime>
#include <cstdlib>
#include "Partitions.h"
using namespace std;

void print(vector<int>* vec) {
    cout << "Print:\n";
    for (int i = 0; i < vec->size(); i++) {
        cout << vec->at(i) << endl;
    }
}

Partitions* partition(vector<int>* S, int pivotIndex) {
    Partitions *partitions = new Partitions();
    int pivot = S->at(pivotIndex);
    partitions->E->push_back(pivot);
    S->erase(S->begin() + pivotIndex); 

    while (S->size() > 0) {
        int test = S->at(0);
        if (test < pivot) { partitions->L->push_back(test); }
        else if (test == pivot) { partitions->E->push_back(test); }
        else if (test > pivot) { partitions->G->push_back(test); }
        S->erase(S->begin());
    }
    return partitions;
}

vector<int>* concatenate(vector<int>* L, vector<int>* E, vector<int>* G) {
    for (int i = 0; i < E->size(); i++) {
        L->push_back(E->at(i));
    }
    for (int i = 0; i < G->size(); i++) {
        L->push_back(G->at(i));
    }
    return L;
}

vector<int>* QuickSort(int count, vector<int>* numbers) {
    if (numbers->size() <= 1) {
        return numbers;
    }
    int randomIndex = (rand() % count);
    Partitions *parts = partition(numbers, randomIndex);
    vector<int>* sortedL = QuickSort(parts->L->size(), parts->L);
    vector<int>* sortedG = QuickSort(parts->G->size(), parts->G);
    numbers = concatenate(sortedL, parts->E, sortedG);
    return numbers;
}

#endif
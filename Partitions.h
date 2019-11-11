#pragma once

#include <vector>
using namespace std;

struct Partitions {
public:
    vector<int> *L;
    vector<int> *E;
    vector<int> *G;
    Partitions() {
        L = new vector<int>();
        E = new vector<int>();
        G = new vector<int>();
    }
    void helpPrint(vector<int>* vec) {
        for (int i = 0; i < vec->size(); i++) {
            cout << vec->at(i) << " ";
        }
    }
    void print() {
        cout << "[L] ";
        helpPrint(L);
        cout << "[E] ";
        helpPrint(E);
        cout << "[G] ";
        helpPrint(G);
        cout << endl;
    }
};
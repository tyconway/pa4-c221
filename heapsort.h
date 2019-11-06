#pragma once

#include "heap.h"
using namespace std;

int* heapSort(int count, int* numbers) {
    Heap<int> *heap = new Heap<int>(numbers, count);
    for (int i = 0; i < count; i++) {
        numbers[i] = heap->removeMin();
    }
    return numbers;
}
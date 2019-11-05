#pragma once

using namespace std;

void swap(int left, int right, int* arr) {
    int temp = arr[left];
    arr[left] = arr[right];
    arr[right] = temp;
}

int* bubbleSort(int count, int* numbers) {
    bool swapped = false;
    do {
        swapped = false;
        for (int i = 0; i < count - 1; i++) {
            if (numbers[i] > numbers[i + 1]) {
                swap(i, i + 1, numbers);
                swapped = true;
            }
        }
    } while (swapped);
    return numbers;
}
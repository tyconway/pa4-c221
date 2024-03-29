#pragma once

using namespace std;

void swapBubble(int left, int right, int* arr) {
    int temp = arr[left];
    arr[left] = arr[right];
    arr[right] = temp;
}

int* BubbleSort(int count, int* numbers) {
    int unsorted = count - 1;
    bool swapped = false;
    do {
        swapped = false;
        for (int i = 0; i < unsorted; i++) {
            if (numbers[i] > numbers[i + 1]) {
                swapBubble(i, i + 1, numbers);
                swapped = true;
            }
        }
        unsorted--;
    } while (swapped);
    return numbers;
}
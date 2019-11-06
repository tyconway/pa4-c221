#pragma once

int* firstHalf(int count, int* numbers) {
    int* half = new int[count/2];
    for (int i = 0; i < count/2; i++) {
        half[i] = numbers[i];
    }
    return half;
}

int* lastHalf(int count, int* numbers) {
    int* half = new int[count - count/2];
    for (int i = 0; i < count/2; i++) {
        half[i] = numbers[i + count/2];
    }
    return half;
}

int* mergeSort(int count, int* numbers) {

    if (count > 1) {
        int* leftHalf = firstHalf(count, numbers);
        int* rightHalf = lastHalf(count, numbers);
    }

    return numbers;
}
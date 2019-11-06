#include <iostream>
using namespace std;

void print_array(int* numbers, int count ){
    cout << "Numbers:\n";
        for (int i = 0; i < count; i++) {
            cout << numbers[i] << endl;
        }
}

int* firstHalf(int count, int* numbers) {
    int* half = new int[count/2];
    for (int i = 0; i < count/2; i++) {
        half[i] = numbers[i];
    }
    return half;
}

int* lastHalf(int count, int* numbers) {
    int* half = new int[count - count/2];
    for (int i = 0; i < count - count/2; i++) {
        half[i] = numbers[i + count/2];
    }
    return half;
}

int* merge(int* left, int leftCount, int* right, int rightCount, int count) {
    int *merged = new int[count];
    int i = 0;
    int j = 0;
    int n = count;

    do {
        if (i == leftCount && j != rightCount) {
            // print out what's left of j
            merged[i + j] = right[j];
            j++;
        } else if (j == rightCount && i != leftCount) {
            // print out what's left of i
            merged[i + j] = left[i];
            i++;
        } else if (i == leftCount && j == rightCount) {
            break;
        } else if (left[i] <= right[j]) {
            merged[i + j] = left[i];
            i++;
        } else {
            merged[i + j] = right[j];
            j++;
        }
    } while ( (i + j) < n );
    return merged;
}

int* mergeSort(int count, int* numbers) {
    if (count > 1) {
        int* r = new int[count];
        int* leftHalf = firstHalf(count, numbers);
        int* rightHalf = lastHalf(count, numbers);
        int *leftHalfSorted = mergeSort(count/2, leftHalf);
        int *rightHalfSorted = mergeSort(count - count/2, rightHalf);
        r = merge(leftHalfSorted, count/2, rightHalfSorted, count - count/2, count);
        return r;
    }

    return numbers;
}
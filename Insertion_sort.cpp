#include <iostream>
using namespace std;

void insertionSort(int arr[], int n, bool ascending = true) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // Modify comparison based on sorting order
        while ((j >= 0) && ((ascending && arr[j] > key) || (!ascending && arr[j] < key))) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {55691, 55632, 55469, 55181, 55223, 56177, 56983};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original Array: ";
    printArray(arr, n);

    // Sort in ascending order
    insertionSort(arr, n, true);
    cout << "Sorted Array in Ascending Order: ";
    printArray(arr, n);

    // Sort in descending order
    insertionSort(arr, n, false);
    cout << "Sorted Array in Descending Order: ";
    printArray(arr, n);

    return 0;
}
#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n, bool ascending = true) {
    for(int i = 0; i < n - 1; i++) {
        
        for (int j = 0; j < n - i - 1; j++) {
            
            if ((ascending && arr[j] > arr[j + 1]) || (!ascending && arr[j] < arr[j + 1])) {

                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {55691, 55632, 55469, 55181, 55223, 56177, 56983};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original Array: ";
    printArray(arr, n);

    bubbleSort(arr, n, true);
    cout << "Sorted Array in Ascending Order: ";
    printArray(arr, n);

    bubbleSort(arr, n, false);
    cout << "Sorted Array in Descending Order: ";
    printArray(arr, n);

    return 0;
}
#include <iostream>
#include <algorithm>
using namespace std;

void display(int* arr, int n) {

    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return;
}

int partition(int* arr, int start, int end) {
    int pivot = arr[end];

    int i = start - 1;

    for(int j = start; j <= end; j++) {
        if(arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[end]);
    return i + 1;
}

void quickSort(int* arr, int start, int end) {

    // partition the array
    if(start < end) {

        int mid = partition(arr, start, end);
        quickSort(arr, start, mid - 1);
        quickSort(arr, mid + 1, end);
    }

    return;
}

int main() {
    int arr[] = {4, 2, 3, 5, 1, 4, 8, 9};

    int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, n - 1);

    display(arr, n);

    return 0;
}
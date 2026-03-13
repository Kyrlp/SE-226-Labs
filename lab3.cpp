#include <iostream>
#include <exception>
#include <iomanip>
using namespace std;

void swapValues(int* p1, int* p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << *(arr + i) << " ";
    }
    cout << endl;
}

int findMax(int* arr, int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max)
max = arr[i];}
    return max;
    }

void reverseArray(int* arr, int size) {
    for (int i = 0; i < size/2; i++) {
        swapValues(&arr[i], &arr[size-1-i]);
    }
}

int* createArray(int size) {
    return new int[size];

}
void deleteArray(int* arr) {
    delete[] arr;
}
int main() {
    cout << "Creating Dynamic Array..." << endl;

    int size;
    cout << "Enter Size of Array: ";
    cin >> size;
    int* arr = new int[size];
    createArray(size);
    cout << "Enter Array Elements: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
    cout << "Array Elements:" << endl;
    printArray(arr, size);
    cout << "Largest Element in Array:" << findMax(arr, size) << endl;



    cout << "swapping two elements: " << endl;
    int a = 8;
    int b = 10;
    cout << "before swap:" <<"\n a = " << a <<"\ b = " << b << endl;
    swapValues(&a, &b);
    cout << "after swap: " <<"\n a = " << a <<"\ b = " << b << endl;

    cout << "Reversing array..." << endl;
    reverseArray(arr, size);
    cout << "After reversing array: " << endl;
    printArray(arr, size);

    cout << "Deleting Array..." << endl;
    deleteArray(arr);
    cout << "Memory Released" << endl;
    return 0;



}
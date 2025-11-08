#include "MyArray.h"

MyArray::MyArray() {
    array = nullptr;
    size = 0;
}

MyArray::MyArray(int s) {
    size = s;
    array = new int[size];
    for (int i = 0; i < size; i++)
        array[i] = 0;
}
MyArray::MyArray(int* arr, int s) {
    size = s;
    array = new int[size];
    for (int i = 0; i < size; i++)
        array[i] = arr[i];
}

MyArray::MyArray(const MyArray& obj) {
    size = obj.size;
    array = new int[size];
    for (int i = 0; i < size; i++)
        array[i] = obj.array[i];
}

MyArray::~MyArray() {
    delete[] array;
}

void MyArray::fill() {
    if (array == nullptr) {
        cout << "Масив порожній!" << endl;
        return;
    }
    cout << "Введіть " << size << " елементів: " << endl;
    for (int i = 0; i < size; i++) {
        cout << "array[" << i << "] = ";
        cin >> array[i];
    }
}

void MyArray::print() {
    cout << "[ ";
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << "]" << endl;
}

void MyArray::resize(int newSize) {
    int* temp = new int[newSize];
    int limit = (newSize < size) ? newSize : size;

    for (int i = 0; i < limit; i++)
        temp[i] = array[i];

    for (int i = limit; i < newSize; i++)
        temp[i] = 0;

    delete[] array;
    array = temp;
    size = newSize;
}

void MyArray::sortArray() {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

int MyArray::minV() {
    if (size == 0) return 0;
    int min = array[0];
    for (int i = 1; i < size; i++)
        if (array[i] < min)
            min = array[i];
    return min;
}

int MyArray::maxV() {
    if (size == 0) return 0;
    int max = array[0];
    for (int i = 1; i < size; i++)
        if (array[i] > max)
            max = array[i];
    return max;
}

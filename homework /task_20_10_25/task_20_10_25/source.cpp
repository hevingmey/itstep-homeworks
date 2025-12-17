#include "MyArray.h"

MyArray::MyArray() {
    this->array = nullptr;
    this->size = 0;
}

MyArray::MyArray(int s) {
    this->size = s;
    this->array = new int[this->size];
    for (int i = 0; i < this->size; i++)
        this->array[i] = 0;
}

MyArray::MyArray(int* arr, int s) {
    this->size = s;
    this->array = new int[this->size];
    for (int i = 0; i < this->size; i++)
        this->array[i] = arr[i];
}

MyArray::MyArray(const MyArray& obj) {
    this->size = obj.size;
    this->array = new int[this->size];
    for (int i = 0; i < this->size; i++)
        this->array[i] = obj.array[i];
}

MyArray::~MyArray() {
    delete[] this->array;
}

void MyArray::fill() {
    if (this->array == nullptr) {
        cout << "Масив порожній!" << endl;
        return;
    }
    cout << "Введіть " << this->size << " елементів: " << endl;
    for (int i = 0; i < this->size; i++) {
        cout << "array[" << i << "] = ";
        cin >> this->array[i];
    }
}

void MyArray::print() {
    cout << "[ ";
    for (int i = 0; i < this->size; i++)
        cout << this->array[i] << " ";
    cout << "]" << endl;
}

void MyArray::resize(int newSize) {
    int* temp = new int[newSize];
    int limit = (newSize < this->size) ? newSize : this->size;

    for (int i = 0; i < limit; i++)
        temp[i] = this->array[i];

    for (int i = limit; i < newSize; i++)
        temp[i] = 0;

    delete[] this->array;
    this->array = temp;
    this->size = newSize;
}

void MyArray::sortArray() {
    for (int i = 0; i < this->size - 1; i++) {
        for (int j = 0; j < this->size - i - 1; j++) {
            if (this->array[j] > this->array[j + 1]) {
                int temp = this->array[j];
                
                this->array[j] = this->array[j + 1];
                this->array[j + 1] = temp;
           
            }
      
        }
   
}
}

int MyArray::minV() {
    
    if (this->size == 0) return 0;
    int min = this->array[0];
    for (int i = 1; i < this->size; i++)
        if (this->array[i] < min)
            
            min = this->array[i];
    
    return min;
}

int MyArray::maxV() {
    if (this->size == 0) return 0;
    int max = this->array[0];
    for (int i = 1; i < this->size; i++)
        if (this->array[i] > max)
            max = this->array[i];
    return max;
}

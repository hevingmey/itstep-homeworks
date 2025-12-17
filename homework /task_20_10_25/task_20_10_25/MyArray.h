#pragma once
#include <iostream>
using namespace std;

class MyArray {
private:
    int* array;   
    int size;

public:
    
    MyArray();
    MyArray(int s);
    MyArray(int* arr, int s);
    MyArray(const MyArray& obj);

    ~MyArray();

    void fill();
    void print();
    void resize(int newSize);
    void sortArray();
    int minV();
    int maxV();
};

#include <iostream>
#include "MyArray.h"
using namespace std;

int main() {
    MyArray a(5);
    a.fill();
    cout << "\nПочатковий масив: ";
    a.print();

    cout <<"mінімальне значення: " << a.minV() << endl;
    
    cout << "Максимальне значення: " << a.maxV() << endl;
    
    
    
    cout << "\nСортуємо масив" << endl;
    a.sortArray();
    a.print();

    
    
    
    cout << "\nЗмінюємо розмір " << endl;
    a.resize(7);
    a.print();

    
    
    cout << "\nКопіюємо масив  " << endl;
    MyArray b = a;
    b.print();

    return 0;
}

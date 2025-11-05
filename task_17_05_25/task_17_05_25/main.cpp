

#include <iostream>
using namespace std;
#include "MyString.h"

int main( ){

        MyString a("hello world");
        MyString b(11);

        cout << "a: "; a.print();
        cout << "b: "; b.print();

        cout << "str " << endl;
        b.setStr(nullptr);
        b.print(); 

        cout << "\n--- Виклик setStr(\"world!\") ---" << endl;
        a.setStr(" HI !");
        cout << "a після setStr: ";
        a.print();

        cout << "\nРозмір a: " << a.getSize() << endl;
        cout << "\nРозмір b: " << b.getSize() << endl;
    
    cout << "\nКількість створених рядків зараз: " << MyString::getCounter() << endl;

return 0;
}

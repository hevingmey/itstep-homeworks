#include <iostream>
#include "MyArray.h"
using namespace  std;
MyArray::MyArray():array{nullptr},size{0}{ }

MyArray::MyArray(int* ar,int si)
{
    if (ar !=nullptr && si>0)
    {
        size =si;
        array=new int[size];
        for ( int i=0;i<size;i++)
            array[i]=ar[i];
    }
    else{
        array=nullptr;
        size=0;
    }
    }

MyArray::~MyArray(){
    delete[] array;
    
}

int* MyArray::getArray(){
    return array;
}
int MyArray::getSize(){
    return size;
}

void MyArray::setArray(int*ar, int si){
    delete[] array;
    if (ar!=nullptr && si>0){
        size=si;
        array=new int[size];
        for(int i=0;i<size;i++)
            array[i]=ar[i];
    }
    else{
        array=nullptr;
        size=0;
    }
    }
int MyArray::sum(){
    int p=0;
    for (int i=0;i<size;i++){
        p+=array[i];}
    return p;
    }
    void MyArray::print()
    {
        cout<<"[";
        for(int i=0;i<size;i++){
            cout<<array[i];
            if (i!=size-1) cout<<", ";
        }
        cout<<" ]"<<endl;
    }

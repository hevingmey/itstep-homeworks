#include <iostream>
#include "MyString.h"
using namespace std;
#include <cstring>
int MyString::counter = 0;

MyString::MyString(){
    size=0;
    str=new char[1];
    str[0]='\n';
    counter++;
}
MyString::MyString( char* s){
    size=strlen(s);
    str=new char[size+1];
    strcpy(str, s);
    counter++;
}
MyString::MyString(size_t s){
    size=s;
    str=new char[size+1];
    for (size_t i=0;i<size;i++)
        str[i]='_';
    str[size]='\0';
    counter++;
}
MyString::~MyString(){
    delete[] str;
    counter--;
}

size_t MyString::getSize(){
    return size;
    
}
char* MyString::getStr(){
    return str;
}
int MyString::getCounter(){
    return counter;
}

void MyString::setStr(char* s)
{
    delete[] str;
    if (s != nullptr) {
        size = strlen(s);
        str = new char[size + 1];
        strcpy(str, s);
    }
    else {
        size = 0;
        str = new char[1];
        str[0] = '\0';
    }}
void MyString::print(){
    cout<<str<<endl;
}

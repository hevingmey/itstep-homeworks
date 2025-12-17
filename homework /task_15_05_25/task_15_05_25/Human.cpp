//
//  Human.cpp
//  task_15_05_25
//
//  Created by hevingmay on 02/11/2025.
//
#include "Human.h"
#include <iostream>
using namespace std;
Human::Human( char* n,unsigned short a,unsigned int inn ):INN{inn}
{
    ++counter;
    setName(n);
    setAge(a);
}

Human::Human():Human::Human(nullptr,0,0)
{
    
}



char*Human::getName()
{
    return name;
}
unsigned short Human::getAge()
{
    return age;
}
unsigned int Human ::getINN()
{
    return INN;
}
void Human::setName(char* n)
{
    if (n!=nullptr && strlen(n)>0)
    {
       if ( name!=nullptr)
       {
           delete[ ] name;
       }
        size_t size = strlen(n);
        name=new char[size+1];
        strncpy(name,n,size);
        name[size]='\0';
    }
}
void Human::setAge(unsigned short a)
{
    age=a;
}
void Human::print(){
    cout<<"Human: \n";
    cout<<getName()<<endl;
    cout<<getAge()<<endl;
    cout<<getINN()<<endl;
    cout<<"=================\n\n";
}
int Human::getCounter(){
    
    return counter;
}

int Human::counter=0;

Human::~Human( )
{
    if (name!=nullptr)
        delete[ ] name;}

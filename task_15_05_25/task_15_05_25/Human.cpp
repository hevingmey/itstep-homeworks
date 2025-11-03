//
//  Human.cpp
//  task_15_05_25
//
//  Created by hevingmay on 02/11/2025.
//
#include "Human.h"
#include <iostream>

Human::Human( char* n,unsigned short a,unsigned int inn ):INN{inn}
{
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
Human::~Human( )
{
    if (name!=nullptr)
        delete[ ] name;}

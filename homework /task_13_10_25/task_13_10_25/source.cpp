#include "Student.h"
#include <iostream>
using namespace std;
Student::Student( )
{
    name=new char [strlen("NoName")+1];
    strcpy(name,"noName");
    age=0;
    grades[0]=0;
    grades[1]=0;
    grades[2]=0;
    grades[3]=0;
    grades[4]=0;
    //або : for (int i=0;i<5;i++) grades[i]=0;
}
Student::Student(const char* n , int a,int g[ ])
{
    name=new char [strlen(n)+1];
    strcpy(name,n);
    age=a;
    for (int i=0;i<5;i++) grades[i]=g[i];
}

void Student::setName(char* newName)
{
    name = new char[strlen(newName) + 1];
        strcpy(name, newName);
}

void Student::getName(char* outName)
{
    strcpy(outName, name);
}

void Student::setAge(int newAge)
{
    if (newAge>0)
        age=newAge;
}
int Student::getAge()
{
    return age;
}

void Student::setGrade(int index, int value)
{
    if ( index>=0 && index<5)
        grades[index]=value;
}

int Student::getGrade(int index){
    if (index>=0 && index<5)
        return grades[index];
    cout<<"error";
    return -1;
}
double Student::getAverage()
{
    double sum=0;
    for (int i=0;i<5;i++) sum+=grades[i];
    return sum/5.0;
}
bool Student::isExcellent()
{
    for (int i=0;i<5;i++)
        if (grades[i]<90) return false;
    return true;
}

    void Student::print()
    {
        cout<<"name: "<<name<<endl;
        cout<<"age : "<<age<<endl;
        for (int i=0;i<5;i++)
        {
            cout<<"grades: "<<grades[i]<<" "<<endl;
        }
        cout<<"Average: "<<getAverage()<<endl;
        cout<<"Excelent: "<<isExcellent()<<endl;
        cout<<endl;
    }



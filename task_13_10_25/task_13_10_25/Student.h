#pragma once
class Student
{
private:
    char* name;
    int age;
    int grades[5];

public:
    Student ( );
        
    Student( const char* n,int a,int g[ ]);
    void setName(char* newName);
    void getName( char* outName);
    void setAge(int newAge);
    int getAge();
    void setGrade(int index ,int value);
    int getGrade(int index);
    double getAverage();
    bool isExcellent();
    void print();
    

};

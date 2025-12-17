#include <iostream>
#include <string>
using namespace std;

class Student
{
protected:
    string name;
    int age;

public:
    Student(string name, int age)
        : name{name}, age{age} {}
};

class Aspirant : public Student
{
private:
    string res;

public:
    Aspirant(string name, int age, string topic)
        : Student(name, age), res{topic} {}
};

int main()
{
    Student st("Ivan", 20);
    Aspirant asp("Petro", 25, "Art");

    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Employee {
public:
    string name;
    unsigned short age;
    double salary;

    Employee(string n, unsigned short a, double s) {
        name = n;
        age = a;
        salary = s;
    }
};

int main() {
    vector<Employee> employees = {
        Employee("Ivan", 25, 9000),
        Employee("Oleg", 30, 12000),
        Employee("Anna", 28, 15000),
        Employee("Maria", 22, 8000),
     
    };

    int count = 0;
    for (auto& e : employees) {
        if (e.salary > 10000)
            count++;
    }
    cout << "salary > 10000: " << count << endl;

    sort(employees.begin(), employees.end(), [](Employee a, Employee b) {
        return a.salary < b.salary;
    });

    cout << "\nsorted by salary:\n";
    for (auto& e : employees) {
        cout << e.name << " - " << e.salary << endl;
    }

    Employee maxSalary = employees[0];
    for (auto& e : employees) {
        if (e.salary > maxSalary.salary)
            maxSalary = e;
    }

    cout << "\nmax salary: " << maxSalary.name
         << " - " << maxSalary.salary << endl;

    return 0;
}

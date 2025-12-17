#include <iostream>
using namespace std;

class Employer {
public:
    virtual void Print() const = 0;

    virtual ~Employer() {}
};


class President : public Employer {
public:
    void Print() const override {
        cout << "I am a president\n";
    }
};


class Manager : public Employer {
public:
    void Print() const override {
        cout << "I am a manager\n";
    }
};


class Worker : public Employer {
public:
    void Print() const override {
        cout << "i am a worker\n";
    }
};

int main() {
    Employer* arr[3];
    arr[0] = new President();
    arr[1] = new Manager();
    arr[2] = new Worker();

    for (int i = 0; i < 3; i++) {
        arr[i]->Print();
        delete arr[i];
    }

    return 0;
}

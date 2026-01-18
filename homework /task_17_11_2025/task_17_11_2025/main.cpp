#include <iostream>
#include <exception>
#include <string>

using namespace std;

class NegativeAmountException : public exception {
    string message;
public:
    NegativeAmountException(string msg) : message(msg) {}

    const char* what() const noexcept override {
        return message.c_str();
    }
};

class NotEnoughFundsException : public exception {
    string message;
public:
    NotEnoughFundsException(string msg) : message(msg) {}

    const char* what() const noexcept override {
        return message.c_str();
    }
};

class BankAccount {
    string owner;
    double balance;

public:
    BankAccount(string owner, double balance) {
        this->owner = owner;
        this->balance = balance;
    }

    void deposit(double amount) {
        if (amount <= 0)
            throw NegativeAmountException("amount must be greater than 0");

        balance += amount;
        cout << "deposit . balance: " << balance << endl;
    }

    void withdraw(double amount) {
        if (amount <= 0)
            throw NegativeAmountException("amount must be greate than 0 ");

        if (amount > balance)
            throw NotEnoughFundsException("not enough funds");

        balance -= amount;
        cout << "withdraw . Balance: " << balance << endl;
    }
};

int main() {
    BankAccount acc("Ivan", 500);

    try {
        acc.deposit(200);
        acc.withdraw(100);
        acc.withdraw(1000);
        acc.deposit(-50);
    }
    catch (const exception& e) {
        cout << "error: " << e.what() << endl;
    }

    return 0;
}

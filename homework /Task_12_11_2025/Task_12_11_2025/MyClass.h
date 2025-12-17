#include <iostream>
#include <string>
using namespace std;

class IPayment {
public:
    virtual void pay(double sum) = 0;
    virtual ~IPayment() = default;
};

class CashPayment : public IPayment {
public:
    void pay(double sum) override {
        cout << "Cash: " << sum << endl;
    }
};

class CardPayment : public IPayment {
public:
    void pay(double sum) override {
        cout << "Card: " << sum << endl;
    }
};

class ProductBase {
protected:
    string title;
    double price;

public:
    ProductBase(string t = "", double p = 0) : title(t), price(p) {}

    virtual void showInfo() {
        cout << title << " " << price << endl;
    }

    void pay(IPayment* p, double sum) {
        p->pay(sum);
    }
};

class OnlineStore : public virtual ProductBase {
public:
    OnlineStore() = default;

    void orderOnline() {
        cout << "Online order" << endl;
    }

    void showInfo() override {
        ProductBase::showInfo();
    }
};

class LocalStore : public virtual ProductBase {
public:
    LocalStore() = default;

    void sellOffline() {
        cout << "Offline sell" << endl;
    }

    void showInfo() override {
        ProductBase::showInfo();
    }
};

class HybridStore : public OnlineStore, public LocalStore {
public:
    HybridStore(string t, double p) : ProductBase(t, p) {}

    void showInfo() override {
        ProductBase::showInfo();
    }
};


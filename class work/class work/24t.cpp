#include <iostream>
using namespace std;

class Fraction {
private:
    int numerator;
    int denominator;

public:
    Fraction(int numerator = 0, int denominator = 1) {
        this->numerator = numerator;
        
        this->denominator = denominator == 0 ? 1 : denominator;
    }

    Fraction(const Fraction& obj) {
        this->numerator = obj.numerator;
        this->denominator = obj.denominator;
    }

    void print() const {
        cout << numerator << "/" << denominator;
    }


    Fraction operator+(const Fraction& obj)
    const {
        return Fraction(numerator * obj.denominator + obj.numerator * denominator,
                        
                        denominator * obj.denominator);
    }

    Fraction operator-(const Fraction& obj)
    const {
        return Fraction(numerator * obj.denominator - obj.numerator * denominator,
                        denominator * obj.denominator);
    }

    Fraction operator*(const Fraction& obj) const {
        return Fraction(numerator * obj.numerator,
                        
                        denominator * obj.denominator);
    }

    Fraction operator/(const Fraction& obj) const {
        
        return Fraction(numerator * obj.denominator,
                        denominator * obj.numerator);
    }
};

int main() {
    Fraction a(2, 5);
    Fraction b(6, 7);  

    Fraction sum = a + b;
    Fraction diff = a - b;
    Fraction prod = a * b;
    Fraction div = a / b;

    cout << "a = "; a.print(); cout << endl;
    cout << "b = "; b.print(); cout << endl;

    cout << "a + b = "; sum.print(); cout << endl;
    cout << "a - b = "; diff.print(); cout << endl;
    cout << "a * b = "; prod.print(); cout << endl;
    cout << "a / b = "; div.print(); cout << endl;

    return 0;
}

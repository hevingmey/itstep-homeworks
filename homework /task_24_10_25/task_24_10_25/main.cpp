#include <iostream>
using namespace std;

class Fraction {
private:
    int numerator;
    int denominator;

public:
    Fraction(int num = 0, int den = 1) {
        if (den == 0) den = 1;

        numerator = num;
        denominator = den;

        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
    }

    Fraction(const Fraction& obj) {
        numerator = obj.numerator;
        denominator = obj.denominator;
    }

    void print() const {
        cout << numerator << "/" << denominator;
    }

    friend ostream& operator<<(ostream& os, const Fraction& f) {
        os << f.numerator << "/" << f.denominator;
        return os;
    }

    Fraction operator+(const Fraction& obj) const {
        return Fraction(numerator * obj.denominator + obj.numerator * denominator,
                        denominator * obj.denominator);
    }

    Fraction operator-(const Fraction& obj) const {
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

    Fraction sum  = a + b;
    Fraction diff = a - b;
    Fraction prod = a * b;
    Fraction div  = a / b;

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    cout << "a + b = " << sum  << endl;
    cout << "a - b = " << diff << endl;
    cout << "a * b = " << prod << endl;
    cout << "a / b = " << div  << endl;

    return 0;
}

#include <iostream>
using namespace std;

template<typename T>
class MyArray {
private:
    unsigned int size;
    T* arr;
public:
    MyArray(unsigned int size) : size(size) {
        
        arr = new T[size];
    }

    ~MyArray() {
        delete[] arr;
    }

    unsigned int getSize() const {
        return size;
    }

    T& operator[](unsigned int index) {
        return arr[index];
    }

    const T& operator[](unsigned int index) const {
        return arr[index];
    }

    void print() const {
        for (unsigned int i = 0; i < size; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void valueUp(int n) {
        for (unsigned int i = 0; i < size; ++i) {
            arr[i] = arr[i] + n;
        }
    }

    T sum() const {
        if (size == 0) return T();
        T s = arr[0];
        for (unsigned int i = 1; i < size; ++i) {
            s = s + arr[i];
        }
        return s;
    }
};

class Point {
private:
    int x;
    int y;
public:
    Point(int x = 0, int y = 0) : x(x), y(y) {}

    Point operator+(int n) const {
        return Point(x + n, y + n);
    }

    Point operator+(const Point& other) const {
        return Point(x + other.x, y + other.y);
    }

    friend ostream& operator<<(ostream& os, const Point& p) {
        os << "(" << p.x << ", " << p.y << ")";
        return os;
    }
};

int main() {
    cout << " MyArray int  " << endl;
    MyArray<int> arrInt(5);

    for (unsigned int i = 0; i < arrInt.getSize(); ++i) {
        arrInt[i] = i + 1;
    }

    cout << "Початковий масив: ";
    arrInt.print();

    arrInt.valueUp(10);
    cout << "Після valueUp(10): ";
    arrInt.print();

    cout << "Сума елементів: " << arrInt.sum() << endl;


    cout << "\n MyArray Point " << endl;
    MyArray<Point> myarr(3);

    myarr[0] = Point(1, 2);
    myarr[1] = Point(3, 4);
    myarr[2] = Point(-1, 0);

    cout << "Початкові точки: ";
    myarr.print();

    myarr.valueUp(5);
    cout << "Після valueUp(5): ";
    myarr.print();

    Point s = myarr.sum();
    cout << "Сума точок: " << s << endl;

    return 0;
}

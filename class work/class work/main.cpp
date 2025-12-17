// Перевантаження операторів
#include <iostream>
using namespace std;

class MyArray
{
private:
    int* arr;
    size_t size;

public:
    MyArray(int* arr, size_t size) : arr{nullptr}, size{0}
    {
        if (size > 0 && arr != nullptr)
        {
            this->size = size;
            this->arr = new int[size];
            for (size_t i = 0; i < size; ++i)
            {
                this->arr[i] = arr[i];
            }
        }
    }

    MyArray(const MyArray& obj) = delete;

    ~MyArray()
    {
        delete[] arr; // delete[] від nullptr — безпечно
    }

    int operator[](int index) const
    {
        if (index >= 0 && index < static_cast<int>(size))
        {
            return arr[index];
        }

        // мінімальна обробка помилки
        cout << "Index out of range\n";
        return 0;
    }
};

class Point
{
private:
    int x;
    int y;

public:
    Point() : x{0}, y{0} {}

    explicit Point(int x) : x{x}, y{0} {}

    Point(int x, int y) : x{ x }, y{ y } {}

    int getX() const { return x; }
    int getY() const { return y; }

    void setY(int y) { this->y = y; }
    void setX(int x) { this->x = x; }

    void showPoint() const
    {
        cout << x << endl << y << endl;
    }

    bool operator>(const Point& obj) const
    {
        return x > obj.x && y > obj.y;
    }

    bool operator!=(const Point& obj) const
    {
        return x != obj.x || y != obj.y;
    }

    // Point + Point
    Point operator+(const Point& obj) const
    {
        return Point{ x + obj.x, y + obj.y };
    }

    // Point + int
    Point operator+(int n) const
    {
        return Point{ x + n, y + n };
    }
};

// int + Point
Point operator+(int n, const Point& p)
{
    return Point{ p.getX() + n, p.getY() + n };
}

// int - Point
Point operator-(int n, const Point& p)
{
    return Point{ n - p.getX(), n - p.getY() };
}

ostream& operator<<( ostream& out, const Point& obj)
{
    cout<<"X: "<<obj.getX()<<"y: "<<obj.getY();
    return out;
}

int main()
{
    Point p{3,4};
    cout<<p;
    
    int arr[] = {4, 5, 6, 7};
    size_t size = sizeof(arr) / sizeof(arr[0]);

    MyArray marr1{arr, size};
    cout << marr1[0] << endl;   // 4

    Point p1{12, 15};
    Point p2{7, 8};

    Point p4 = p1 + 10;   // Point + int
    Point p5 = 10 + p1;   // int + Point
    Point p6 = 30 - p1;   // int - Point

    p4.showPoint();
    p6.showPoint();

    if (p1 > p2)
        cout << "p1 > p2\n";

    if (p1 != p2)
        cout << "p1 != p2\n";

    Point p3 = p1 + p2;   // Point + Point
    p3.showPoint();

    return 0;
}

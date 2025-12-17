#include <iostream>
#include <vector>
using namespace std;

/*
C-Style    (int)8.9  - int(8.9)
static_cast<type> - на етапі компіляції програми
dynamic_cast<type> - для поліморфних типів(virtual),
на етапі виконання програми
reinterpret_cast<type>
const_cast<type> - надавати/знімати константність
*/
class IShape
{
public:
  virtual ~IShape() = default;
  virtual void draw() const = 0;
};

class IPerimeter
{
public:
  virtual ~IPerimeter() = default;
  virtual double perimeter() const = 0;
};

class Rectangle : public IShape, public IPerimeter
{
private:
  double w;
  double h;
public:
  Rectangle(double w, double h) :w{ w }, h{ h } {}
  void draw() const override
  {
    cout << "I am Rectangle\n";
  }
  double perimeter() const override
  {
    return 2 * (w + h);
  }
};
class Circle : public IShape, public IPerimeter
{
private:
  double r;
public:
  Circle(double r) :r{ r } {}
  void draw() const override
  {
    cout << "I am Circle\n";
  }
  double perimeter() const override
  {
    return 2 * 3.14*r;
  }
};
class Point :public IShape
{
private:
  double x;
  double y;
public:
  Point(double x, double y) :x{ x }, y{ y } {}
  void draw() const override
  {
    cout << "I am Point\n";
  }
};


void calc(vector<IShape*> shapes)
{
  for (auto el : shapes)
  {
    el->draw();
    if (IPerimeter* obj = dynamic_cast<IPerimeter*>(el))
    {
      cout << obj->perimeter() << endl;
    }
    else
    {
      cout << "Perimeter not available\n";
    }
  }
}

int main()
{
  vector<IShape*> shapes;
  shapes.push_back(new Circle(2.5));
  shapes.push_back(new Rectangle(3.4, 7.6));
  shapes.push_back(new Point(4.0, 8.0));
  calc(shapes);}

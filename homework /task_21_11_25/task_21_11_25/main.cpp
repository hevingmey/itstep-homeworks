#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

class Shape {
public:
    virtual void show() = 0;
    virtual void save(ofstream& f) = 0;
    virtual ~Shape() = default;
};

class Circle : public Shape {
    double r;
public:
    Circle(double r) : r(r) {}
    void show() override {
        cout << "Circle r=" << r << endl;
    }
    void save(ofstream& f) override {
        f << "C " << r << endl;
    }
};

class Rectangle : public Shape {
    double w, h;
public:
    Rectangle(double w, double h) : w(w), h(h) {}
    void show() override {
        cout << "Rectangle w=" << w << " h=" << h << endl;
    }
    void save(ofstream& f) override {
        f << "R " << w << " " << h << endl;
    }
};

class Triangle : public Shape {
    double a,b,c;
public:
    Triangle(double a,double b,double c) : a(a),b(b),c(c) {}
    void show() override {
        cout << "Triangle a=" << a << " b=" << b << " c=" << c << endl;
    }
    void save(ofstream& f) override {
        f << "T " << a << " " << b << " " << c << endl;
    }
};

int main() {
    vector<Shape*> v;

    v.push_back(new Circle(5));
    v.push_back(new Rectangle(3,4));
    v.push_back(new Triangle(2,3,4));

    ofstream out("shapes.txt");
    for(auto s : v) s->save(out);
    out.close();

    for(auto s : v) delete s;
    v.clear();

    ifstream in("shapes.txt");
    char t;

    while(in >> t) {
        if(t=='C'){
            double r; in >> r;
            v.push_back(new Circle(r));
        }
        else if(t=='R'){
            double w,h; in >> w >> h;
            v.push_back(new Rectangle(w,h));
        }
        else if(t=='T'){
            double a,b,c; in >> a >> b >> c;
            v.push_back(new Triangle(a,b,c));
        }
    }

    for(auto s : v) s->show();
    for(auto s : v) delete s;

    return 0;
}

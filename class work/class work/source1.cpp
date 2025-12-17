#include <iostream>
using namespace std;
#include <cstring>

class Book{
    
private:
    char* title;
    int year;
    double price;
public:
    Book(const char* t, int y, double p) {
        title = new char[strlen(t) + 1]; 
        strcpy(title, t);
        year = y;
        price = p;
    }


    Book(const Book& obj){
        title= new char[strlen (obj.title)+1];
        strcpy(title, obj.title);
        year=obj.year;
        price=obj.price;}
    
    ~Book( ){
        delete[] title;
    }

    void print() const {
        cout<<"name: "<<title;
        cout<<"year: "<<year;
        cout<<"price: "<<price;
        
    }
    char* getTitle( )const{
        return title;
    }
    void setPrice(double newPrice){
        price=newPrice;
    }
};

int main( ){
    Book b1("The witcher",1993,350.4);
    b1.print();
    Book b2=b1;
    b2.setPrice(370.8);
    b2.print();
    
    return 0;
}

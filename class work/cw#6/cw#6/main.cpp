#include <iostream>
#include <string>

using namespace std;


class Furniture
{
    string desk;
    string chair;
    string pictures;
public:
    Furniture( )=default;
    Furniture(string d,string c,string p):desk{d},pictures{p}, chair{ c}{ }
    
    string getDesk( )const{
        return desk;}
    string getChair( )const{
        return chair;
    }
    string getPictures( )const
    {
        return pictures;
    }
};
class Wall
{
    
};
class Room
{
private:
    string name;
    Wall wall;
    Furniture* furniture ;
public:
    Room( ): name{"noName"},
    furniture{nullptr}{ }
    Room(string n, Furniture* f):
    name{n},furniture{f}{ }
    void show ( )const
    {
        cout<<"name- "<<name <<endl;
        if (furniture)
        {
            cout<<"has a furniture"<<furniture->getDesk()<<endl;
            cout<<"has a furniture"<<furniture->getPictures()<<endl;
            cout<<"has a furniture"<<furniture->getChair()<<endl;
            
        }
        else
            cout << "no furniture"<<endl;
    }
};

int main (){
    
    Furniture fur1("red","gren","black");
    Room* room1=new Room("kitchen", &fur1);
    room1->show();
    delete room1;
    Room* room2=new Room("bedroom",&fur1);
    room2->show( );
    delete room2;
    
    return 0;
    
}

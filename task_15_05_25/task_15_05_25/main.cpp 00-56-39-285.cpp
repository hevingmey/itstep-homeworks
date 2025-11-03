//
//  main.cpp
//  task_15_05_25
//
//  Created by hevingmay on 02/11/2025.
//



//class Bar
//{
//private:
//  int count;
//  int price;
//  int age;
//  int weight;
//    const int R;
//public:
//    Bar(int c, int p, int a, int w,int r):R{r}
//  {
//    count = c > 0 ? c : 0;
//    price = p > 100 ? p : 100;
//    age = age > 18 ? age : 18;
//    weight = w;
//  }
//  Bar() :Bar(0, 0, 0, 0,0) {};
//  Bar(int c) :Bar(c, 0, 0,0, 0) {};
//  Bar(int c, int p) :Bar(c, p,0, 0, 0) {};
//  Bar(int c, int p, int a) :Bar(c, p, a,0, 0) {};
//    };
//
//class Letter
//    {
//    private:
//        const char sh;
//        unsigned int code10;
//        unsigned int code16;
//    public:
//        
//        Letter(char s, unsigned int c10, unsigned int c16)
//               : sh{s}, code10{c10}, code16{c16} { }
//        Letter() : Letter('?', 0, 0) { }
//
//            Letter(char s)
//                : Letter(s, static_cast<unsigned int>(s), static_cast<unsigned int>(s)) { }
//
//            Letter(char s, unsigned int c10)
//                : Letter(s, c10, c10) { }
//        
//      
            
    //};

#include <iostream>
#include "Human.h"
using namespace std;


int main( ){
    
    char name[30];
    cout<<"enter name: ";
    cin>>name;
    unsigned short age;
    cout<<"enter age: ";
    cin>>age;
    cout<<"enter INN: ";
    unsigned int inn;
    cin>>inn;
    Human h1(name, age, inn);
    cout<<h1.getName()<<endl;
    cout<<h1.getAge()<<endl;
    cout<<h1.getINN()<<endl;
    
    Human* h2=new Human(name,age,inn);
    delete h2;
    
    return 0;
}

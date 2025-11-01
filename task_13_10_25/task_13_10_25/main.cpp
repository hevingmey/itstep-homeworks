#include <iostream>
using namespace std;
#include "Student.h"
 
int main( ){
    
    int grades1[5]={90,91,93,90,92};
    Student vlad("vlad",21,grades1);
    vlad.print();
    int grades2[5]{88,97,75,100,87};
    Student alex("alex",22,grades2);
    
    alex.print();
    
    
    
                      
    return 0;
    
}

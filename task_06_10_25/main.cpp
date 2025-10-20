#include <iostream>
#include <string>
using namespace std;
 
class Student {
private:
    string name;
    string was_born;
    string telf;
    string city;
    string country;
    string nameUN;
    string cityUN;
    string numClasss;
    string countryUN;
    
public:
    void input(  ){
        cout<<"ПІБ: ";
        getline(cin,name);
        cout<<"дату народження: ";
        getline(cin,was_born);
        cout<<"телефон: ";
        getline(cin,telf);
        cout<<"місто: ";
        getline(cin,city);
        cout<<"країну: ";
        getline(cin,country);
        cout<<"назву навчального закладу: ";
        getline(cin,nameUN);
        cout<<"місто Унів.: ";
        getline(cin,cityUN);
        cout<<"країну Унів. : ";
        getline(cin,numClasss);
        cout<<"номер групи: ";
        getline(cin,countryUN);
    }
    
    void show() const{
        cout<<"+++інформація про студента+++"<<endl;
        cout<<"ПІБ: "<<name<<endl;
        cout<<"дату народження: "<<was_born<<endl;
        cout<<"телефон: "<<telf<<endl;
        cout<<"місто: "<<city<<endl;
        cout<<"країну: "<<country<<endl;
        cout<<"назву навчального закладу: "<<nameUN<<endl;
        cout<<"місто Унів.: "<<cityUN<<endl;
        cout<<"країну Унів. : "<<countryUN<<endl;
        cout<<"номер групи: "<<numClasss<<endl;}
          
};
int main( ){
    Student Vlad;
    Vlad.input();
    Vlad.show();
    
    
    
    return 0;
}

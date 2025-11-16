#include <iostream>
#include <string>
using namespace std;

class Laptop{
private:
    string name;
    float diag;
    string proces;
    int massa;
public:
    Laptop( )=default;
    Laptop (string name,float diag,string proces, int massa): name{name},diag{diag},proces{proces},massa{massa}
    {
        
    }
    int getMassa()const{
        return massa;
    }
    void setMassa(int massa1){
        massa=massa1;
    }
    
    int getDiag()const{
        return diag;
    }
    void setDiag(float diag1){
        diag=diag1;
    }
   const string& getName()const {
        return name;
    }
    void setName(string& name1){
        name=name1;
        
    }
    const string& getProces()const {
        return proces;
    }
    void setProces(string& proces1){
        proces=proces1;
        
    }
    
};
ostream& operator<<(ostream& os,const Laptop& p)
{
    os<<"name: "<<p.getName()<<endl;
    os<<"diag: "<<p.getDiag()<<endl;
    os<<"proces: "<<p.getProces()<<endl;
    os<<"massa: "<<p.getMassa()<<" kg"<<endl;
    return os;
}






int main(){
    
    Laptop n("macBook",15.3,"intel i7",2);
    cout<<n<<endl;
    string str1 ={ "hello"};
    cout<<str1.capacity()<<endl;
    str1.shrink_to_fit();
    cout<<str1.capacity()<<endl;
    return 0;
    
}

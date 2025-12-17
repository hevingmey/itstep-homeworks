//#include <iostream>
//using namespace std;
//class Number
//{
//private:
//    int num;
//public:
//    Number (int n=0):num(n){ }
//    int getN()const {return num;}
//    Number& operator++(){
//        ++num;
//        return *this;
//    }
//    Number operator++(int){
//        Number temp =*this;
//        ++num;
//        return temp;
//        
//    }
//    Number& operator--(){
//        --num;
//        return *this;
//    }
//    Number operator--(int){
//        Number temp=*this;
//        --num;
//        return temp;
//    }
//    Number operator+(int t )const{
//        return Number(num+t);
//    }
//    
//    
//};
//Number operator-(int n,const Number& num ){
//    return Number(n-num.getN());
//}
//
//istream& operator>>(istream& in ,Number& num){
//    int temp;
//    in>>temp;
//    num = Number(temp);
//    return in;
//}
//ostream& operator<<(ostream& on, Number& num){
//    on<<num.getN();
//    return on;
//    
//}

#include <iostream>
#include <fstream>
using namespace std;

int main(){
    
    
    ifstream fin("task_file.txt");
    if (!fin){
        cout<<"не можу відкрити файл ";
        return 1;
        
    }
    
    char c;
    int chars=0;
    int lines=0;
    int digits=0;
    
    while(fin.get(c)){
        chars++;
        
        if (c=='\n')
            lines++;
        if (c>='0'&& c<='9')
            digits++;
        
    }
    
    if (chars >0 && c!='\n')
        lines++;
    ofstream fout("exitf.txt");
    fout<<"кількість символів: "<<chars<<"\n";
    fout<<"кількість рядків: "<<lines<<"\n";
    fout<<"кількість цифр: "<<digits<<"\n";
    
    return 0;}

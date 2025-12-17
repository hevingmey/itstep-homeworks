#include <iostream>
#include <fstream>
using namespace std;

int main(){
    
    
    ifstream fin("task_file.txt");
    if (!fin){
        cout<<"не можу відкрити файл ";
        return 1;
        
    }
    int vowels=0;
    int consonants=0;
    char c;
    int chars=0;
    int lines=0;
    int digits=0;
    
    while(fin.get(c)){
        chars++;
        if (c=='a'||c=='e'||c=='y'||c=='u'||c=='i'||c=='o'||c=='A'||c=='E'||c=='Y'||c=='U'||c=='I'||c=='O')
            vowels++;
        if(c=='q'||c=='w'||c=='r'||c=='t'||c=='p'||c=='s'||c=='d'||c=='f'||c=='g'||c=='h'||c=='j'||c=='k'||c=='l'||c=='z'||c=='x'||c=='c'||c=='v'||c=='b'||c=='n'||c=='m'||c=='Q'||c=='W'||c=='R'||c=='T'||c=='P'||c=='S'||c=='D'||c=='F'||c=='G'||c=='H'||c=='J'||c=='K'||c=='L'||c=='Z'||c=='X'||c=='C'||c=='V'||c=='B'||c=='N'||c=='M')
            consonants++;
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
    fout<<"кількість голосних: "<<vowels<<"\n";
    fout<<"кількість приголосних: "<<consonants<<"\n";
    
    return 0;}

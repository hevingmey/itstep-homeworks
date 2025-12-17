
class MyString
{
private:
    size_t size;
    char* str;
    static int counter;
public:
    MyString();
    
    MyString(char* s);
    
    MyString(size_t s);
    
    ~MyString();
    
    
    size_t getSize();
    char* getStr( );
    static int getCounter( );
    
    void setStr(char* s);
    
    void print();
};


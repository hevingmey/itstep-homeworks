

class MyArray{
  
private:
    int*array;
    int size;
    
public:
    MyArray( );
    MyArray(int* ar,int si );
    ~MyArray( );
    
    int* getArray( );
    int getSize( );
    
    void setArray(int* ar,int si);
    
    int sum( );
    void print();
    
    
};

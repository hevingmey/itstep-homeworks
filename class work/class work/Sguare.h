//
//class Sguare{
//private:
//    int x;
//    int y;
//    int size;
//public:
//    Sguare( int x1,int y1,int size1)
//    {
//       this-> x=x1;
//        this->y=y1;
//        this->size=size1;
//    }
//    void showSguare( )
//    {
//        cout<<this->x<<" "<<this->y<<endl;
//    }
//};
class Rectangle{
private:
    int x;
    int y;
    int height;
    int width;
public:
    Rectangle ();
    Rectangle(int x1,int y1,int h,int w);
    
        
    
    int getX( );
    int getY( );
    int getWidth( );
    int getHeight( );
    
    void setX(int x );
    void setY(int y );
    void setWidth(int w );
    void setHeight(int h );
    
    
    
    int getplo( );
    int getper();
};

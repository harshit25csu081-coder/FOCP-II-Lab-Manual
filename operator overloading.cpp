operator overloading
#include <iostream>

class Rectangle {
private:
    int width, length;
public:
    Rectangle(int w = 0, int l = 0) {width=w;length=l;}
        void display() {
        std::cout << "Width: " << width << ", Length: " << length << std::endl;    }
Rectangle operator-(Rectangle obj2) 
{    Rectangle temp;
    temp.width=width-obj2.width;
    temp.length=length-obj2.length;
    return temp;}
    //operator overloading member method
Rectangle operator+(int val) 
{    Rectangle temp;
    temp.width=width+val;
    temp.length=length+val;
    return temp;}
friend Rectangle operator+(int val,Rectangle obj) ;
};
 //operator overloading normal method
Rectangle operator+(int val,Rectangle obj) 
{
    Rectangle temp;
    temp.width=obj.width+val;
    temp.length=obj.length+val;
    return temp;
}
int main() {

    Rectangle r1(5, 10),r2(67,90);
    Rectangle r3=r1-r2;//r1.operator-(r2);
    r1.display();
    r2.display();
    r3.display();
    r3=9+r1;
    r3.display();
    return 0;
}
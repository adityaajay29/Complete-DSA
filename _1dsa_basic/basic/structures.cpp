#include <iostream>
using namespace std;
// std is used to aviod using std::

//in structure,things are public by default, but in class, things are private by default

struct point //creating a data type of name point
{
    int x;
    int y;
};

void fun1(point *p) //for pointer,we use ->
{
    p->x=12;
    p->y=13;
}

void fun2(point &p) //for &,same style
{
    p.x=12;
    p.y=13;
}
int main()
{   
    point p;
    p.x=10,p.y=20;
    cout<<p.x<<" "<<p.y<<endl;
    fun1(&p);
    cout<<p.x<<" "<<p.y<<endl;
    fun2(p);
    cout<<p.x<<" "<<p.y<<endl;
}

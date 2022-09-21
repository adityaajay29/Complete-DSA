#include <iostream>
using namespace std;

class Base
{
    public : 
    virtual void func()
    {
        cout<<"this is base class"<<endl;
    }
    void fun2()
    {
        cout<<"this is 1"<<endl;
    }
};

class Derived : public Base
{
    public : 
    void func()
    {
        cout<<"this is derived class"<<endl;
    }
    void fun2()
    {
        cout<<"this is 2"<<endl;
    }
};

int main()
{
    Base *b;
    Derived d;
    b = &d;
    b->func();
    b->fun2();
    return 0;
}
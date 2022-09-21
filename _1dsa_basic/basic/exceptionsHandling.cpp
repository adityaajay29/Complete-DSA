#include <iostream>
using namespace std;

// this is an example of stack unwinding

void fun1()
{
    cout<<"fun1 begins"<<endl;
    throw 10;
    cout<<"fun1 ends"<<endl;
}

void fun2()
{
    cout<<"fun2 begins"<<endl;
    fun1();
    cout<<"fun2 ends"<<endl;
}

void fun3()
{
    cout<<"fun3 begins"<<endl;
    try
    {
        fun2();
    }
    catch(int x)
    {
        cout<<"caugtht exception in fun3"<<endl;
    }
    cout<<"fun3 ends"<<endl;
}

int main()
{
    fun3();
    cout<<"program ends here"<<endl;
    return 0;
}
#include <iostream>
using namespace std;

class Function
{
    public:
    void fun(int a, int b)
    {
        cout<<"the value of a and b are "<<a<<" "<<b<<endl;
    }
    void fun(double a, double b)
    {
        cout<<"the value of a and b are "<<a<<" "<<b<<endl;
    }
    void fun(string a, string b)
    {
        cout<<"the value of a and b are "<<a<<" "<<b<<endl;
    }
}; 

int main()
{
    Function *func = new Function();
    func->fun(1, 2);
    func->fun(1.0, 2.0);
    func->fun("one", "two");
    return 0;
}
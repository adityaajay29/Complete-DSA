#include <iostream>
using namespace std;

class Abstraction
{
    int a, b;
    public:
    void set(int x, int y)
    {
        a = x, b = y;
    }
    void print()
    {
        cout<<"value of x is "<<a<<" and x is "<<b<<endl;
    }
};

int main()
{
    Abstraction abstract;
    abstract.set(10, 20);
    abstract.print();
    return 0;
}

#include <iostream>
using namespace std;

class example
{
    public:
    int x=10;
    // private:
    int y=20;
};

int main()
{
    example p;
    cout<<p.x<<" "<<p.y<<endl;
    return 0;
}
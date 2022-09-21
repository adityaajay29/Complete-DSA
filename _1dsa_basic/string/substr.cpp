#include <iostream>
using namespace std;

int main()
{
    string s = "aditya ajay";
    for(int i=0;i<s.size();i++)
    {
        cout<<s.substr(i)<<endl;
    }
    cout<<s.substr(3)<<endl;
    cout<<s.substr(0, 3)<<endl;
    cout<<s.substr(3, 5)<<endl;
    return 0;
}
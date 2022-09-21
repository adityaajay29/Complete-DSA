#include <iostream>
using namespace std;
int sum(int n)
{
    if(n<10) 
    return n;
    else
    return sum(n/10)+n%10; // 293/10 to get 293/10=29 (say), and  293%10 to get remainder 3
}

int main()
{
    int n=1000;
    cout<<sum(n)<<endl;
    return 0;
}
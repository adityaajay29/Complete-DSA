#include <iostream>
using namespace std;

string minNum(int n,int m)
{
    int i=n;
    while(i<(10e6))
    {
        int temp=i;
        int sum=0;
        while(temp!=0)
        {
        sum+=temp%10;
        temp/=10;
        }
        if(i%n==0 && sum==m)
        {
            string s=to_string(i);
            return s;
        }
        else
        i+=n;
    }
    return "-1";
}
int main()
{
    int n=12;
    int m=5;
    cout<<minNum(n,m)<<endl;
    return 0;
}
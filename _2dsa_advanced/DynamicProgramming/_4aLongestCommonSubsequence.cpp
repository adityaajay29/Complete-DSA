#include <iostream>
using namespace std;

int longest(string s1, string s2, int n, int m)
{
    if(n == 0 || m == 0)
    return 0;
    if(s1[n-1] == s2[m-1])
    {
        return 1 + longest(s1, s2, n-1, m-1);
    }
    else 
    {
        return max(longest(s1, s2, n-1, m), longest(s1, s2, n, m-1));
    }
}

int main()
{
    int n,m;
    string s1;
    string s2;
    cin>>s1>>s2;
    n=s1.size();
    m=s2.size();
    cout<<"longest common subsequence is "<<longest(s1, s2, n, m);
    return 0;
}
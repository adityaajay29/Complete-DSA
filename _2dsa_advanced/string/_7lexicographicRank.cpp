#include <iostream>
#include <vector>
using namespace std;

// naive approach
// O(n2) time
// can be optimised by making cummulitive freq table of characters, then finding smaller chars
// then reduce the frequency of the char for which we have found the smaller chars
// O(1) space

int factorial(int n)
{
    if(n<0)
    return -1;
    if(n==0 || n==1)
    return 1;
    return n*factorial(n-1);
}

int lexicographicRank(string s)
{
    int n=s.size();
    int mul=factorial(n);
    int res=0;
    int j;
    for(int i=0;i<n;i++)
    {
        int count=0;
        for(j=i+1;j<n;j++)
        {
            if(s[j]<s[i])
            count++;
        }
        mul/=(n-i);
        res+=count*mul;
    }
    return res+1;
}

int main()
{
    string s="STRING";
    cout<<"the lexicographic rank of "<<s<<" is "<<lexicographicRank(s)<<endl;
    return 0;
}
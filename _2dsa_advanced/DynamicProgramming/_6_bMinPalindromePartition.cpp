#include <iostream>
using namespace std;

int dp[101][101];

bool isPalindrome(string &s, int i, int j)
{
    while(i<=j)
    {
        if(s[i] != s[j])
        return false;
        i++;
        j--;
    }
    return true;
}

int minPart(string &s, int i, int j)
{
    if(i >= j)
    return 0;
    
    if(isPalindrome(s, i, j))
    return 0;
    
    int ans=INT_MAX;

    for(int k=i;k<j;k++)
    {
        int temp = minPart(s, i, k) + minPart(s, k+1, j) + 1;
        ans=min(ans, temp);
    }
    return ans;
}

int main()
{
    int n;
    string s;
    cin>>s;
    n=s.size();
    cout<<"min no of partition to make palindromes are "<<minPart(s, 0, n-1)<<endl;
    return 0;
}
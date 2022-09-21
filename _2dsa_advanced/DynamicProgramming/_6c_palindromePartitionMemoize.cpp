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

    if(dp[i][j] != -1)
    return dp[i][j];

    int ans = INT_MAX;

    for(int k=i;k<j;k++)
    {
        int temp = minPart(s, i, k) + minPart(s, k+1, j) + 1;
        ans = min(ans, temp);

        // OPTIMISATION : 
        // if the left part is already a palindrome, then dont solve for it
        // simply add 1 to the solution for right
        if(isPalindrome(s, i, k))
        {
            ans = min(ans, 1 + minPart(s, k+1, j));
        }
    }
    return dp[i][j] = ans;
}

int main()
{
    string s;
    cin>>s;
    int n=s.size();
    memset(dp, -1, sizeof(dp));
    // ababbbabbababa
    // op - 3
    cout<<"the min no of part to make all parts of s as palindrome is "<<minPart(s, 0, n-1)<<endl;
    return 0;
}
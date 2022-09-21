#include <iostream>
using namespace std;

// leetcode 647

// tc : O(n2), space constant

int palindromeSubstrings(string s)
{
    int n=s.size();
    int l, r;
    int count=0;
    for(int i=0;i<n;i++)
    {
        // for odd palindrome
        l = r = i;
        while(l >= 0 && r < n && s[l] == s[r])
        {
            count++;
            // goto left and right
            l--;
            r++;
        }
        // for even palindrome
        l = i;
        r = i+1;
        while(l >= 0 && r < n && s[l] == s[r])
        {
            count++;
            // goto left and right 
            l--;
            r++;
        }
    }
    return count;
}

int main()
{
    string s;
    cin>>s;
    cout<<"the no of palindrome substrings for "<<s<<" are "<<palindromeSubstrings(s)<<endl;
    return 0;
}
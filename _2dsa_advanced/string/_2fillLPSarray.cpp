#include <iostream>
#include <vector>
using namespace std;

vector<int> fillLPS(string &s)
{
    int n=s.size();
    vector<int>lps(n,0);
    // lps of 0 must be zero
    lps[0]=0;
    // initialise the length of i-1 th lps as 0
    int len=0;
    int i=1;
    // starting from index 1,compare str[i] with s[len]
    while(i<n)
    {
        if(s[i]==s[len])
        {
            // if they are mathing, meaning len of lps increases
            len++;
            lps[i]=len;
            i++;
        }
        else
        // if not matching there are 2 cases
        {
            if(len==0)
            {
                // simply, lps will be 0 as len is 0
                lps[i]=0;
                i++;
            }
            else
            {
                // recursively check for lps of len-1,and assign it to len
                len=lps[len-1];
            }
        }
    }
    return lps;
}

int main()
{
    string s="ABABA";
    vector<int>lps=fillLPS(s);
    cout<<"the lps array for this string is ";
    for(auto x:lps)
    cout<<x<<" ";
    cout<<endl;
    return 0; 
}

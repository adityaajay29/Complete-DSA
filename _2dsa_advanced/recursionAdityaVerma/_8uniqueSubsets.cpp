#include <iostream>
#include <unordered_set>
using namespace std;

// same as printing subsets, powerset, subsequence
// same as printing all combinations of a number, like for 123

void unique(string &s, string temp, unordered_set<string> &set, int i, int n)
{
    if(i == n)
    {
        set.insert(temp);
        return;
    }
    unique(s, temp, set, i+1, n);
    unique(s, temp+s[i], set, i+1, n);
}

int main()
{
    string s;
    cin>>s;
    int n=s.size();
    unordered_set<string> set;
    unique(s, "", set, 0, n);
    for(string s : set)
    cout<<s<<" ";
    return 0;
}
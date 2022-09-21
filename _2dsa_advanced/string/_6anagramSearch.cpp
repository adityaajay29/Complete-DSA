#include <iostream>
#include <vector>
using namespace std;

bool anagram(string text,string patt)
{
    int n=patt.size();
    int m=text.size();
    vector<int>a1(256,0);
    vector<int>a2(256,0);
    for(int i=0;i<n;i++)
    {
        a1[text[i]]++;
        a2[patt[i]]++;
    }
    for(int i=n;i<m;i++)
    {
        if(a1==a2)
        return true;
        else 
        {
            a1[text[i-n]]--;
            a1[text[i]]++;
        }
    }
    return false;
}

int main()
{
    string text="geeksforgeeks";
    string patt="frog";
    cout<<anagram(text,patt)<<endl;
    return 0;
}
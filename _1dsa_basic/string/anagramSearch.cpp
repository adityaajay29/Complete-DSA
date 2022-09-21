#include <iostream>
#include <vector>
using namespace std;

bool arrayMatch(vector<int>&asciiStr,vector<int>&asciiPattern)
{
    // function to check if both the ascii tables have same ascii values and their frequency
    for(int i=0;i<256;i++)
    {
        if(asciiPattern[i]!=asciiStr[i])
        return false;
    }
    return true;
}

bool slideWindow(string &givenStr,string &givenPattern,vector<int>&asciiStr,vector<int>&asciiPattern)
{
    // storing ascii values of pattern and string
    // both having size of pattern
    for(int i=0;i<givenPattern.size();i++)
    {
        asciiStr[givenStr[i]]++;
        asciiPattern[givenPattern[i]]++;
    }

    // for(auto x:asciiStr)
    // cout<<x<<" ";
    // cout<<endl;
    // for(auto x:asciiPattern)
    // cout<<x<<" ";
    // cout<<endl;

    // checking if ascii maches
    for(int i=givenPattern.size();i<givenStr.size();i++)
    {
    if(arrayMatch(asciiStr,asciiPattern))
    return true;
    else
    {asciiStr[givenStr[i]]++;
    asciiStr[givenStr[i-givenPattern.size()]]--;}
    }
    return false;
}

int main()
{
    vector<int>asciiPattern;
    vector<int>asciiStr;
    // initialising all elements as 0;
    for(int i=0;i<256;i++)
    {
        asciiPattern.push_back(0);
        asciiStr.push_back(0);
    }
    string givenStr="dcda";
    string givenPattern="acd";
    cout<<slideWindow(givenStr,givenPattern,asciiStr,asciiPattern)<<endl;;
    return 0;
}
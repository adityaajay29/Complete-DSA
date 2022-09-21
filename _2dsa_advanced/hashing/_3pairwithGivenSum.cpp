#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

bool findPair(vector<int>arr,int sum)
{
    int n=arr.size();
    unordered_set<int>s;
    for(int i=0;i<n;i++)
    {
        if(s.find(sum-arr[i])!=s.end())
        return true;
        else
        s.insert(arr[i]);
    }
    return false;
}

int main()
{
    vector<int>arr{11,5,6};
    int sum=17;
    cout<<findPair(arr,sum)<<endl;
    return 0;
}
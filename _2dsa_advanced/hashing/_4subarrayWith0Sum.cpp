#include <iostream>
#include <vector>
#include <unordered_set>
// #include <unordered_map>
using namespace std;

// we use prefix sum to check if sum is 0
// if the prefix sum is repeating, then there must be 0 sum
// else if 0 is present in prefix sum, then also there is a 0 sum

bool subarrayWith0Sum(vector<int>arr)
{
    int n=arr.size();

    // for(int i=1;i<n;i++)
    // {
    //     arr[i]=arr[i-1]+arr[i];
    // }
    // unordered_map<int,int>mp;
    // for(auto x:arr)
    // mp[x]++;
    // for(auto x:mp)
    // {
    //     if(x.first==0 || x.second==2)
    //     return true;
    // }
    // return false;
    int prefixSum=0;
    unordered_set<int>s;
    for(int i=0;i<n;i++)
    {
        prefixSum+=arr[i];
        if(s.find(prefixSum)!=s.end())
        return true;
        if(prefixSum==0)
        return true;
        // else
        s.insert(prefixSum);
    }
    return false;
}

int main()
{
    vector<int>arr{1,4,13,-3,-19,5};
    cout<<subarrayWith0Sum(arr)<<endl;
}
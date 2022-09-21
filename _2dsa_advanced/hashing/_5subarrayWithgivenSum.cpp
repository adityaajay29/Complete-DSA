#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

bool sumPresent(vector<int>arr,int sum)
{
    int n=arr.size();
    int prefixSum=0;
    unordered_set<int>s;
    for(int i=0;i<n;i++)
    {
        // corner case when sum = one of the prefix sum
        prefixSum+=arr[i];
        if(prefixSum==sum)
        return true;
        if(s.find(prefixSum-sum)!=s.end())
        return true;
        else 
        s.insert(prefixSum);
    }
    return false;
}

int main()
{
    vector<int>arr{5,8,6,13,3,-1};
    cout<<sumPresent(arr,20)<<endl;
    return 0;
}
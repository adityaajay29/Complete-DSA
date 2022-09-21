#include <iostream>
#include <vector>
#include <set>
using namespace std;

// naive app:O(n2), O(n)  space
vector<int>ceilOnLeft(vector<int>arr)
{
    int n=arr.size();
    vector<int>ans(n,-1);
    for(int i=1;i<n;i++)
    {
        int ceil=INT_MAX;
        for(int j=0;j<i;j++)
        {
            if(arr[j]>=arr[i])
            {
                ans[i]=min(ceil,arr[j]);
                ceil=ans[i];
            }
        }
    }
    return ans;
}


// efficient approach using set, to use the lower_bound fun to find ceiling efficiently
// vector<int>ceiling(vector<int>arr)
// {
//     int n=arr.size();
//     set<int>s;
//     vector<int>ans;
//     ans.push_back(-1);
//     s.insert(arr[0]);
//     for(int i=1;i<n;i++)
//     {
//         auto ceil=lower_bound(s.begin(),s.end(),arr[i]);
//         if(s.find)
//     }
// }

int main()
{
    vector<int>arr{2,8,67,34,90,12,9};
    vector<int>ans=ceilOnLeft(arr);
    for(auto x:ans)
    cout<<x<<" ";
    return 0;  
}
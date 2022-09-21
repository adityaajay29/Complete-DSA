#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> distEleInWindow(vector<int>arr,int k)
{
    vector<int>ans;
    int n=arr.size();
    unordered_map<int,int>mp;
    for(int i=0;i<k;i++)
    mp[arr[i]]++;
    ans.push_back(mp.size());
    for(int i=k;i<n;i++)
    {
        mp[arr[i-k]]--;
        // if its frequency becomes 0, then erase it from map
        // as it will affect count of dist ele in another windows
        if(mp[arr[i-k]]==0)
        mp.erase(arr[i-k]);
        // if arr[i] is already present in map, no need to add it to the map
        if(mp.find(arr[i])==mp.end())
        mp[arr[i]]++;
        ans.push_back(mp.size());
    }
    return ans;
}

int main()
{
    vector<int>arr{10,20,10,10,30,40};
    int k=4;
    vector<int>ans=distEleInWindow(arr,k);
    cout<<"the no of distinct elements in all windows of size "<<k<<" is"<<endl;
    for(auto x:ans)
    cout<<x<<" ";
    cout<<endl;
    return 0;
}
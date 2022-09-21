#include <iostream>
#include <vector>
using namespace std;

vector<int> isLeader(vector<int>v,int n)
{
    vector<int>ans;
    int currLeader=v[n-1];
    ans.push_back(v[n-1]);
    for(int i=n-2;i>0;i--)
    {
        if(v[i]>currLeader)
        {
            currLeader=v[i];
            ans.push_back(currLeader);
        }
    }
    int l=0;
    int h=ans.size()-1;
    while(l<h)
    {
        swap(ans[l++],ans[h--]);
    }
    return ans;
}

int main()
{
    vector<int>v{7,14,4,12,6,5,8};
    int n=v.size();
    vector<int>ans=isLeader(v,n);
    for(auto x:ans)
    cout<<x<<" ";
    return 0;
}
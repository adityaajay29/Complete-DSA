#include <iostream>
#include <vector>
using namespace std;

// leader is an element after which there is no element larger or equal than it

vector<int> isLeader(vector<int>v,int n)
{
    if(n==1)
    return v;
    vector<int>ans;
    for(int i=0;i<n;i++)
    {
        bool flag=false;
        for(int j=i+1;j<n;j++)
        {
            if(v[j]>=v[i])
            {
                // set the flag for ith element as true if we find a number larget than it
                flag=true;
                break;
            }
        }
        if(flag==false)
        ans.push_back(v[i]);
    }
    return ans;
}

int main()
{
    vector<int>v{7,14,4,12,6,5,8,8};
    int n=v.size();
    vector<int>ans=isLeader(v,n);
    for(auto x:ans)
    cout<<x<<" ";
    return 0;
}
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int>prevSmallest(vector<int>&arr)
{
    int n=arr.size();
    vector<int>v;
    stack<int>s;
    s.push(0);
    v.push_back(-1);
    for(int i=1;i<n;i++)
    {
        while(!s.empty() && arr[s.top()]>=arr[i])
        {
            s.pop();
        }
        // if no prev is smaller , then assume its index as -1
        if(s.empty())
        v.push_back(-1);
        else
        v.push_back(s.top());

        s.push(i);
    }
    return v;
}

vector<int>nextSmallest(vector<int>&arr)
{
    int n=arr.size();
    vector<int>v;
    stack<int>s;
    s.push(n-1);
    v.push_back(n);
    for(int i=n-2;i>=0;i--)
    {
        while(!s.empty() && arr[s.top()]>=arr[i])
        {
            s.pop();
        }
        // if no next is smaller , then assume its index as n
        if(s.empty())
        v.push_back(n);
        else 
        v.push_back(s.top());

        s.push(i);
    }
    reverse(v.begin(),v.end());
    return v;
}

int maxArea(vector<int>&arr)
{
    int n=arr.size();
    vector<int>ps=prevSmallest(arr);
    vector<int>ns=nextSmallest(arr);
    int res=0;
    for(int i=0;i<n;i++)
    {
        int curr=arr[i];
        // curr+=(i-ps[i]-1)*arr[i];
        curr+=(i-(ps[i]+1))*arr[i];
        // curr+=(ns[i]-i-1)*arr[i];
        curr+=((ns[i]-1)-i)*arr[i];
        res=max(res,curr);
    }
    return res;
}

int main()
{
    vector<int>arr{6,2,5,4,1,5,6};
    cout<<"the max rectangular area of the histogram is "<<maxArea(arr)<<endl;
    return 0;
}
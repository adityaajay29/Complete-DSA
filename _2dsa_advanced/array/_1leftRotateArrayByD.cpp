#include <iostream>
#include <vector>
using namespace std;

vector<int> leftRotate(vector<int>v,int n,int d)
{
    vector<int>store;
    // O(d)
    for(int i=0;i<d;i++)
    {
        store.push_back(v[i]);
    }
    // O(n-d)
    for(int i=d;i<n;i++)
    {
        v[i-d]=v[i];
    }
    // O(d)
    for(int i=n-d,j=0;i<n;i++)
    {
        v[i]=store[j++];
    }
    return v;
}

int main()
{
    vector<int>v{1,2,3,4,5};
    int n=v.size();
    int d=2;
    vector<int>ans=leftRotate(v,n,d);
    for(auto x:ans)
    cout<<x<<" ";
    cout<<endl;
    return 0;
}
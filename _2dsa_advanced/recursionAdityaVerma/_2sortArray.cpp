#include <iostream>
#include <vector>
using namespace std;

void insert(vector<int> &v,int &temp)
{
    if(v.size()==0 || v[v.size()-1]<=temp)
    {
        v.push_back(temp);
        return;
    }
    int val=v[v.size()-1];
    v.pop_back();
    insert(v,temp);
    v.push_back(val);
    return;
}

void sorts(vector<int> &v)
{
    if(v.size()==1)
    return;
    int temp=v[v.size()-1];
    v.pop_back();
    sorts(v);
    insert(v,temp);
}

int main()
{
    int n,a;
    cin>>n;
    vector<int>v(n);
    while(n--)
    {
        cin>>a;
        v.push_back(a);
    }
    // sorts(v);
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++)
    cout<<v[i]<<" ";
    return 0;
}
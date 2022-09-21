#include <iostream>
#include <vector>
using namespace std;

// algo: to find the majority and return any of its index

int majority(vector<int>v,int n)
{
    int res=0;
    int count=1;
    for(int j=1;j<n;j++)
    {
        if(v[j]==v[res])
        {
            count++;
        }
        else
        count--;
        if(count==0)
        {
            res=j;
            count++;
        }
    }
    count=0;
    for(int i=0;i<n;i++)
    {
        if(v[i]==v[res])
        count++;
    }
    if(count<=n/2)
    return -1;
    return res;
}

 int main()
{
    vector<int>v{8,3,4,3,3,4,3,6};
    int n=v.size();
    cout<<"the majority ele index is "<<majority(v,n)<<endl;
    return 0;
}
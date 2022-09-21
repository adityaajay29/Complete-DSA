#include <iostream>
#include <vector>
using namespace std;

void zerosToEnd(vector<int>&v,int n)
{
    int count=0;
    for(int i=0;i<n;i++)
    {
        if(v[i])
        {
            swap(v[count],v[i]);
            count++;
        }
    }
}

int main()
{
    vector<int>v{10,5,0,0,8,0,9,0};
    int n=v.size();
    zerosToEnd(v,n);
    for(auto x:v)
    cout<<x<<" ";
    cout<<endl;
    return 0;
}
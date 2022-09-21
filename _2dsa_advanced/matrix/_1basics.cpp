#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // method 1:
    int m=3;
    int n=2;
    vector<int>arr[m];
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
        arr[i].push_back(i+j+1);
        }
    }
    for(int i=0;i<m;i++)
    {
        for(auto x:arr[i])
        {
            cout<<x<<" ";
        }
        cout<<endl;
        }
    return 0;

    // method 2:
    // vector<vector<int>>arr;
    // int m=3;
    // int n=2;
    // for(int i=0;i<m;i++)
    // {
    //     vector<int>v;
    //     for(int j=0;j<n;j++)
    //     {
    //         v.push_back(i+j+1);
    //     }
    //     arr.push_back(v);
    // }
    // for(int i=0;i<m;i++)
    // {
    //     for(auto x:arr[i])
    //     {
    //         cout<<x<<" ";
    //     }
    //     cout<<endl;
    // }
    // return 0;
}


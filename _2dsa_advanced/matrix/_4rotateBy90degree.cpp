#include <iostream>
#include <vector>
using namespace std;

// efficient approac:
// take transpose and then reverse vertically

void transpose(vector<vector<int> >&arr)
{
    int n=arr.size();
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            swap(arr[i][j],arr[j][i]);
        }
    }
}

void rotate90(vector<vector<int> >&arr)
{
    transpose(arr);
    int n=arr.size();
    for(int i=0;i<n;i++)
    {
        // reversing the rows usig two pointers
        int l=0,h=n-1;
        while(l<h)
        {
            swap(arr[l][i],arr[h][i]);
            l++;
            h--;
        }
    }
}

int main()
{
    vector<vector<int> >arr{
        {1,2,3,10},
        {4,5,6,11},
        {7,8,9,12},
        {67,78,12,23}
    };
    rotate90(arr);
    for(int i=0;i<arr.size();i++)
    {
        for(auto x:arr[i])
        cout<<x<<" ";
        cout<<endl;
    }
    return 0;
}
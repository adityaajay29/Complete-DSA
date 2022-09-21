#include <iostream>
#include <vector>
using namespace std;
// O(n2)
// O(1) space


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

int main()
{
    vector<vector<int> >arr
    {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16}
    };
    transpose(arr);
    for(int i=0;i<arr.size();i++)
    {
        for(auto x:arr[i])
        cout<<x<<" ";
        cout<<endl;
    }
    return 0;
}
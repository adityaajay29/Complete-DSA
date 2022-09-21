#include <iostream>
#include <vector>
using namespace std;

// the concept is to rotate 1st d elements
// then rotate elements from d+1 to n-1
// then rotate the whole array
// TC : O(d+n-d+n)=O(2n)=O(n)
// SC=O(1)

// function to rotate
void reverse(vector<int>&v,int l,int h)
{
    while(l<h)
    {
        swap(v[l++],v[h--]);
    }
}

void leftRotate(vector<int>&v,int n,int d)
{
    reverse(v,0,d-1);
    reverse(v,d,n-1);
    reverse(v,0,n-1);
}

int main()
{
    vector<int>v{1,2,3,4,5,6,7};
    int n=v.size();
    int d=3;
    leftRotate(v,n,d);
    for(auto x:v)
    cout<<x<<" ";
    cout<<endl;
    return 0;
}
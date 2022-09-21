#include <iostream>
#include <vector>
using namespace std;

// approach is to begin the subarray from 1 whenever we see that alternate ele are even or odd
// based on Kadane's Algo
// O(n)

int longestEvenOdd(vector<int>v,int n)
{
    int res=1;
    int curr=1;
    for(int i=1;i<n;i++)
    {
        if(v[i]%2==v[i-1]%2)
        {
            curr=1;
        }
        else
        {
            curr++;
            res=max(res,curr);
        }
    }
    return res;
}

int main()
{
    vector<int>v{1,2,2,4,3,0,3,1,2};
    int n=v.size();
    cout<<"longest Consecutive even odd is "<<longestEvenOdd(v,n)<<endl;
    return 0;
}
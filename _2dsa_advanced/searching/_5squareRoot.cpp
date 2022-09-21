#include <iostream>
using namespace std;

// approach to use binary search 
// similar to find the last occurance problem
// is mid square is smaller than x, then store the mid and change the left
// if now the mid becomes larger, we already have the largest value smaller than x stored in our ans
// O(logx)

int squareRoot(int x)
{
    int l=0;
    int h=x;
    int ans=-1;
    while(l<=h)
    {
        int mid=(l+h)/2;
        int msq=(mid)*(mid);
        if(msq==x)
        return mid;
        else if(msq>x)
        h=mid-1;
        else
        {
            l=mid+1;
            ans=mid;
        }
    }
    return ans;
}

int main()
{
    int x=15;
    // naive sol : O(x^0.5)
    // int x=25;
    // int i=1;
    // while(i*i<=x)
    // {
    //     i++;
    // }
    // cout<<i-1<<endl;
    cout<<squareRoot(x)<<endl;
    return 0;
}
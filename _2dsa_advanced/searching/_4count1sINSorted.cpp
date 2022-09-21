#include <iostream>
#include <vector>
using namespace std;

// using 1st occ approach in Binary Search
// O(logn)

int count1s(vector<int>arr)
{
    int l=0;
    int h=arr.size()-1;
    while(l<=h)
    {
        int mid=(l+h)/2;
        if(arr[mid]==0)
        l=mid+1;
        else
        {
            if(mid==0 || arr[mid-1]==0)
            return (arr.size()-mid);
            else 
            h=mid-1;
        }
    }
    return 0;
}

int main()
{
    vector<int>arr{0,0,1,1,1,1,1,1,1,1,1,1,1,1};
    cout<<"total count of 1s is "<<count1s(arr)<<endl;
    return 0;
}

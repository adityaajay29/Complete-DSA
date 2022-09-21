#include <iostream>
#include <vector>
using namespace std;

// algo for partitioning array with three types of elements
// also called three way partitioning
// similar prob : partition according to element in a range
//                partition with multiple occurance of pivot

void threeWayPart(vector<int>&arr,int n)
{
    // we are maintaining three pointers
    // l for 0s
    // m for 1s
    // h for 2s
    int l=0;
    int m=0;
    int h=n-1;
    while(m<=h)
    {
        switch (arr[m])
        {
        // increment box for 0
        case 0:swap(arr[l],arr[m]);
        l++;
        m++;
        break;
        // increment box for 1
        case 1:m++;
        break;
        // increment box for 2
        case 2:swap(arr[m],arr[h]);
        h--;
        break;
        }
    }
}

int main()
{
    vector<int>arr{2,0,1,1,2,0,0,2,1};
    int n=arr.size();
    threeWayPart(arr,n);
    for(auto x:arr)
    cout<<x<<" ";cout<<endl;
    return 0;
}

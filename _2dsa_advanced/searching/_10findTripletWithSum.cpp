#include <iostream>
#include <vector>
using namespace std;

// using 2 pinter
// O(n^2) if sorted array
// O(nlogn)+O(n^2) = O(n^2) if unsored
// hence approach is good for both types of arrays

bool findTriplet(vector<int>arr,int x)
{
    for(int i=0;i<arr.size()-1;i++)
    {
        int l=i+1;
        int h=arr.size()-1;
        while(l<h)
        {
            if(arr[i]+arr[l]+arr[h]==x)
            return true;
            else if(arr[i]+arr[l]+arr[h]>x)
            h--;
            else 
            l++;
        }
    }
    return false;
}

int main()
{
    vector<int>arr{2,3,4,8,9,20,40};
    int x=60;
    cout<<findTriplet(arr,x)<<endl;
    return 0;
}
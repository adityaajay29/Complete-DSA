#include <iostream>
#include <vector>
using namespace std;

// problem:there are two types of ele in the array
// we have to partition them in two groups in the same array acc to their type

// using lomuto partition, with O(n) time, O(1) space
// can also be done similarly as moving zeros to end

void partition(vector<int>&arr,int n)
{
    int pivot=arr[n-1];
    int i=-1;
    int j=0;
    for(int j=0;j<n-1;j++)
    {
        if(arr[j]%2==0)
        {
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[n-1]);
}

// void partition(vector<int>&arr,int n)
// {
//     int count=0;
//     for(int i=0;i<n;i++)
//     {
//         if(arr[i]%2==0)
//         {
//             swap(arr[i],arr[count]);
//             count++;
//         }
//     }
// }

int main()
{
    vector<int>arr{24,5,67,12,32,9,11,34};
    int n=arr.size();
    partition(arr,n);
    for(auto x:arr)
    cout<<x<<" ";
    cout<<endl;
    return 0;
}
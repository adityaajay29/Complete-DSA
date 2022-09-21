#include <iostream>
using namespace std;
// bubble sort is stable sorting, O(n2) time complex.
// as it doesn't swap two elements with same value, and their order remain same
// idea is to compare adjecent elements until the largest element is at end
// then, repeat this comaprison for all elements until we reach the element which is already at last
// then repeat 

// we can optimise bubble sort by maintaing a variable swapped to store if swapping is done or not
// this will be helpful if our array is already sorted or gets sorted in middle
// in this case, time is O(n*d)
void bubbleSort(int arr[],int n)
{
    // i for repeating the swapping of jth element
    // we can optimise bubble sort by maintaing a variable swapped to store if swapping is done or not
    // this will be helpful if our array is already sorted or gets sorted in middle
    // in this case, time is O(n*d)
    bool swapped=false;
    for(int i=0;i<n-1;i++)
    {
        // largest already going to end, so why include that in our iteration
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr[j],arr[j+1]);
                swapped=true;
            }
        }
        if(swapped==false)
        break;
    }
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}

int main()
{
    int arr[]={10,8,20,5};
    bubbleSort(arr,4);
    cout<<endl;
    return 0;
}
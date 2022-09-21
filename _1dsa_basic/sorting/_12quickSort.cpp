#include <iostream>
using namespace std;

// quick sort is divide and conqueror, using partition method
// no need to merge
// in place algo
// using lomuto partition algo in this sorting
// O(nlogn) average time, O(n^2) worst time -> when partiotion is single sided recursively
// O(1) space 
// not stable
// better, as it is tail recursive

// to prevent ending up in worst case, we can use random function, to generate a random number
// from l to r, and assiging that as the pivot

int partition(int arr[],int l,int h)
{
    // marking last element as pivot
    int pivot=arr[h];
    // starting from one posi before leftmost ele
    // initially, small window is empty
    int i=l-1;
    // starting loop from j=l
    for(int j=l;j<h;j++)
    {
        // if the current jth ele is smaller than pivot 
        // increase the window of small ele, then put that small ele in it
        if(arr[j]<=pivot)
        {
            i++;
            swap(arr[i],arr[j]);
        }
    }
    // put the pivot ele at correct posi
    swap(arr[i+1],arr[h]);
    // return the index of pivot
    return i+1;
}

void quicksort(int arr[],int l,int h)
{
    if(l<h)
    {
        // getting the pivot index, and dividing the array around the pivot
        int pivotIndex=partition(arr,l,h);
        // pivot is not included in the sorting
        // recursively sorting left to the pivot
        quicksort(arr,l,pivotIndex-1);
        // recursively sorting right to the pivot
        quicksort(arr,pivotIndex+1,h);
    }
}
 
int main()
{
    int arr[]={8,4,7,9,3,10,3,5};
    quicksort(arr,0,6);
    for(auto x:arr)
    cout<<x<<" ";
    cout<<endl;
    return 0;
}
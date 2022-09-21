#include <iostream>
using namespace std;
// O(n) in best case, when array is sorted
// O(n2) in worst time, when array is reversly sorted
// in place
// best performance among all sorting algo if input size is small 

void insertionSort(int arr[],int n)
{
    // start from the second element
    for(int i=1;i<n;i++)
    {
        // store an element in a key
        int storeKey=arr[i];
        // start another loop from 1st element, i-1 th element
        int j=i-1;
        while(j>=0 && arr[j]> storeKey)
        {
            // shift the elements to right if the jth element is larger than key value
            arr[j+1]=arr[j];
            // decrement key
            j--;
        }
        // give the key value to the position where the shifting ends
        arr[j+1]=storeKey;
    }
    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
}

int main()
{
    int arr[]={50,20,40,60,10,30};
    insertionSort(arr,6);
    cout<<endl;
    return 0;
}
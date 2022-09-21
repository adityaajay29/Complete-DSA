#include <iostream>
#include <vector>
using namespace std;

// O(n) time
// O(1) space
// not stable algo

int lomuto(vector<int> &arr, int l, int h, int p)
{
    // putting the element to be pivoted at last 
    swap(arr[p],arr[h]);
    int pivot=arr[h];
    // i represents window of smaller element and j represents window of larger elements than pivot
    // starting with an empty window of smaller elements
    int i=l-1; //i starting from -1
    for(int j=l;j<h;j++)
    {
        if(arr[j]<=pivot)
        {
            // increasing the size of smaller element's window
            i++;
            // putting the smaller ele in smaller's window
            swap(arr[j],arr[i]);
        }
    }
    // putting the pivot element just after smaller element's window
    swap(arr[i+1],arr[h]);
    // returning pivot's index
    return i+1;
}

int main()
{
    vector<int> arr{3,24,1,20,14,9,22,17};
    int n = arr.size();
    cout<<"thr pivot point index is "<<lomuto(arr,0,n - 1, n - 1)<<endl;
    for(auto x:arr)
    cout<<x<<" ";
    cout<<endl;
    return 0;
}

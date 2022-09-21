#include <iostream>
#include <vector>
using namespace std;

int leftChild(int i)
{
    return (2 * i + 1);
}

int rightChild(int i)
{
    return (2 * i + 2);
}

int parent(int i)
{
    return (i - 1)/2;
}

void maxHeapify(vector<int> &arr, int i, int n)
{
    int largest = i;
    int left = leftChild(i);
    int right = rightChild(i);
    if(left < n && arr[left] > arr[i])
    largest = left;
    if(right < n && arr[right] > arr[largest])
    largest = right;
    if(largest != i)
    {
        swap(arr[i], arr[largest]);
        maxHeapify(arr, largest, n);
    }
}

void buildHeap(vector<int> &arr, int n)
{
    int i = parent(n - 1);
    while(i>=0)
    {
        maxHeapify(arr, i, n);
        i--;
    }
}

int main()
{
    int n;
    cin>>n;
    vector<int> arr;
    int val;
    int i = n;
    while(i--)
    {
        cin>>val;
        arr.push_back(val);
    }
    buildHeap(arr, n);
    for(int x : arr)
    {
        cout<<x<<" ";
    }
    cout<<endl;
}
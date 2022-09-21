#include <iostream>
using namespace std;

// heap sort is improved version of selection sort
// uses max heap data structure
// O(nlogn) in all cases

class maxHeap
{
    public:
    int *arr;
    int size;
    int cap;
    // constructor
    maxHeap(int c)
    {
        arr=new int[c];
        size=0;
        cap=c;
    }
    
    int leftChild(int i)
    {
        return (2*i+1);
    }
    int rightChild(int i)
    {
        return (2*i+2);
    }
    int parent(int i)
    {
        return (i-1)/2;
    }
    void createArr(int x)
    {
        if(size==cap)
        return;
        size++;
        arr[size-1]=x;
    }
    // heapify the binary heap, if and only if 1 element is incorrect
    // start from root
    void maxheapify(int size,int i=0)
    {
        // assuming index of root as largest ele
        int largest=i;
        // finding index of left child
        int left=leftChild(i);
        // finding index of right child
        int right=rightChild(i);
        // if left child exists and is greater than curr largest, make it's index as largest
        if(left<size && arr[left]>arr[i])
        largest=left;
        // if right child exists and is greater than curr largest, make it's index as largest
        if(right<size && arr[right]>arr[largest])
        largest=right;
        // if index for largest element has changed, swap it with previous largest marked index
        if(largest!=i)
        {
            swap(arr[i],arr[largest]);
            // call heapify function for current largest index
            maxheapify(size,largest);
        }
    }
    void buildHeap()
    {
        // starting form last inner node
        int i=parent(size-1);
        // going till 0th node
        while(i>=0)
        {
            maxheapify(size,i);
            i--;
        }
    }
    void heapSort()
    {
        // starting from last ele
        int i=size-1;
        while(i>0)
        {
            // swap last ele with the largest ele
            swap(arr[0],arr[i]);
            // call heapify function for heap with 1 less, i.e., remove the last ele for heapify function call
            maxheapify(i,0);
            i--;
        }
    }
};

int main()
{
    maxHeap mh(5);
    mh.createArr(50);
    mh.createArr(20);
    mh.createArr(10);
    mh.createArr(4);
    mh.createArr(15 );
    mh.buildHeap();
    mh.heapSort();
    for(int i=0;i<mh.size;i++)
    cout<<mh.arr[i]<<" ";
    cout<<endl;
    return 0;
}
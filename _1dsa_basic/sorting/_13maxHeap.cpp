#include <iostream>
using namespace std;

class maxHeap
{
    public:
    int *arr;
    int size;
    int cap;
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
};

int main()
{
    maxHeap maxH(5);
    maxH.createArr(50);
    maxH.createArr(20);
    maxH.createArr(10);
    maxH.createArr(4);
    maxH.createArr(15 );
    maxH.buildHeap();
    for(int i=0;i<maxH.size;i++)
    cout<<maxH.arr[i]<<" ";
    cout<<endl;
    return 0;
}
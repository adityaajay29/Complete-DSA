#include <iostream>
using namespace std;

class minHeap
{
    public:
    int *arr;
    int size;
    int cap;
    minHeap(int c)
    {
        size=0;
        cap=c;
        arr=new int[c];
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
    void createHeap(int x)
    {
        if(size==cap)
        return;
        size++;
        arr[size-1]=x;
    }
    void heapify(int i=0)
    {
        int smallest=i;
        int left=leftChild(i);
        int right=rightChild(i);
        // checking if left child exists and is smaller or not
        if(left<size && arr[left]<arr[i])
            smallest=left;
        // checking if right child exists and is smaller or not
        else if(right<size && arr[right]<arr[smallest])
            smallest=right;
        // checking if smallest is not the root node
        if(smallest!=i)
        {
            // swap their data
            swap(arr[smallest],arr[i]);
            // call heapify for new smallest 
            heapify(smallest);
        }
    }
    int extractMin()
    {
        if(size==0)
        return INT_MAX;
        if(size==1)
        {
            size--;
            return arr[0];
        }
        swap(arr[0],arr[size-1]);
        size--;
        heapify();
        return arr[size];
    }
};

int main()
{
    minHeap h(10);
    h.createHeap(20);
    h.createHeap(25);
    h.createHeap(30);
    h.createHeap(35);
    h.createHeap(40);
    h.createHeap(80);
    h.createHeap(32);
    h.createHeap(100);
    h.createHeap(70);
    h.createHeap(60);
    cout<<h.extractMin()<<endl;
    for(int i=0;i<h.size;i++)
    cout<<h.arr[i]<<" ";
    cout<<endl;
    return 0;
}
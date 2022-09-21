#include <iostream>
using namespace std;

class heap
{
    public:
    int *arr;
    int size;
    int cap;
    heap(int c)
    {
        cap=c;
        size=0;
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
        int left=leftChild(i);
        int right=rightChild(i);
        int smallest=i;
        if(left<size && arr[left]<arr[i])
        smallest=left;
        if(right<size && arr[right]<arr[smallest])
        smallest=right;
        if(smallest!=i)
        {
            swap(arr[i],arr[smallest]);
            heapify(smallest);
        }
    }
    void buildHeap()
    {
        // heapify starting from the last child's parent
        // ending to 0th index 
        int i=parent(size-1);
        while(i>=0)
        {
            heapify(i);
            i--;
        }
    }
};

int main()
{
    heap h(10);
    // h.createHeap(10);
    // h.createHeap(5);
    // h.createHeap(20);
    // h.createHeap(2);
    // h.createHeap(4);
    // h.createHeap(8);

    h.createHeap(40);
    h.createHeap(20);
    h.createHeap(30);
    h.createHeap(35);
    h.createHeap(25);
    h.createHeap(80);
    h.createHeap(32);
    h.createHeap(100);
    h.createHeap(70);
    h.createHeap(60);

    h.buildHeap();
    for(int i=0;i<h.size;i++)
    cout<<h.arr[i]<<" ";
    cout<<endl;
    return 0;
}
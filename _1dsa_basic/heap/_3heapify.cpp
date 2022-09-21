#include <iostream>
using namespace std;
// heapify fixes the binary heap only if one node is not correct
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

    void insert(int x)
    {
        if(size==cap)
        return;
        size++;
        arr[size-1]=x;
        int i=size-1;
        while(i!=0 && arr[i]<arr[parent(i)])
        {
            swap(arr[i],arr[parent(i)]);
            i=parent(i);
        }
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
        if(right<size && arr[right]<arr[smallest])
            smallest=right;
        // checking if smallest is not the root node
        if(smallest!=i)
        {
            swap(arr[smallest],arr[i]);
            heapify(smallest);
        }
    }
};

int main()
{
    minHeap h(10);
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

    for(int i=0;i<h.size;i++)
    cout<<h.arr[i]<<" ";
    cout<<endl;
    h.heapify();
    for(int i=0;i<h.size;i++)
    cout<<h.arr[i]<<" ";
    cout<<endl;
    return 0;
}
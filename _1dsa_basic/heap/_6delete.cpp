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
    void decrease(int i,int x)
    {
        arr[i]=x;
        while(i!=0 && arr[i]<arr[parent(i)])
        {
            swap(arr[i],arr[parent(i)]);
            i=parent(i);
        }
    }
    void del(int i)
    {
        decrease(i,INT_MIN);
        extractMin();
    }
};

int main()
{
    minHeap h(8);
    h.createHeap(10);
    h.createHeap(20);
    h.createHeap(30);
    h.createHeap(40);
    h.createHeap(50);
    h.createHeap(35);
    h.createHeap(38);
    h.createHeap(45);
    h.del(3);
    for(int i=0;i<h.size;i++)
    cout<<h.arr[i]<<" ";
    cout<<endl;
    return 0;
}
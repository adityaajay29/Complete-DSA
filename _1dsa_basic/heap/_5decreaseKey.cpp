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
        cap=c;
        size=0;
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
    void decreaseKey(int i,int x)
    {
        arr[i]=x;
        while(i!=0 && arr[i]<arr[parent(i)])
        {
            swap(arr[i],arr[parent(i)]);
            i=parent(i);
        }
    }
};

int main()
{
    minHeap h(6);
    h.createHeap(10);
    h.createHeap(20);
    h.createHeap(40);
    h.createHeap(80);
    h.createHeap(100);
    h.createHeap(70);
    h.decreaseKey(3,5); 
    for(int i=0;i<h.size;i++)
    cout<<h.arr[i]<<" ";
    cout<<endl;
    return 0;
}
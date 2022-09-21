#include <iostream>
using namespace std;

struct minHeap
{
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
        return ((i-1)/2);
    }
    void insert(int x)
    {
        if(size==cap)
        return;
        size++;
        arr[size-1]=x;
        int i=size-1;
        // traversing as long as node is smaller than parent
        while(i && arr[i]<arr[parent(i)])
        {
            swap(arr[i], arr[parent(i)]);
            i=parent(i);
        }
    }
};

int main()
{
    minHeap h(10);
    // h.insert(10);
    // h.insert(20);
    // h.insert(15);
    // h.insert(40);
    // h.insert(50);
    // h.insert(100);
    // h.insert(25);
    // h.insert(45);
    // h.insert(12);


    h.insert(40);
    h.insert(20);
    h.insert(30);
    h.insert(35);
    h.insert(25);
    h.insert(80);
    h.insert(32);
    h.insert(100);
    h.insert(70);
    h.insert(60);

    for(int i=0;i<h.size;i++)
    cout<<h.arr[i]<<" ";
    return 0;
}
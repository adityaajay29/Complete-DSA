#include <iostream>
using namespace std;

struct minheap
{
    int cap;
    int size;
    int *arr;

    minheap(int n)
    {
        cap = n;
        size = 0;
        arr = new int[n];
    }

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
    void insert(int x)
    {
        if(size == cap)
        return;
        size++;
        arr[size - 1] = x;
        int i = size - 1;
        while(i && arr[i] < arr[parent(i)])
        {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }
    void heapify(int x)
    {
        int smallest = x;
        int left = leftChild(x);
        int right = rightChild(x);
        if(left < size && arr[left] < arr[x])
        {
            smallest = left;
        }
        if(right < size && arr[right] < arr[smallest])
        {
            smallest = right;
        }
        if(smallest != x)
        {
            swap(arr[smallest], arr[x]);
            heapify(smallest);
        }
    }

    void decreaseKey(int i, int val)
    {
        arr[i] = val;
        while(i && arr[i] < arr[parent(i)])
        {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }

    int getMin()
    {
        return arr[0];
    }

    int extractMin()
    {
        if(size == 0)
        return INT_MAX;
        if(size == 1)
        {
            size--;
            return arr[0];
        }
        swap(arr[0], arr[size - 1]);
        size--;
        heapify(0);
        return arr[size];
    }
    void deleteKey(int i)
    {
        decreaseKey(i, INT_MIN);
        extractMin();
    }
};

int main()
{
    minheap h(11);
    h.insert(3);
    h.insert(2);
    h.deleteKey(1);
    h.insert(15);
    h.insert(5);
    h.insert(4);
    h.insert(45);
    cout << h.extractMin() << " ";
    cout << h.getMin() << " ";
    h.decreaseKey(2, 1);
    cout << h.getMin()<<endl;
    return 0;
}
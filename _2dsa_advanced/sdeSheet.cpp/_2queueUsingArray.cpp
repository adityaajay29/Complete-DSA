#include <iostream>
using namespace std;

struct queue
{
    int cap;
    int low;
    int high;
    int sz;
    int *arr;
    queue(int c)
    {
        cap = c;
        low = 0;
        high = -1;
        sz = 0;
        arr = new int[c];
    }

    void push(int x)
    {
        if(sz == cap)
        return;
        high++;
        sz++;
        arr[high % sz] = x;

    }

    void pop()
    {
        if(sz == 0)
        return;
        sz--;
        low++;
    }

    int front()
    {
        if(sz == 0)
        return INT_MAX;

        return arr[low % sz];
    }

    int size()
    {
        return sz;
    }

    bool empty()
    {
        return sz == 0;
    }
};

int main()
{
    queue q(5);
    cout<<q.empty()<<" "<<q.size()<<endl;
    q.push(7);
    cout<<q.size()<<" "<<q.front()<<endl;
    q.push(1);
    q.push(4);
    q.push(3);
    q.push(2);
    cout<<q.size()<<" "<<q.front()<<endl;
    q.pop();
    q.push(12);
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    cout<<q.size()<<" "<<q.front()<<endl;
    cout<<q.empty()<<endl;
    return 0;
}
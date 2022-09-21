#include <iostream>
using namespace std;

struct myStack
{
    // members
    int *arr;
    int cap;
    int top1;
    int top2;
    // constructor
    myStack(int n)
    {
        cap=n;
        top1=-1;
        top2=n;
        arr=new int[n];
    }
    void push1(int x)
    {
        // push possible when there is atleast 1 gap btwn top1 and top2
        if(top1<top2-1)
        {
            top1++;
            arr[top1]=x;
        }
    }
    void push2(int x)
    {
        if(top1<top2-1)
        {
            top2--;
            arr[top2]=x;
        }
    }
    int pop1()
    {
        // preventing underflow
        if(top1>0)
        {
            int popped=arr[top1];
            top1--;
            return popped;
        }
        else
        exit(1);
    }
    int pop2()
    {
        // preventing overflow
        if(top2<cap)
        {
            int popped=arr[top2];
            top2++;
            return popped;
        }
        else 
        exit(1);
    }
};

int main()
{
    myStack twoStacks(6);
    twoStacks.push1(2);
    twoStacks.push2(4);
    twoStacks.push1(45);
    twoStacks.push2(78);
    twoStacks.push1(23);
    twoStacks.push1(7);
    cout<<twoStacks.pop1()<<endl;
    for(auto i=0;i<twoStacks.cap;i++)
    cout<<twoStacks.arr[i]<<" ";
    return 0;
}
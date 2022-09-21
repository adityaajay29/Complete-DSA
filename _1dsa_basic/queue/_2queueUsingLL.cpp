#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
    // constructer
    node(int x)
    {
        data=x;
        next=NULL;
    }
};
struct queue
{
    node *front,*rear;
    int size;
    // constructer
    queue()
    {
        front=rear=NULL;
        size=0;
    }

    void enqueue(int x)
    {
        node *temp=new node(x);
        size++;
        if(front==NULL)
        {
        front=rear=temp;
        return;
        }
        else
        {
            rear->next=temp;
            rear=temp; //we are changing rear, not temp, so LHS will be rear
        }
    }

    void dequeue()
    {
        if(front==NULL)
        return;
        node *temp=front->next;
        size--;
        front=front->next;
        if(front==NULL) //if single node
        rear=NULL;
        delete temp;
    }
};

int main()
{
    queue q;
    q.enqueue(10);
    q.enqueue(20);
    cout<<q.front->data<<endl;
    cout<<q.rear->data<<endl;
    return 0;
}
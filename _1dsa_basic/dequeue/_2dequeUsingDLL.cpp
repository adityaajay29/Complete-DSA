#include <iostream>
using namespace std;
// creating a doubly LL
struct node
{
    int data;
    node *prev;
    node *next;
    node(int x)
    {
        data=x;
        next=prev=NULL;
    }
};
// creating the dequeue, with 2 pointers front and rear
struct deque
{
    node *front;
    node *rear;
    int size;
    deque()
    {
        front=rear=NULL;
        size=0;
    }
    void insertFront(int x)
    {
        node *temp=new node(x);
        size++;
        if(front==NULL)
        front=rear=temp;
        else
        {
            temp->next=front;
            front->prev=temp;
            front=temp;
        }
    }
    void insertRear(int x)
    {
        node *temp=new node(x);
        size++;
        if(rear==NULL)
        front=rear=temp;
        else
        {
            rear->next=temp;
            temp->prev=rear;
            rear=temp;
        }
    }
    void deleteFront()
    {
        if(front==NULL)
        return;
        else if(front==NULL)
        rear=NULL;
        else
        {
            size--;
            node *temp=front;
            front=front->next;
            front->prev=NULL;
            delete temp;
        }
    }
    void deleteRear()
    {
        if(rear==NULL)
        return;
        else if(front==NULL)
        rear=NULL;
        else
        {
            size--;
            node *temp=rear;
            rear=rear->prev;
            rear->next=NULL;
            delete temp;
        }
    }
    bool isEmpty()
    {
        if(front==NULL && rear==NULL)
        return true;
        else 
        return false;
    }
};

int main()
{
    deque dq;
    dq.insertFront(10);
    dq.insertRear(40);
    dq.insertFront(26);
    dq.insertRear(56);
    // dq.deleteFront();
    // dq.deleteRear();
    cout<<"the front is "<<dq.front->data<<" and the rear is "<<dq.rear->data<<" "<<endl;
    cout<<dq.size<<endl;
    if(dq.isEmpty()==true)
    cout<<"yes"<<endl;
    return 0;
}
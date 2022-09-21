#include <iostream>
using namespace std;

struct node
{
    int data;
    node *prev;
    node *next;
    node(int x)
    {
        data=x;
        prev=next=NULL;
    }
};

node *insertBeginCDLL(node *head,int x)
{
    node *temp=new node(x);
    if(head==NULL)
    {
        temp->prev=temp;
        temp->next=temp;
        return temp;
    }
    int store=temp->data;
    temp->data=head->data;
    head->data=store;
    temp->next=head->next;
    head->next=temp;
    temp->prev=head;
    temp->next->prev=temp;
    return head;

    // temp->prev=head->prev;
    // temp->next=head;
    // head->prev->next=temp;
    // head->prev=temp;
    // return temp;
}

void printCDLL(node *head)
{
    node *curr=head->next;
    if(head==NULL)
    return;
    cout<<head->data<<" ";
    while(curr!=head)
    {
        cout<<curr->data<<" ";
        curr=curr->next;
    }
}

int main()
{
    node *head=nullptr;
    head=insertBeginCDLL(head,5);
    head=insertBeginCDLL(head,23);
    head=insertBeginCDLL(head,34);
    head=insertBeginCDLL(head,55);
    printCDLL(head);
    return 0;
}
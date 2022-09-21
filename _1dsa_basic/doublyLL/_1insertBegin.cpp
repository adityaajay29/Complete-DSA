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

node *insertBeginDLL(node *head,int x)
{
    node *temp=new node(x);
    if(head==NULL)
    return temp;
    temp->next=head;
    head->prev=temp;
    return temp; //because temp is the new head
}

void printDLL(node *head)
{
    node *curr=head;
    if(head==NULL)
    return;
    while (curr!=NULL)
    {
        cout<<curr->data<<" ";
        curr=curr->next;
    }
}

int main()
{
    node *head=new node(10);
    head->next=new node(20);
    head->next->prev=head;
    head->next->next=new node(30);
    head->next->next->prev=head->next;
    printDLL(head);
    cout<<endl;
    head=insertBeginDLL(head,5);
    printDLL(head);
    cout<<endl;
    return 0;
}


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

node *deleteLastDLL(node *head)
{
    if(head==NULL)
    return head;
    if(head->next==NULL)
    {
        delete head;
        return NULL;
    }
    node *curr=head;
    while(curr->next->next!=NULL)
    {
        curr=curr->next;
    }
    node *temp=curr->next;
    curr->next=NULL;
    delete temp;
    return head;
    // while(curr->next!=NULL)
    // {
    //     curr=curr->next;
    // }
    // curr->prev->next=NULL;
    // delete curr;
    // return head;
}

void printDLL(node *head)
{
    node *curr=head;
    if(head==nullptr)
    return;
    while (curr!=nullptr)
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
    head->next->next->next=new node(40);
    head->next->next->next->prev=head->next->next;
    printDLL(head);
    cout<<endl;
    head=deleteLastDLL(head);
    printDLL(head);
    cout<<endl;
    return 0;
}
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

node *insertEndDLL(node *head,int x)
{
    node *temp=new node(x);
    if(head==NULL)
    return temp;
    node *curr=head;
    while(curr->next!=NULL)
    {
        curr=curr->next;
    }
    curr->next=temp;
    temp->prev=curr;
    return head;
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
    head=insertEndDLL(head,5);
    head=insertEndDLL(head,23);
    head=insertEndDLL(head,34);
    head=insertEndDLL(head,32);
    int ins=0;
    while(ins<5)
    {
    head=insertEndDLL(head,ins*10+1);
    ins++;
    }
    printDLL(head);
    cout<<endl;
    return 0;
}
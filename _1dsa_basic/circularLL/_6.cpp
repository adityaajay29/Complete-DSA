#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
    node(int x)
    {
        data=x;
        next=NULL;
    }
};

node *deleteHeadCLL(node *head)
{
    if(head==NULL)
    return NULL;
    if(head->next==head)
    {
        delete head;
        return NULL;
    }
    node *temp=head->next; //so that we delete the copy of head next, not head next itself
    // swapping head and temp datas
    int store=head->data;
    head->data=temp->data;
    temp->data=store;
    // deleting temp node
    head->next=temp->next;
    delete temp;
    return head;
}

void printCLL(node *head)
{
    if(head==NULL)
    return;
    cout<<head->data<<" "; //to handle single node case
    node *curr=head->next;
    while(curr!=head)
    {
        cout<<curr->data<<" ";
        curr=curr->next;
    }
}

int main()
{
    node *head=new node(10);
    head->next=new node(20);
    head->next->next=new node(30);
    head->next->next->next=new node(40);
    head->next->next->next->next=head;
    printCLL(head);
    cout<<endl;
    head=deleteHeadCLL(head);
    // head=deleteHeadCLL(head);
    printCLL(head);
    cout<<endl;
    return 0;
}
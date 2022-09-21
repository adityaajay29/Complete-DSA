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

// approach is to insert the node at 2nd position
// and then, swap the head with temp node at 2nd position
// time complexity is O(n)

node *effiInsertBeginCLL(node *head,int x)
{
    node *temp=new node(x);
    if(head==NULL)
    {
        temp->next=temp;
        return temp;
    }
    temp->next=head->next;
    head->next=temp;
    // swapping data of head and temp
    int store=temp->data;
    temp->data=head->data;
    head->data=store;
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
    head=effiInsertBeginCLL(head,5);
    head=effiInsertBeginCLL(head,90);
    printCLL(head);
    cout<<endl;
    return 0;
}
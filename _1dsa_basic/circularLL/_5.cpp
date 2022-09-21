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
// O(1) solution
node *effiInsertEndCLL(node *head,int x)
{
    node *temp=new node(x);
    if(head==NULL)
    {
        temp->next=temp;
        return temp;
    }
    // inserting node after head
    temp->next=head->next;
    head->next=temp;
    // swapping head with temp
    int store=temp->data;
    temp->data=head->data;
    head->data=store;
    // making temp our new head
    return temp;
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
    head=effiInsertEndCLL(head,5);
    // head=effiInsertEndCLL(head,90);
    printCLL(head);
    cout<<endl;
    return 0;
}

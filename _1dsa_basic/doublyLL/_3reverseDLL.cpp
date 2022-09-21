#include <iostream>
using namespace std;

struct node 
{
    int data;
    node *next;
    node *prev;
    node(int x)
    {
        data=x;
        prev=next=nullptr;
    }
};

node *reverseDLL(node *head)
{
    if(head==nullptr)
    return nullptr;
    if(head->next==nullptr)
    return head;
    // temp to store the curr prev to swap next and prev
    node *temp=nullptr;
    node *curr=head;
    while(curr!=nullptr) 
    {   //swapping
        temp=curr->prev;
        curr->prev=curr->next;
        curr->next=temp;
        //swapping ends
        curr=curr->prev; //curr prev is new curr next, as we have swapped prev and next
    }
    return temp->prev; //current will become null, but the temp will still be 2 nodes before curr
                       //as temp is updated at the beginning of the loop, so it doesn't get chance to update
                       //to last node of the list when curr becomes null pointer
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
    printDLL(head);
    cout<<endl;
    head=reverseDLL(head);
    printDLL(head);
    cout<<endl;
    return 0;
}

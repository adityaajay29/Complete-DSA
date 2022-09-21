#include <iostream>
using namespace std;

struct node
{
    int key;
    node *left;
    node *right;
    node(int x)
    {
        key=x;
        left=right=NULL;
    }
};

int floorVal(node *root,int x)
{
    static int floor=INT_MAX;
    if(!root)
    return floor;
    if(root->key==x)
    return root->key;
    else if(x>root->key)
    {
        floor=root->key;
        floor=max(floor,floorVal(root->right,x));
    }
    else
    floor=max(floor,floorVal(root->left,x));
    return floor;
}

int main()
{
    node *root=new node(8);
    root->left=new node(5);
    root->left->left=new node(4);
    root->left->right=new node(7);
    root->left->right->left=new node(6);
    root->right=new node(12);
    root->right->left=new node(10);
    root->right->right=new node(14);
    root->right->right->left=new node(13);
    cout<<"the floor val is "<<floorVal(root,1)<<endl;
    return 0;
}
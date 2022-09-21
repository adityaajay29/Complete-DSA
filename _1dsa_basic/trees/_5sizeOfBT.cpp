#include <iostream>
using namespace std;

struct node
{
    int key;
    node *left,*right;
    node(int x)
    {
        key=x;
        left=right=NULL;
    }
};

int size(node *root)
{
    if(root==NULL)
    return 0;
    return size(root->left)+size(root->right)+1; //+1 to add the root node along with left and right child
}

int main()
{
    node *root=new node(10);
    root->left=new node(20);
    root->right=new node(30);
    root->right->left=new node(40);
    root->right->right=new node(50);
    cout<<"the size of the tree is "<<size(root)<<endl;
    return 0;
}
#include <iostream>
using namespace std;

struct node
{
    int key;
    node *left,*right;
    node(int x)
    {
        key=x;
        left=right=nullptr;
    }
};

int maxEle(node *root)
{
    if(root==NULL)
    // let the max ele is -infinity
    return INT_MIN;
    return max(root->key,max(maxEle(root->left),maxEle(root->right)));  //comparing max of left and right
                                                                        // with the root node's key
}

int main()
{
    node *root=new node(10);
    root->left=new node(20);
    root->right=new node(30);
    root->right->left=new node(40);
    root->right->right=new node(50);
    cout<<"the max element is "<<maxEle(root)<<endl;
    return 0;
}
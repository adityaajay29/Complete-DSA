#include <iostream>
using namespace std;

// creating the structure of a binary tree
// with each node having a key
// and two pointers for left and right child
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

                                        //        10
                                        //       /  \
                                        //      20   30
                                        //     /
                                        //    40

int main()
{
    node *root=new node(10);
    root->left=new node(20);
    root->right=new node(30);
    root->left->left=new node(40);
    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

// approach:
// since we want to keep track of left most (right most) ele
// we will use recursive appr instead of iterative

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

void leftView(node *root,int level,vector<int>&ans)
{
    if(root==NULL)
    return;
    // we only need to print the left most ele of a given level
    // so we use a trick here: if the size of vector is same as the lvl of tree
    // then only we push that node of lvl in the vector
    // so that no other ele than the leftmost node is inserted in the vector
    if(level==ans.size())
    ans.push_back(root->key);
    leftView(root->left,level+1,ans);
    leftView(root->right,level+1,ans);
}

// similar to leftView
// only diff is function call for right and left swapped for recursion

void rightView(node *root,int level,vector<int>&ans2)
{
    if(root==nullptr)
    return;
    if(level==ans2.size())
    ans2.push_back(root->key);
    rightView(root->right,level+1,ans2);
    rightView(root->left,level+1,ans2);
}

int main()
{
    node *root=new node(1);
    root->left=new node(2);
    root->left->left=new node(4);
    root->left->right=new node(5);
    root->left->right->left=new node(6);
    root->right=new node(3);
    root->right->right=new node(7);
    vector<int>ans;
    leftView(root,0,ans);
    cout<<"the left view of the tree is ";
    for(auto x:ans)
    cout<<x<<" ";
    cout<<endl;
    vector<int>ans2;
    rightView(root,0,ans2);
    cout<<"the right view of the tree is ";
    for(auto x:ans2)
    cout<<x<<" ";
    return 0;
}
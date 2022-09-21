#include <iostream>
using namespace std;

int dp[101];

struct node
{
    node *left, *right;
    int key;
    node(int data)
    {
        left = right = nullptr;
        key = data;
    }
};

int helper(node *root, int &res)
{
    if(root == nullptr)
    return 0;

    int lh = helper(root->left, res);
    int rh = helper(root->right, res);
    int temp = 1 + max(lh, rh);
    int ans = max(temp, lh + rh);
    // ans = max(temp, l+r+1) will give the no of nodes in the diameter
    res = max(res, ans);
    return temp;
}

int diameter(node *root, int &res)
{
    // int res;
    helper(root, res);
    return res;
}

int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    root->left->right->left = new node(8);
    root->right->left->right = new node(9);
    root->right->left->right->left = new node(10);
    int res = INT_MIN;
    cout<<"the height of tree is "<<helper(root, res)<<endl;
    cout<<"the diameter of tree is "<<diameter(root, res)<<endl;
    return 0;
}
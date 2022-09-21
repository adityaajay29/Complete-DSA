#include <iostream>
using namespace std;

struct node
{
    node *left, *right;
    int val;
    node(int x)
    {
        val = x;
        left = right = nullptr;
    }
};

int solve(node *root, int &res)
{
    if(root == nullptr)
    return 0;

    int lh = solve(root->left, res);
    int rh = solve(root->right, res);
    // even if children giving negative val, include it
    int temp = root->val + max(lh, rh);
    int ans = max(temp, lh + rh + root->val);
    res = max(res, ans);
    
    return temp;
}

int maxPathSum(node *root, int &res)
{
    solve(root, res);
    return res;
}

int main()
{
    struct node *root = new node(-15);
    root->left = new node(5);
    root->right = new node(6);
    root->left->left = new node(-8);
    root->left->right = new node(1);
    root->left->left->left = new node(2);
    root->left->left->right = new node(6);
    root->right->left = new node(3);
    root->right->right = new node(9);
    root->right->right->right= new node(0);
    root->right->right->right->left= new node(4);
    root->right->right->right->right= new node(-1);
    root->right->right->right->right->left= new node(10);
    int res = INT_MIN;
    cout<<"the max path sum from leaf to leaf is "<<maxPathSum(root, res)<<endl;
    return 0;
}
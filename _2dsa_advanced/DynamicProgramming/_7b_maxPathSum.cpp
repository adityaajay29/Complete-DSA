#include <iostream>
using namespace std;

struct node
{
    node *left, *right;
    int val;
    node(int x)
    {
        left = right = nullptr;
        val = x;
    }
};

int solve(node *root, int &res)
{
    if(root == nullptr) 
    return 0;

    int l = solve(root->left, res);
    int r = solve(root->right, res);
    // taking max of root val or child to avoid negative child vals (if there)
    int temp = max(root->val + max(l, r), root->val);
    int ans = max(temp, l + r + root->val);
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
    node *root = new node(10);
    root->left = new node(12);
    root->right = new node(7);
    root->left->left = new node(-2);
    root->left->right = new node(4);
    root->right->left = new node(2);
    root->right->right = new node(-2);
    root->left->right->left = new node(-3);
    root->right->right->right = new node(3);
    root->right->right->right->left = new node(-4);
    int res = INT_MIN;
    cout<<"the max path sum is "<<maxPathSum(root, res)<<endl;
    return 0;
}
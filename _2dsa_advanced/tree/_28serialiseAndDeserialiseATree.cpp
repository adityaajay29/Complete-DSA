#include <iostream>
#include <queue>
#include <string>
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

string serialise(node *root)
{
    string serialised;
    if(!root)
    return serialised;
    queue<node *>q;
    q.push(root);
    while(!q.empty())
    {
        node *curr=q.front();
        q.pop();
        serialised.push_back[to_string(curr->key)];


    }
}
